#include <iostream>
#include "Algebras/Natural.h"

int main() {
    Natural a = 256, b = 16, c;
    c = a % b;
    std::cout << a << " " << b << " " << c ;
    return 0;
}
