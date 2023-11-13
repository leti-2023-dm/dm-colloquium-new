//
// Created by super on 12.11.2023.
//

#ifndef COLOQ_MY_TRY_MODNAT_H
#define COLOQ_MY_TRY_MODNAT_H

#include "../Algebras/Natural.h"

int com_nn_d(Natural& first, Natural& second);

bool nzer_n_b(Natural& num);

Natural add_1n_n(Natural& num);

Natural add_nn_n(Natural& first, Natural& second);

Natural sub_nn_n(Natural& first, Natural& second);

Natural mul_nd_n(Natural& num, int digit);

Natural mul_nk_n(Natural& num, size_t k);

Natural mul_nn_n(Natural& num1, Natural& num2);

Natural sub_ndn_n(Natural& num1, Natural& num2, int digit);

Natural div_nn_dk(Natural& num1, Natural& num2);

Natural div_nn_n(Natural& num1, Natural& num2);

Natural mod_nn_n(Natural& num1, Natural& num2);

Natural gcf_nn_n(const Natural& num1, const Natural& num2);

Natural lcm_nn_n(const Natural& num1, const Natural& num2);

Natural fact_n_n(Natural& num);

Natural sqr_n_n(Natural& num);

Natural pow_nn_n(Natural base, Natural exp);

Natural sqrt_n_q(Natural& num);

#endif //COLOQ_MY_TRY_MODNAT_H
