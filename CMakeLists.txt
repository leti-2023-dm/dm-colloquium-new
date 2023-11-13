cmake_minimum_required(VERSION 3.26.4)
project(coloq_my_try)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp
        Algebras/Natural.cpp
        Algebras/Natural.h
        Modules/modnat.cpp
        Modules/modnat.h
        Algebras/Integer.h
        Algebras/Integer.cpp
        Algebras/Rational.cpp
)
