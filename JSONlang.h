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
#define SET ;
#define ASSIGN *=



// #define SIZE_OF(json) json.SIZE_OF_ME()
// #define IS_EMPTY(json) json.IS_EMPTY_ME()
// #define HAS_KEY(json,key) json.HAS_KEY_ME(key)
#define TYPE_OF(json) json.TYPE_OF_ME()


#define PRINT ;cout <<

#define TRUE type(true);
#define FALSE type(false);

using namespace std;

enum varType{arithmos, grammata,antikeimeno,pinakas,adeio,boolis,akyro };


class type {
private:

    vector<type> data;
    vector<float> arr;
    varType ttype;


    bool boolean;
    bool isMeme = 1;
    bool hidden;
    string name = "";
    string str;
    float number;
public:
    friend ostream &operator<<(ostream &os, type &var) {

// Print overload functions
        if (var.ttype == grammata) {
            cout << var.get_name() << " : " << var.get_string() << endl;
        } else if (var.ttype == arithmos) {
            cout << var.get_name() << " : " << var.get_number() << endl;
        } else if (var.ttype == boolis) {
            cout << var.get_name() << " : " << var.get_boolean() << endl;
        } else if (var.ttype == pinakas) {
            cout << "[";
            for (int i = 0; i < var.get_array().size(); i++) {
                cout << var.get_array()[i];
                if (i < var.get_array().size() - 1)
                    cout << ", ";
            }
            cout << "]" << endl;
        } else if (var.ttype == antikeimeno) {

            if (var.get_name() != "") {
                cout << var.get_name() << ": { \n";
            }
            for (int i = 0; i < var.data.size(); i++) {
                cout << var.data[i];
            }

            if (var.get_name() != "") {
                cout << "}" << endl;
            }
        }


        return os;
    }


    friend ostream &operator<<(ostream &os, type *var) {
        if (var->ttype == grammata) {
            cout << var->get_name() << " : " << var->get_string() << endl;
        } else if (var->ttype == arithmos) {
            cout << var->get_name() << " : " << var->get_number() << endl;
        } else if (var->ttype == boolis) {
            cout << var->get_name() << " : " << var->get_boolean() << endl;
        } else if (var->ttype == pinakas) {
            cout << "[";
            for (int i = 0; i < var->get_array().size(); i++) {
                cout << var->get_array()[i];
                if (i < var->get_array().size() - 1)
                    cout << ", ";
            }
            cout << "]" << endl;
        } else if (var->ttype == antikeimeno) {

            if (var->get_name() != "") {
                cout << var->get_name() << ": { \n";
            }
            for (int i = 0; i < var->data.size(); i++) {
                cout << var->data[i];
            }

            if (var->get_name() != "") {
                cout << "}" << endl;
            }
        }


        return os;
    }




/* -----------------------------CONSTRUCTORS------------------------- */

    // constructor for list
    type(initializer_list<type> Head) {
        vector<type>::iterator head_iterator;
        head_iterator = this->data.begin();
        head_iterator = this->data.insert(head_iterator, Head);
        this->set_type(antikeimeno);
    };

    //constructor for empty
    type() {
        set_type(adeio);
    };

    //constructor for integer
    type(const int x) {
        number = x;
        set_type(arithmos);
    };


    type(const double x) {
        number = x;
        set_type(arithmos);
    };


    //constructor for string
    type(const string &str) {
        name = str;
        set_type(grammata);
    };

    //constructor for boolean
    type(const bool Boolean) {
        boolean = Boolean;
        set_type(boolis);
    };

/* -------------------------------------------------------------------- */


// = overload functions
    type &operator=(type value) {
        // cout << "= operator";
        this->set_type(value.ttype);

        if (value.ttype == grammata) {
            this->set_string(value.name);
        } else if (value.ttype == arithmos) {
            this->set_number(value.number);
        } else if (value.ttype == boolis) {
            this->set_bool(value.boolean);
        } else if (value.ttype == antikeimeno) {
            this->data.push_back(value);
        } else if (value.ttype == pinakas) {
            for (int i = 0; i < value.get_array().size(); i++) {
                this->arr.push_back(value.get_array()[i]);
            }
        }

        return *this;
    };


