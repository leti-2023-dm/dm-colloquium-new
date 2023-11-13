#ifndef COLOQ_MY_TRY_MODINT_H
#define COLOQ_MY_TRY_MODINT_H
#include "../Algebras/Integer.h"

Natural abs_z_n(Integer& num);

int poz_z_d(Integer& num);

Integer mul_zm_z(Integer& num);

Integer trans_n_z(Natural& num);

Natural trans_z_n(Integer& num);

Integer add_zz_z(Integer& num1, Integer& num2);

Integer sub_zz_z(Integer& num1, Integer& num2);

Integer mul_zz_z(Integer& num1, Integer& num2);

Integer div_zz_z(Integer& num1, Integer& num2);

Integer mod_zz_z(Integer& num1, Integer& num2);

Integer pow_zn_z(Integer& num1, Natural exp);
#endif //COLOQ_MY_TRY_MODINT_H
