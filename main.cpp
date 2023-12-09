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
