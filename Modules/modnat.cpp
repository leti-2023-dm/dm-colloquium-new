#include "modnat.h"

int com_nn_d(Natural& first, Natural& second){
    return first > second? 2: first < second;
}

bool nzer_n_b(Natural& num){
    return num == 0;
}

Natural add_1n_n(Natural& num){
    return num + 1;
}

Natural add_nn_n(Natural& first, Natural& second){
    return first + second;
}

Natural sub_nn_n(Natural& first, Natural& second){
    try {
        return first - second;
    }
    catch (std::invalid_argument& e) {
        std::cout<<e.what()<<'\n';
    }
    return 0;
}

Natural mul_nd_n(Natural& num, int digit){
    return num * digit;
}

Natural mul_nk_n(Natural& num, size_t k){
    return num.mul_nk(k);
}

Natural mul_nn_n(Natural& num1, Natural& num2){
    return num1 * num2;
}

Natural sub_ndn_n(Natural& num1, Natural& num2, int digit){
    try{
        return num1 - num2 * digit;
    }
    catch (std::invalid_argument& e) {
        std::cout<<e.what()<<'\n';
    }
}

Natural div_nn_dk(Natural& num1, Natural& num2){
    return num1.div_nn_dk(num2);
}

Natural div_nn_n(Natural& num1, Natural& num2){
    return num1 / num2;
}

Natural mod_nn_n(Natural& num1, Natural& num2){
    return num1 % num2;
}

Natural gcf_nn_n(const Natural& num1, const Natural& num2){
    std::pair<Natural, Natural> pair = std::make_pair(num1, num2);
    while (pair.first != 0 && pair.second != 0)
        pair = std::make_pair(pair.second, pair.first % pair.second);
    return pair.first + pair.second;
}

Natural lcm_nn_n(Natural& num1, Natural& num2){
    return num1 * num2 / gcf_nn_n(num1, num2);
}

Natural fact_n_n(Natural& num){

}

Natural sqr_n_n(Natural& num){
    return num * num;
}

Natural pow_nn_n(Natural base, Natural exp){
    Natural res = 1;
    while (exp > 0){
        if (exp % 2 == 1){

        }
    }
}

Natural sqrt_n_q(Natural& num);