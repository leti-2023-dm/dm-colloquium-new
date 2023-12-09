#ifndef INP_PARSER_H
#define INP_PARSER_H

#include <iostream>
#include <stack>
#include <cctype>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include "../Algebras/Natural.h"
#include "../Algebras/Rational.h"
#include "../Algebras/Integer.h"
#include "../Algebras/Polynomial.h"

enum AlgebraType {
    UNDEFINED,
    NATURAL,
    INTEGER,
    RATIONAL,
    POLYNOMIAL
};

class Parser {
private:
    std::set<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::set<char> operations = {'*', '+', '-', '/', '^', '%'};
    std::set<char> other = {'.', 'x', '(', ')', '!'};

public:
    Parser();

    // Validate string an expression
    void validate(std::string str);

    // Define algebra type from str
    AlgebraType getAlgebraType(const std::string &str);

    // Check if symbol is round bracket
    static bool isBracket(char symbol);

    // Create token vector with numbers and binary operations from numeric expression
    std::vector<std::string> parseExpression(std::string str);

    // Returns string expression as vector in Reverse Polish Notation
    std::vector<std::string> RPN(const std::vector<std::string>& tokens);

    // Execute all operations from RPN vector
    std::string executeRPN(std::vector<std::string> rpnExpression);

    // Create polynomial with numbers and binary operations
    Polynomial parsePolynomial(std::string str);

    // Return max ll value from string
    static uint16_t maxDeg(const std::vector<std::string> &str);

    // Execute approved binary operations
    std::string executeBiOp(std::string first, std::string second, char op);

    // Execute common binary operations
    template<typename T, typename U>
    T executeBinary(T first, U second, char op) {
        switch (op) {
            case '+':
                return first + second;
            case '-':
                return first - second;
            case '*':
                return first * second;
            case '/':
                return first / second;
            default:
                throw std::invalid_argument("Undefined operand");
        }
    }

    // Main pipeline
    std::string parse(const std::string &str);
};


#endif //INP_PARSER_H
