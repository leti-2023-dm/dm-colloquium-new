#include <iostream>
#include "Algebras/Polynomial.h"
#include "Algebras/Rational.h"
#include "Modules/modint.h"
#include "Modules/modpoly.h"
#include "Modules/parser.h"


int mainExmpl() {
    Parser p;
    //Tests rpn
    p.parse("()");
    p.parse("1 + (42 - 41) * 1 ");
    p.parse("3.0 + 4! * 2 / (1 - 5)^2");
    p.parse("40 - (100 - 99) * 1 ");
    p.parse("(-1)");
    p.parse("34^2*14/(7+7!)");
    p.parse("34.0^2*14/(7+7!)"); //WTF
    p.parse("2^5");
    p.parse("2^50");
    p.parse("2^500");
    p.parse("31*28^22-112"); // WTF
    p.parse("12.5^2"); // WTF

    return 0;
}

#include <iostream>
#include <string>

// Polynomial input
int main1() {
    Parser p;
    std::cout << p.parse("(x^2+2)*(24)") << std::endl;
    std::cout << p.parse("(x^2+2)*(24x)") << std::endl;
    std::cout << p.parse("(x^2+2)*(24^2)") << std::endl;

    return 0;
}

#include "Web/backend.cpp"

int main() {
    http_server server;
    server.start();

    std::string line;
    std::getline(std::cin, line);
    return 0;
}

int main4() {
    std::cout << Polynomial("x^2+2") << std::endl;
    std::cout << Polynomial("x^2+x+2") << std::endl;
    std::cout << Polynomial("x^2") << std::endl;
}