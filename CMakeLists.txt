cmake_minimum_required(VERSION 3.26.4)
project(coloq_dm)

set(CMAKE_CXX_STANDARD 17)

add_executable(

        main.cpp
        Algebras/Natural.cpp
        program
        Algebras/Natural.h
        Algebras/Integer.h
        Algebras/Polynomial.h
        Modules/modnat.cpp
        Algebras/Natural.cpp
        Algebras/Integer.cpp
        Algebras/Rational.cpp
        Algebras/Polynomial.cpp
        Algebras/Polynomial.h
        Modules/modnat.h
        main.cpp
        Modules/modint.cpp
        Modules/modint.h
        Modules/modrat.cpp
        Modules/modrat.h
        Modules/modpoly.cpp
        Modules/modpoly.h
        "parsing/parser.h"]]
)
