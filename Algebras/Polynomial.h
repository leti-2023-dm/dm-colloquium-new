
#ifndef COLOQ_POLYNOMIAL_H
#define COLOQ_POLYNOMIAL_H

#include "Rational.h"

class Polynomial {
private:
    std::vector<Rational> coefficients;
public:
    explicit Polynomial(std::vector<Rational> coefs);

    explicit Polynomial(const std::string &poly);

    Polynomial(const Polynomial &polynomial) = default;

    Polynomial(Polynomial &&polynomial) = default;

    Polynomial();

    Polynomial(const Rational &num, size_t deg = 0);

    Polynomial(const double &num);

    Polynomial &operator=(const Polynomial &other) = default;

    Polynomial &operator=(Polynomial &&other) = default;

    Polynomial operator+(const Polynomial &other) const;

    Polynomial operator-(const Polynomial &other) const;

    Polynomial operator*(const Rational &coef) const;

    Polynomial operator*(const Polynomial &other) const;

    Polynomial mul_pxk(size_t k) const;

    Rational operator[](size_t index) const;

    size_t size() const;


    size_t degre() const;

    Rational fac_p() const;

    Polynomial div_pp_qxk(const Polynomial &other) const;


    Polynomial operator/(const Polynomial &other) const;

    Polynomial operator%(const Polynomial &other) const;


    bool operator==(const Polynomial &other) const;

    bool operator!=(const Polynomial &other) const;

    Polynomial derivative() const;

    friend std::ostream &operator<<(std::ostream &stream, const Polynomial &p);

    void delete_leading_zeroes();
};


#endif
