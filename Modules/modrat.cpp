#include "modrat.h"

Rational red_q_q(Rational num){
    num.reduce();
    return num;
}

bool int_q_b(Rational& num){
    return num.isInt();
}

Rational trans_z_q(Integer& num){
    return {num};
}

Integer trans_q_z(Rational& num){
    if (!num.isInt())
        throw std::invalid_argument("Number is not integer");
    return num.getNumerator();
}

Rational add_qq_q(Rational& num1, Rational& num2){
    return num1 + num2;
}

Rational sub_qq_q(Rational& num1, Rational& num2){
    return num1 - num2;
}

Rational mul_qq_q(Rational& num1, Rational& num2){
    return num1 * num2;
}

Rational div_qq_q(Rational& num1, Rational& num2){
    return num1 * num2;
}

Rational pow_qn_q(Rational base, Natural exp){
    Rational res = 1;
    while (exp > 0){
        if (exp[0] % 2 == 1){
            res = res * base;
        }
        base = base * base;
        exp = exp / 2;
    }
    return res;
}