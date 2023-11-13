#ifndef DM_COLLOQUIUM_NEW_RATIONAL_H
#define DM_COLLOQUIUM_NEW_RATIONAL_H

#include "Integer.h"

// Store reduced
class Rational {
private:
    Integer numerator;
    Natural denominator;

public:
    Rational();

    Rational(const Integer &numerator, const Natural &denominator);

    Rational(Integer numerator);

    Rational(const std::string &num);

    Rational(const double& num);

    Rational(const Rational &num);

    Rational(Rational &&num) noexcept;

    void reduce();

    Rational operator-();

    Rational &operator=(Rational const &other);

    Rational &operator=(Rational &&other) noexcept;

    bool operator==(Rational const &other) const;

    bool operator!=(Rational const &other) const;

    bool operator>(Rational const &other) const;

    bool operator<(Rational const &other) const;

    bool operator>=(Rational const &other) const;

    bool operator<=(Rational const &other) const;

    Rational operator+(Rational const &other) const;

    Rational operator-(Rational const &other) const;

    Rational operator*(Rational const &other) const;

    Rational operator/(Rational const &other) const;

    bool isInt() const;

    Integer getNumerator() const;

    Natural getDenominator() const;


    friend std::ostream &operator<<(std::ostream &stream, const Rational &num);
};


#endif
