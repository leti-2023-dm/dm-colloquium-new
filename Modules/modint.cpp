#include "modint.h"

Natural abs_z_n(Integer& num){
    return num.abs();
}

int poz_z_d(Integer& num){
    return num > 0? 2: num != 0;
}

Integer mul_zm_z(Integer& num){
    return -num;
}

Integer trans_n_z(Natural& num){
    return Integer(num);
}

Natural trans_z_n(Integer& num){
    if (num < 0)
        throw std::invalid_argument("Number is not natural");
    return num.abs();
}

Integer add_zz_z(Integer& num1, Integer& num2){
    return num1 + num2;
}

Integer sub_zz_z(Integer& num1, Integer& num2){
    return num1 - num2;
}

Integer mul_zz_z(Integer& num1, Integer& num2){
    return num1 * num2;
}

Integer div_zz_z(Integer& num1, Integer& num2){
    return num1 * num2;
}

Integer mod_zz_z(Integer& num1, Integer& num2){
    return num1 % num2;
}

Integer pow_zn_z(Integer& num1, Natural exp){
    return Integer(pow_nn_n(num1.abs(), exp), (exp[0] % 2) * (!num1.isPositive()));
}