#ifndef COLOQ_MY_TRY_MODRAT_H
#define COLOQ_MY_TRY_MODRAT_H
#include "../Algebras/Rational.h"

Rational red_q_q(Rational num);

bool int_q_b(Rational& num);

Rational trans_z_q(Integer& num);

Integer trans_q_z(Rational& num);

Rational add_qq_q(Rational& num1, Rational& num2);

Rational sub_qq_q(Rational& num1, Rational& num2);

Rational mul_qq_q(Rational& num1, Rational& num2);

Rational div_qq_q(Rational& num1, Rational& num2);

Rational pow_qn_q(Rational base, Natural exp);

#endif //COLOQ_MY_TRY_MODRAT_H