    type &operator=(type *value) {
        this->set_type(value->ttype);

        if (value->ttype == grammata) {
            this->set_string(value->name);
        } else if (value->ttype == arithmos) {
            cout << "number";
            this->set_number(value->number);
        } else if (value->ttype == boolis) {
            cout << "boolean";
            this->set_bool(value->boolean);
        } else if (value->ttype == antikeimeno) {
            this->data.push_back(value);
        } else if (value->ttype == pinakas) {
            for (int i = 0; i < value->get_array().size(); i++) {
                this->arr.push_back(value->get_array()[i]);
            }
        }
        return *this;
    };


    type operator[](type *Head) { return Head; };

    type operator[](type Head) { return Head; };

// , (array) overload functions
    type &operator,(type var) {
        if (var.ttype == arithmos && var.name == "") {

            if (arr_empty() == "TRUE") {
                this->arr.push_back(get_number());
            }

            arr.push_back(var.get_number());
            this->set_type(pinakas);
        } else if (get_name() != "") {
            type overload = *this;
            this->clear();
            this->set_type(antikeimeno);
            this->data.push_back(overload);
            this->data.push_back(var);
        } else if (this->get_name() == "" && var.get_name() == "") {
            type overload = *this;
            this->clear();
            this->set_type(antikeimeno);
            this->data.push_back(overload);
            this->data.push_back(var);
        } else {
            arr.push_back(var.get_number());
            this->set_type(pinakas);
        }
        return *this;
    }


    type &operator,(type *var) {
        if (var->ttype == arithmos) {

            if (this->arr_empty() == "TRUE") {
                arr.push_back(get_number());
            }

            arr.push_back(var->get_number());
            this->set_type(pinakas);
        } else if (get_name() != "") {
            type overload = *this;
            this->clear();
            this->set_type(antikeimeno);
            this->data.push_back(overload);
            this->data.push_back(var);
        } else {
            arr.push_back(var->get_number());
            this->set_type(pinakas);
        }
        return *this;
    }


    //...


    type &operator[](int num){

        if (this->arr_empty() == "FALSE"){
            if (this->arr.size() > num){
                this->arr[num] = 999;
            }
        }else{
            type NEW;
            NEW.hidden = true;

            if (num == 0){
                data.push_back(NEW);
            }else{
                data[num].data.push_back(NEW);
            }
        }

        return *this;
    }

    type &operator[](char *name){

        return *this;
    }


