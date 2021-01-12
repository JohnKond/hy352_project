#include "JSONlang.h"

PROGRAM_BEGIN


    JSON(var) = NUMBER(23)JSON(name) = STRING("hello")JSON(x) = FALSE

    PRINT name PRINT var PRINT x JSON(obj) = OBJECT{}JSON(book) = OBJECT{
            KEY(title) : STRING("Gone Girl"),
            KEY(published) : NUMBER(2013),
            KEY(movie_type) : STRING("Thriller"),
            KEY(author) : OBJECT{
                    KEY(firstname) : STRING("GILLIAN"),
                    KEY(surname) : STRING("FLYNN"),
                    KEY(age) : NUMBER(45),
            }
    }PRINT book JSON(week_temperatures) = ARRAY[
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
    ]PRINT students PROGRAM_END