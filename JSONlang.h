#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#define PROGRAM_BEGIN int main() { string tmp; 
#define PROGRAM_END ;return 0;}


#define JSON(var) ;type var
#define KEY(name) type(tmp = #name) = 0 ? 0
#define STRING(name) type(tmp = name)
#define NUMBER(name) type(name)
#define ARRAY type("fok")
#define OBJECT *new type


// #define SIZE_OF(json) json.SIZE_OF_ME()
// #define IS_EMPTY(json) json.IS_EMPTY_ME()
// #define HAS_KEY(json,key) json.HAS_KEY_ME(key)
#define TYPE_OF(json) json.TYPE_OF_ME()


#define PRINT ;cout << 

#define TRUE type(true);
#define FALSE type(false);

using namespace std;



class type{
public:


    friend ostream &operator<<(ostream &os, type &var){
    

        if (var.typeno == 1){
            cout << var.get_name() << " : " << var.get_string() << endl;
        }else if (var.typeno == 2 ){
            cout << var.get_name() << " : " << var.get_number() << endl;
        }else if (var.typeno == 3){
            cout << var.get_name()<< " : " << var.get_boolean() << endl;
        }else if(var.typeno == 5){
            cout << "[";
            for(int i = 0; i < var.get_array().size() ; i++){
                cout << var.get_array()[i] ;
                if (i < var.get_array().size()-1)
                cout << ", ";
            }
            cout << "]" << endl;
        }else if (var.typeno == 4){ 

            if(var.get_name() != ""){
                cout << var.get_name() << ": { \n";
            }   
            for(int i = 0; i < var.data.size(); i++){
               cout <<var.data[i] ;
            }

            if(var.get_name() != ""){
                cout << "}" << endl;
            }
        }

    
        return os;
    }


    friend ostream &operator<<(ostream &os, type *var){
        if (var->typeno == 1){
            cout << var->get_name() << " : " << var->get_string() << endl;
        }else if (var->typeno == 2 ){
            cout << var->get_name() << " : " << var->get_number() << endl;
        }else if (var->typeno == 3){
            cout << var->get_name()<< " : " << var->get_boolean() << endl;
        }else if(var->typeno == 5){
            cout << "[";
            for(int i = 0; i < var->get_array().size() ; i++){
                cout << var->get_array()[i] ;
                if (i < var->get_array().size()-1)
                cout << ", ";
            }
            cout << "]" << endl;
        }else if (var->typeno == 4){ 

            if(var->get_name() != ""){
                cout << var->get_name() << ": { \n";
            }   
            for(int i = 0; i < var->data.size(); i++){
               cout <<var->data[i] ;
            }

            if(var->get_name() != ""){
                cout << "}" << endl;
            }
        }

    
        return os;
    }




/* -----------------------------CONSTRUCTORS------------------------- */

    // constructor for list
    type(initializer_list<type> Head){
        vector<type>::iterator head_iterator;
        head_iterator = this->data.begin();
        head_iterator = this->data.insert ( head_iterator , Head );
        this->set_type(4);
    };

    //constructor for empty
    type(){
        set_type(8);
    };

    //constructor for integer
    type(const int x) {
        number = x;
        set_type(2);
    };


    type(const double x) {
        number = x;
        set_type(2);
    };



    //constructor for string
    type(const string &str) {
        name = str;
        set_type(1);
    };

    //constructor for boolean
    type(const bool Boolean) {
        boolean = Boolean;
        set_type(3);
    };

/* -------------------------------------------------------------------- */

 

