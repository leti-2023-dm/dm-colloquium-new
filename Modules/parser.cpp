#include <set>
#include <sstream>
#include "parser.h"
#include "modrat.h"

Parser::Parser() = default;


void Parser::validate(std::string str) {
    // Remove spaces from input string
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());

    std::set<char> approvedSymbols;
    approvedSymbols.insert(digits.begin(), digits.end());
    approvedSymbols.insert(operations.begin(), operations.end());
    approvedSymbols.insert(other.begin(), other.end());

    auto bracketCounter = (int8_t) isBracket(str[0]);
    for (size_t i = 1; i < str.size(); i++) {
        char prv = str[i - 1];
        char cur = str[i];

        if (approvedSymbols.find(cur) == approvedSymbols.end())
            throw std::invalid_argument("Invalid symbol on " + std::to_string(i) + " position");
        if (operations.find(cur) != operations.end() && operations.find(prv) != operations.end())
            throw std::invalid_argument("Two operations in a row on " + std::to_string(i) + " position");
//        if (other.find(cur) != other.end() && other.find(prv) != other.end())
//            throw std::invalid_argument("Invalid two symbols in a row on " + std::to_string(i) + " position");

        if (cur == '(') bracketCounter++;
        if (cur == ')') bracketCounter--;
        if (bracketCounter < 0) break;
    }

    if (bracketCounter != 0)
        throw std::invalid_argument("Invalid brackets");
}

AlgebraType Parser::getAlgebraType(const std::string &str) {
    try { validate(str); }
    catch (std::invalid_argument &e) { return UNDEFINED; }
    if (str.find('x') != std::string::npos) return POLYNOMIAL;
    if (str.find('.') != std::string::npos || str.find('/') != std::string::npos) return RATIONAL;
    if (str.find('-') != std::string::npos) return INTEGER;
    return NATURAL;
}

std::vector<std::string> Parser::parseExpression(std::string str) {
    std::vector<std::string> result;

    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());

    if (str.empty()) {
        result.emplace_back("0");
        return result;
    }

    int start = 0;
    for (int fin = 0; fin < str.size(); fin++) {
        char cur = str[fin];

        // Symbol is a number
        if (digits.find(cur) != digits.end() || cur == '.') continue;

        // if true: Number and operation, else: only operation
        if (start != fin) {
            result.push_back(str.substr(start, fin - start));
            result.push_back(std::string{cur});
            start = fin + 1;
        } else if (digits.find(cur) == digits.end()) {
            result.push_back(std::string{str[start]});
            start++;
        }
    }

    // Additional recording to vector
    if (start != str.size())
        result.push_back(str.substr(start));

    // Fold expression
    for (int i = 0; i < result.size(); i++) {
        // Collapse fractions
        if (result[i].find('/') != std::string::npos &&
            isdigit(result[i + 1][0]) &&
            result[i - 1].find('!') == std::string::npos &&
            result[i - 1].find('.') == std::string::npos &&
            result[i + 1].find('!') == std::string::npos &&
            result[i + 1].find('.') == std::string::npos) {

            result[i - 1] = result[i - 1] + "/" + result[i + 1];
            result.erase(result.begin() + i, result.begin() + i + 2);
        }

        // Move negative to number
        if (result[i] == "-" && digits.find(result[i + 1][0]) == digits.end()) {
            continue;
        } else if (result[i] == "-" && digits.find(result[i - 1][0]) != digits.end()) {
            result[i] = "+";
            result[i + 1] = "-" + result[i + 1];
        } else if (result[i] == "-") {
            result.erase(result.begin() + i);
            result[i] = "-" + result[i];
        }

        // Create decimal fraction
        if (int c = result[i].find('.') != std::string::npos) {
            std::string znam = "1";
            unsigned long d = result[i].size() - c - 1;
            for (int y = 0; y < d; y++) znam += "0";
            result[i].erase(c, 1);
            result[i] += "/" + znam;
        }
    }

    return result;
}

std::vector<std::string> Parser::RPN(const std::vector<std::string> &tokens) {
    std::vector<std::string> srpn;

    // Symbol weight map
    std::map<char, size_t> map;
    map.insert(std::make_pair('^', 4));
    map.insert(std::make_pair('*', 3));
    map.insert(std::make_pair('#', 3));
    map.insert(std::make_pair('/', 3));
    map.insert(std::make_pair('+', 2));
    map.insert(std::make_pair('-', 2));
    map.insert(std::make_pair('(', 1));


    // Create result string to RPN
    std::stack<std::string> stack;
    for (auto token: tokens) {
        if (!isalnum(token[0]) && !(token[0] == '-' && token.length() > 1)) {
            if (')' == token[0]) {
                while (stack.top()[0] != '(') {
                    std::string buf = stack.top();
                    srpn.push_back(buf);
                    stack.pop();
                }
                stack.pop();
            } else if ('(' == token[0]) {
                stack.push(token);
            } else if (token == "!") {
                srpn.push_back(token);
            } else if (stack.empty() || (map[stack.top()[0]] < map[token[0]])) {
                stack.push(token);
            } else {
                do {
                    srpn.push_back(stack.top());
                    stack.pop();
                } while (!(stack.empty() || (map[stack.top()[0]] < map[token[0]])));
                stack.push(token);
            }
        } else {
            if (token[token.size() - 1] == '!') {
                token.erase(token.find('!'));
                srpn.push_back(token);
                srpn.push_back("!");
            } else {
                srpn.push_back(token);
            }
        }
    }

    // Append remainder from stack to result string
    while (!stack.empty()) {
        srpn.push_back(stack.top());
        stack.pop();
    }

    return srpn;
}

