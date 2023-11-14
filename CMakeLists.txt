cmake_minimum_required(VERSION 3.26.4)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

find_package(cpprestsdk REQUIRED)
find_package(OpenSSL 3.0.0 REQUIRED)

find_package(GTest REQUIRED)

# Список исходных файлов
set(SOURCES
        Algebras/Natural.h
        Algebras/Integer.h
        Algebras/Rational.h
        Algebras/Polynomial.h
        Algebras/Natural.cpp
        Algebras/Integer.cpp
        Algebras/Rational.cpp
        Algebras/Polynomial.cpp
        Modules/modnat.h
        Modules/modint.h
        Modules/modrat.h
        Modules/modpoly.h
        Modules/modnat.cpp
        Modules/modint.cpp
        Modules/modrat.cpp
        Modules/modpoly.cpp
)

# main program
add_executable(program main.cpp ${SOURCES})

target_link_libraries(program PRIVATE cpprestsdk::cpprest)
target_include_directories(program PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(program PRIVATE ${OPENSSL_LIBRARIES} OpenSSL::SSL OpenSSL::Crypto)

# test part
add_executable(test_program Tests/test_modint.cpp ${SOURCES})
target_link_libraries(test_program PRIVATE gtest gtest_main pthread)