    type &operator*=(type var) {

        if (get_type() == pinakas) {
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] == 999) {
                    arr[i] = var.get_number();
                    return *this;
                }
            }
        }
        return *this;
    }





    // arithmetic overload functions

    type &operator+(type *var) {
        //... malakies tou typou

        type first = this;

        if (this->get_type() == grammata && var->get_type() == grammata) {
            this->set_string(first.get_name() + var->get_name());
        } else if (this->get_type() == arithmos && var->get_type() == arithmos) {
            this->set_number(first.get_number() + var->get_number());
        } else if (this->get_type() == antikeimeno && var->get_type() == antikeimeno){
            for (int i=0; i< var->data.size(); i++){
                this->data.push_back(var->data[i]);
            }
        } else if (this->get_type() == pinakas && var->get_type() == pinakas){
            for (int i=0; i< var->arr.size(); i++){
                this->arr.push_back(var->arr[i]);
            }
        }
    }

    type &operator+(type var) {
        //... malakies tou typou

        type first = *this;

        if (this->get_type() == grammata && var.get_type() == grammata) {
            this->set_string(this->get_name() + var.get_name());
        } else if (this->get_type() == arithmos && var.get_type() == arithmos) {
            this->set_number(this->get_number() + var.get_number());
        } else if (this->get_type() == antikeimeno && var.get_type() == antikeimeno){
            for (int i=0; i< var.data.size(); i++){
                this->data.push_back(var.data[i]);
            }
        } else if (this->get_type() == pinakas && var.get_type() == pinakas){
            for (int i=0; i< var.arr.size(); i++){
                this->arr.push_back(var.arr[i]);
            }

        }

        return *this;
    }


    type &operator-(type var) {
        if (this->get_type() == arithmos && var.get_type() == arithmos) {
            this->set_number(this->get_number() - var.get_number());
        }
        return *this;
    }

    type &operator*(type var) {
        if (this->get_type() == arithmos && var.get_type() == arithmos) {
            this->set_number(this->get_number() * var.get_number());
        }
        return *this;
    }

    type &operator/(type var) {
        if (this->get_type() == arithmos && var.get_type() == arithmos) {
            this->set_number(this->get_number() - var.get_number());
        }
        return *this;
    }

    type &operator%(type var) {
        if (this->get_type() == arithmos && var.get_type() == arithmos) {
            this->set_number(this->get_number() - var.get_number());
        }
        return *this;
    }



    //Logical operators
    type operator&&(type *var){
        if (this->get_type() == boolis && var->get_type() == boolis){
            if (this->get_boolean()=="TRUE" && var->get_boolean()=="TRUE")
                return true;
            return false;
        }
    }

    type operator||(type *var){
        if (this->get_type() == boolis && var->get_type() == boolis){
            if (this->get_boolean()=="FALSE" && var->get_boolean()=="FALSE")
                return false;
            return true;
        }
    }

    type operator!(){
        if (this->get_type() == boolis) {
            if (this->get_boolean() == "TRUE") return false;
            return true;
        }
        return false;
    }

    // Equality operators
    const bool &operator==(type *var){
        if(this->get_type() == grammata && var->get_type() == grammata){
            if (this->get_name() == var->get_name()) return true;
            else false;
        }else if (this->get_type() == arithmos && var->get_type() == arithmos) {
            if (this->get_number() == var->get_number()) return true;
            return false;
        }else if (this->get_type() == boolis && var->get_type() == boolis){
            if (this->get_boolean() == var->get_boolean()) return true;
            return false;
        }else if (this->get_type() == antikeimeno && var->get_type() == antikeimeno){
            if (this->data.size() != var->data.size()) return false;

            // TODO

        }else if (){

            //TODO

        }
    }




    //setters
    void set_type(varType type) {
        this->ttype = type;
    }

    void set_name(string const str) {
        this->name = str;
    }

    void set_string(string const str) {
        this->str = str;
    }

    void set_number(float const number) {
        this->number = number;
    }

    void set_bool(bool const boolean) {
        this->boolean = boolean;
    }

    void set_array(vector<float> array) {
        arr = array;
    }
    //add to list data
    // void push_data(type data){
    // this->data.push_back(data);
    // }


    // getters
    string get_name() {
        return (this->name);
    }

    string get_string() {
        return (this->str);
    }

    float get_number() {
        return (this->number);
    }

    string get_boolean() {
        if (this->boolean == 1) return "TRUE";
        return "FALSE";
    }

    int get_type() {
        return this->ttype;
    }

    // int getMEMBER(){
    // return this->isMember;
    // }
    vector<float> get_array() {
        return this->arr;
    }

    vector<type> get_data() {
        return this->data;
    }

    string arr_empty() {
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
    5->Array
    */



    void clear() {

        this->set_name("");
        this->set_string("");
        this->set_number(999);
        this->set_bool(false);
        this->data.clear();
        this->arr.clear();
        // this->clearARRAY();
        // this->set_type(999);

        // isMember = false;
        // hidden = false;
        // edited = false;
        // willgeterased = false;
        // deleteMe = true;

    }


    string TYPE_OF_ME() {
        if (this->ttype == grammata) {
            return "String";
        } else if (this->ttype == arithmos) {
            return "Number";
        } else if (this->ttype == boolis) {
            return "Boolean";
        } else if (this->ttype == pinakas) {
            return "Array";
        } else if (this->ttype == antikeimeno) { //|| this->ttype == 7){
            return "Object";
        } else {
            return "NULL";
        }

    }




};