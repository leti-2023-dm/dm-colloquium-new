#include "modpoly.h"


Polynomial add_pp_p(Polynomial& pol1, Polynomial& pol2){
    return pol1 + pol2;
}

Polynomial sub_pp_p(Polynomial& pol1, Polynomial& pol2){
    return pol1 - pol2;
}

Polynomial mul_pq_p(Polynomial& pol1, Rational& num){
    return pol1 * num;
}

Polynomial mul_pxk_p(Polynomial& pol1, size_t k){
    return pol1.mul_pxk(k);
}

Polynomial led_p_q(Polynomial& pol){
    return pol[pol.degre()];
}

size_t deg_p_n(Polynomial& pol){
    return pol.degre();
}

Rational fac_p_q(Polynomial& pol){
    return pol.fac_p();
}

Polynomial mul_pp_p(Polynomial& pol1, Polynomial& pol2){
    return pol1 * pol2;
}

Polynomial div_pp_p(Polynomial& pol1, Polynomial& pol2){
    return pol1 / pol2;
}

Polynomial mod_pp_p(Polynomial& pol1, Polynomial& pol2){
    return pol1 % pol2;
}

Polynomial gcf_pp_p(Polynomial& pol1, Polynomial& pol2){
    std::pair<Polynomial, Polynomial> pair = std::make_pair(pol1, pol2);
    while (pair.first != 0 && pair.second != 0)
        pair = std::make_pair(pair.second, pair.first % pair.second);
    return pair.first + pair.second;
}

Polynomial der_p_p(Polynomial& pol){
    return pol.derivative();
}

Polynomial nmr_p_p(Polynomial& pol){
    Polynomial deriv = pol.derivative();
    Polynomial res = pol / gcf_pp_p(pol, deriv);
    res = res * (Rational(1) / res.fac_p());
    return res;
}

Rational solve_pq_q(Polynomial& pol, Rational& val){
    Rational res = 0;
    for (int i = 0; i < pol.size(); ++i) {
        res = res + pol[i] * pow_qn_q(val, i);
    }
    return res;
}