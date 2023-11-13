#ifndef COLOQ_MY_TRY_POLYNIMIAL_H
#define COLOQ_MY_TRY_POLYNIMIAL_H
#include "Rational.h"

class Polynimial {
private:
    std::vector<Rational> coefficients;
public:
    explicit Polynimial(std::vector<Rational> coefs);

    explicit Polynimial(const std::string& poly);

    Polynimial(const Polynimial& polynimial) = default;

    Polynimial(Polynimial&& polynimial) = default;

    Polynimial();

    Polynimial(const Rational& num);

    Polynimial(const double& num);

    Polynimial& operator=(const Polynimial& other);

    Polynimial& operator=(Polynimial&& other) noexcept ;

    Polynimial operator+(const Polynimial& other) const;

    Polynimial operator-(const Polynimial& other) const;

    Polynimial operator*(const Rational& coef) const;

    Polynimial operator*(const Polynimial& other) const;

    Polynimial mul_pxk(size_t k) const;

    Rational operator[](size_t index) const;

    size_t size() const;

    Rational fac_p() const;

    Polynimial operator/(const Polynimial& other) const;

    Polynimial operator%(const Polynimial& other) const;

    Polynimial der() const;

    void delete_leading_zeroes();
};


#endif //COLOQ_MY_TRY_POLYNIMIAL_H
