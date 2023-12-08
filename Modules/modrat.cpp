#include "modrat.h"

Rational red_q_q(Rational num){ //'r'
    num.reduce();
    return num;
}

bool int_q_b(Rational& num){ //'i'
    return num.isInt();
}

Rational trans_z_q(Integer& num){//'Q';
    return {num};
}

Integer trans_q_z(Rational& num){//'Z'
    if (!num.isInt())
        throw std::invalid_argument("Number is not integer");
    return num.getNumerator();
}

Rational add_qq_q(Rational& num1, Rational& num2){ //'+'
    return num1 + num2;
}

Rational sub_qq_q(Rational& num1, Rational& num2){ //'-'
    return num1 - num2;
}

Rational mul_qq_q(Rational& num1, Rational& num2){ //'*'
    return num1 * num2;
}

Rational div_qq_q(Rational& num1, Rational& num2){ //'/'
    return num1 / num2;
}

Rational pow_qn_q(const Rational& base, Natural exp){ //'^'
    Integer numerator = base.getNumerator();
    Natural denumerator = base.getDenominator();
    return Rational(pow_zn_z(numerator, exp), pow_nn_n(denumerator, exp));
}