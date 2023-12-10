
#include <iostream>
#include "Algebras/Polynomial.h"
#include "Algebras/Rational.h"
#include "Modules/modint.h"
#include "Modules/modpoly.h"
#include "Modules/parser.h"
#include <iostream>
#include <string>
#include "Web/backend.cpp"


int main() {
    Parser p;
    std::cout << p.parse("()") << std::endl;
    std::cout << p.parse("1 + (42 - 41) * 1 ") << std::endl;
    std::cout << p.parse("3.0 + 4! * 2 / (1 - 5)^2") << std::endl;
    std::cout << p.parse("40 - (100 - 99) * 1 ") << std::endl;
    std::cout << p.parse("-1") << std::endl;
    std::cout << p.parse("(-1)") << std::endl;
    std::cout << p.parse("34^2*14/(7+7!)") << std::endl;
    std::cout << p.parse("2^5") << std::endl;
    std::cout << p.parse("2^50") << std::endl;
    std::cout << p.parse("2^500") << std::endl;
    std::cout << p.parse("38.5^2*14/(7+7!)") << std::endl;
    std::cout << p.parse("31*28^2-112") << std::endl;
    std::cout << p.parse("12.5^2") << std::endl;
    std::cout << p.parse("5!+2") << std::endl;
    std::cout << p.parse("5!-2") << std::endl;
    try { p.parse("(-2)!"); }
    catch (std::exception &e) { std::cerr << e.what() << std::endl; }
    try { p.parse("12.5^(-2)"); }
    catch (std::exception &e) { std::cerr << e.what() << std::endl; }


    return 0;
}

// Polynomial input
int main1() {

    std::cout << Polynomial("x^2+2") << std::endl;
    std::cout << Polynomial("x^2+x+2") << std::endl;
    std::cout << Polynomial("x^2") << std::endl;
    Parser p;
    std::cout << p.parse("(x^2+2)*(24)") << std::endl;
    std::cout << p.parse("(x^2+2)*(24x)") << std::endl;
    std::cout << p.parse("(x^2+2)*(24^2)") << std::endl;

    return 0;
}


int main2() {
    http_server server;
    server.start();

    std::string line;
    std::getline(std::cin, line);
    return 0;
}