    type &operator=(type value) {
        // cout << "= operator";
        this->set_type(value.typeno);
        
        if (value.typeno == 1){
            this->set_string(value.name);
        }
        else if (value.typeno == 2 ){
            this->set_number(value.number);
        }
        else if (value.typeno == 3){
            this->set_bool(value.boolean);
        }
        else if ( value.typeno == 4){
            this->data.push_back(value);
        }else if (value.typeno == 5){
            for(int i = 0; i < value.get_array().size() ; i++){
                this->arr.push_back(value.get_array()[i]);
            }
        }

        return *this;
    };

     
    type &operator=(type *value) {
        this->set_type(value->typeno);
        
        if (value->typeno == 1){
            this->set_string(value->name);
        }
        else if (value->typeno == 2 ){
            cout << "number";
            this->set_number(value->number);
        }
        else if (value->typeno == 3){
            cout << "boolean";
            this->set_bool(value->boolean);
        }

        else if (value->typeno == 4 ){
            this->data.push_back(value);
        }else if (value->typeno == 5){
            for(int i = 0; i < value->get_array().size() ; i++){
                this->arr.push_back(value->get_array()[i]);
            }
        }
        return *this;
    };


    type operator[](type *Head){return Head;};
    type operator[](type Head){return Head;};




    type &operator,(type var){
        if (var.typeno == 2 && var.name == ""){
            
            if (arr_empty() == "TRUE"){
                this->arr.push_back(get_number());
            }

            arr.push_back(var.get_number());
            this->set_type(5);
        }else if (get_name() != ""){
            this->clear();
            this->set_type(4);
            // this->data.push_back(*this);
            this->data.push_back(var);
        }else if (this->get_name() == "" && var.get_name() == ""){
            this->clear();
            this->set_type(4);
            // this->data.push_back(*this);
            this->data.push_back(var);
        }else{
            arr.push_back(var.get_number());
            this->set_type(5);
        }
        return *this;
    }


    type &operator,(type *var){
        if (var->typeno == 2){
            
            if (this->arr_empty() == "TRUE"){
                arr.push_back(get_number());
            }

            arr.push_back(var->get_number());
            this->set_type(5);
        }else if (get_name() != ""){
            this->clear();
            this->set_type(4);
            // this->data.push_back(*this);
            this->data.push_back(var);
        }else{
            arr.push_back(var->get_number());
            this->set_type(5);
        }
        return *this;
    }







    //setters
    void set_type(int type){
        this->typeno = type;
    }
    void set_name(string const str){
        this->name = str;
    }
    void set_string(string const str){
        this->str =str;
    }
    void set_number(float const number){
        this->number = number;
    }
    void set_bool(bool const boolean){
        this->boolean = boolean;
    }
    void set_array(vector<float> array){
        arr = array;
    }
    //add to list data
    // void push_data(type data){
        // this->data.push_back(data);
    // }


    // getters
    string get_name(){
        return(this->name);
    }
    string get_string(){
        return(this->str);
    }
    float get_number(){
        return(this->number);
    }
    string get_boolean(){
        if (this->boolean == 1) return "TRUE";
        return "FALSE";
    }
    int get_type(){
        return this->typeno;
    }
    // int getMEMBER(){
        // return this->isMember;
    // }
    vector<float> get_array(){
        return this->arr;
    }
    vector<type> get_data(){
        return this->data;
    }
    
    string arr_empty(){
        if (get_array().size() == 0) return "TRUE";
        return "FALSE";
    }

    /*
    Types_Numbers
    --------------
    1->String
    2->Int
    3->Boolean
    4->Object
    6->Array
    */



   void clear(){

        this->set_name("");
        this->set_string("");
        this->set_number(99);
        this->set_bool(false);
        this->data.clear();
        // this->clearARRAY();
        this->set_type(99);

        // isMember = false;
        // hidden = false;
        // edited = false;
        // willgeterased = false;
        // deleteMe = true;

    }



    string TYPE_OF_ME(){
        if(this->typeno == 1){
            return "String";
        }else if(this->typeno == 2){
            return "Number";
        }else if(this->typeno == 3){
            return "Boolean";
        }else if(this->typeno == 5){
            return "Array";
        }else if(this->typeno == 4 ){ //|| this->typeno == 7){
            return "Object";
        }else{
            return "NULL";
        }

    }

   

private:

    int typeno = 999;
    vector<type> data;
    vector<float> arr;
    


    bool boolean;
    bool isMeme = 1;
    string name = "";
    string str;
    float number;

};