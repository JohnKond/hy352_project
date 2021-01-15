#include "JSONlang.h"

PROGRAM_BEGIN


    JSON(var) = NUMBER(23)JSON(name) = STRING("hello")JSON(x) = FALSE
            JSON(var2) = NUMBER(2)
    JSON(kon) = TRUE
            JSON(lamp) = FALSE
    JSON(krap) = kon && !lamp



    PRINT name PRINT var PRINT x JSON(obj) = OBJECT{}JSON(book) = OBJECT{
            KEY(title) : STRING("Gone Girl"),
            KEY(fok) : kon && lamp,
            KEY(published) : NUMBER(2013),
            KEY(movie_type) : STRING("Thriller"),
            KEY(author) : OBJECT{
                    KEY(firstname) : STRING("GILLIAN"),
                    KEY(surname) : STRING("FLYNN"),
                    KEY(age) : NUMBER(45),
            }
    }PRINT book
            PRINT HAS_KEY(book,"fak")
            PRINT SIZE_OF(book)
            JSON(week_temperatures) = ARRAY[
                    NUMBER(20), NUMBER(19.5), NUMBER(19), NUMBER(20),
                    NUMBER(19), NUMBER(18.5), NUMBER(19)]PRINT week_temperatures JSON(students) = ARRAY[
                    OBJECT{
                            KEY(name) : STRING("Nikos Nikolaou"),
                            KEY(id) : NUMBER(4444),
                            KEY(grades) : ARRAY[
                                            OBJECT{
                                                    KEY(hy100) : NUMBER(7.5)
                                            },
                                            OBJECT{
                                                    KEY(hy150) : NUMBER(8)
                                            }
                            ]
                    },
                    OBJECT{
                            KEY(name) : STRING("Ioannis Tsiakkas"),
                            KEY(csd) : NUMBER(3213),
                            KEY(grades) : ARRAY[
                                            OBJECT{
                                                    KEY(hy225) : NUMBER(8)
                                            },
                                            OBJECT{
                                                    KEY(hy352) : NUMBER(10)
                                            }
                            ]
                    }
    ]PRINT students

            SET week_temperatures[2] ASSIGN NUMBER(22)
            PRINT week_temperatures


            JSON(fok) = NUMBER(23) - NUMBER(2)*NUMBER(2)
                    PRINT fok

                    JSON(str) = STRING("KO") + STRING("NDO")
                            PRINT str

//            SET foods[1] ASSIGN STRING("fokia")
//            PRINT foods



            PROGRAM_END