#ifndef COLOQ_MY_TRY_MODPOLY_H
#define COLOQ_MY_TRY_MODPOLY_H
#include "../Algebras/Polynomial.h"

Polynomial add_pp_p(Polynomial& pol1, Polynomial& pol2);

Polynomial sub_pp_p(Polynomial& pol1, Polynomial& pol2);

Polynomial mul_pq_p(Polynomial& pol1, Rational& num);

Polynomial mul_pxk_p(Polynomial& pol1, size_t k);

Polynomial led_p_q(Polynomial& pol);

size_t deg_p_n(Polynomial& pol);

Rational fac_p_q(Polynomial& pol);

Polynomial mul_pp_p(Polynomial& pol1, Polynomial& pol2);

Polynomial div_pp_p(Polynomial& pol1, Polynomial& pol2);

Polynomial mod_pp_p(Polynomial& pol1, Polynomial& pol2);

Polynomial gcf_pp_p(Polynomial& pol1, Polynomial& pol2);

Polynomial der_p_p(Polynomial& pol);

Polynomial nmr_p_p(Polynomial& pol);

Rational solve_pq_q(Polynomial& pol, Rational& val;);


#endif //COLOQ_MY_TRY_MODPOLY_H