uint16_t Parser::maxDeg(const std::vector<std::string> &str) {
    uint16_t res = 0;
    for (const auto &i: str)
        if (stoll(i) > res) res = stoll(i);

    return res;
}

std::string Parser::parse(const std::string &str) {
    validate(str);

    if (getAlgebraType(str) == POLYNOMIAL) {
        std::stringstream res;
        res << parsePolynomial(str);
        return res.str();
    }

    std::vector<std::string> parsed = parseExpression(str);
    std::vector<std::string> rpn = RPN(parsed);
    return executeRPN(rpn);
}

std::string Parser::executeRPN(std::vector<std::string> rpnExpression) {
    long int cursor = 0;
    while (rpnExpression.size() != 1) {
        auto value = rpnExpression[cursor];
        auto symbol = value[0];
        if ((value.size() != 1 || operations.find(symbol) == operations.end()) && symbol != '!') {
            cursor++;
            continue;
        }

        auto ARNY = symbol == '!' ? 1 : 2;
        if (cursor < ARNY) {
            cursor++;
            continue;
        }
        if (rpnExpression.size() <= ARNY)
            throw std::invalid_argument("Amount of operations greater than operands");

        // Get operands for this arity
        std::stringstream res;
        std::vector<std::string> operands;
        for (int i = 0; i < ARNY; ++i) operands.push_back(rpnExpression[cursor - ARNY + i]);
        rpnExpression.erase(rpnExpression.begin() + cursor - ARNY, rpnExpression.begin() + cursor);

        if (ARNY == 1) res << fact_n_n(*(new Natural(operands[0])));
        else res << executeBiOp(operands[0], operands[1], symbol);
        cursor -= ARNY;
        rpnExpression[cursor] = res.str();
    }

    if (rpnExpression.size() != 1)
        throw std::invalid_argument("Result is not the number");
    return rpnExpression[0];
}

bool Parser::isBracket(char symbol) {
    return symbol == '(' || symbol == ')';
}

std::string Parser::executeBiOp(std::string first, std::string second, char op) {
    std::set<char> baseOperations = {'*', '+', '-', '/'};
    std::stringstream result;
    if (baseOperations.find(op) != baseOperations.end()) {
        switch (std::max(getAlgebraType(first), getAlgebraType(second))) {
            case NATURAL:
                result << executeBinary(Natural(first), Natural(second), op);
                break;
            case INTEGER:
                result << executeBinary(Integer(first), Integer(second), op);
                break;
            case RATIONAL:
                result << executeBinary(Rational(first), Rational(second), op);
                break;
            default:
                throw std::invalid_argument("Argument should be a number");
        }
        return result.str();
    }

    switch (op) {
        case '%':
            result << Integer(first) % Integer(second);
            break;
        case '^':
            result << pow_qn_q(Rational(first), Natural(second));
            break;
        default:
            throw std::invalid_argument("Undefined operand");
    }

    return result.str();
}

Polynomial Parser::parsePolynomial(std::string str) {
    auto firstPos = str.find('(');
    if (firstPos == std::string::npos) return Polynomial(str);

    std::vector<int> bracketPos;
    auto bracketCount = 0;
    for (int i = firstPos; i < str.length(); ++i) {
        if (str[i] == '(') {
            if (bracketCount == 0) bracketPos.push_back(i);
            bracketCount++;
        }
        if (str[i] == ')') {
            if (bracketCount == 1) bracketPos.push_back(i);
            bracketCount--;
        }
        if (bracketCount < 0) break;
    }
    if (bracketCount != 0) throw std::invalid_argument("Invalid brackets");

    std::stack<std::string> algebras;
    std::stack<char> polyOps;
    for (int i = 0; i < bracketPos.size(); i++) {
        auto temp = std::string(str.substr(bracketPos[i] + 1, bracketPos[i + 1] - bracketPos[i] - 1));
        if (temp.empty()) continue;
        if (operations.find(temp[0]) != operations.end() && temp.length() == 1) polyOps.push(temp[0]);
        else algebras.push(temp);
    }

    while (algebras.size() > 1) {
        if (polyOps.empty())
            throw std::invalid_argument("Invalid operands input");

        std::string val2 = algebras.top();
        auto type2 = getAlgebraType(val2);
        algebras.pop();
        std::string val1 = algebras.top();
        auto type1 = getAlgebraType(val1);
        algebras.pop();
        char op = polyOps.top();
        polyOps.pop();

        std::stringstream res;
        if (type1 == POLYNOMIAL && type2 == POLYNOMIAL)
            res << executeBinary(Polynomial(val1), Polynomial(val2), op);
        else if (type1 == POLYNOMIAL && type2 >= NATURAL) {
            res << executeBinary(Polynomial(val1), Rational(parse(val2)), op);
        }

        auto resultStr = res.str();
        resultStr.erase(std::remove_if(resultStr.begin(), resultStr.end(), ::isspace), resultStr.end());
        algebras.push(resultStr);
    }

    return Polynomial(algebras.top());
}

