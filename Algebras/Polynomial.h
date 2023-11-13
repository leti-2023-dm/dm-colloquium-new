#ifndef COLOQ_MY_TRY_POLYNOMIAL_H
#define COLOQ_MY_TRY_POLYNOMIAL_H
#include "Rational.h"

class Polynomial {
private:
    std::vector<Rational> coefficients;
public:
    explicit Polynomial(std::vector<Rational> coefs);

    explicit Polynomial(const std::string& poly);

    Polynomial(const Polynomial& polynimial) = default;

    Polynomial(Polynomial&& polynimial) = default;

    Polynomial();

    Polynomial(const Rational& num, size_t deg = 0);

    Polynomial(const double& num);

    Polynomial& operator=(const Polynomial& other);

    Polynomial& operator=(Polynomial&& other) noexcept ;

    Polynomial operator+(const Polynomial& other) const;

    Polynomial operator-(const Polynomial& other) const;

    Polynomial operator*(const Rational& coef) const;

    Polynomial operator*(const Polynomial& other) const;

    Polynomial mul_pxk(size_t k) const;

    Rational operator[](size_t index) const;

    size_t size() const;

    size_t degre() const;

    Rational fac_p() const;

    Polynomial div_pp_qxk(const Polynomial& other) const;

    Polynomial operator/(const Polynomial& other) const;

    Polynomial operator%(const Polynomial& other) const;

    bool operator == (const Polynomial& other) const;

    bool operator != (const Polynomial& other) const;

    Polynomial derivative() const;

    void delete_leading_zeroes();
};


#endif //COLOQ_MY_TRY_POLYNOMIAL_H
