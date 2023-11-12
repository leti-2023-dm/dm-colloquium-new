#include "Rational.h"

#include <utility>

Rational::Rational()
        : numerator(0),
          denominator(1) {}

//TODO: reduce it
Rational::Rational(const Integer &numerator, const Natural &denominator)
        : numerator(numerator),
          denominator(denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator can't be zero");
    if (numerator == 0)
        this->denominator = 1;
}

Rational::Rational(const Rational &num) = default;

Rational::Rational(Rational &&num) noexcept = default;

Rational::Rational(const std::string &num) {
    // number 1242.222
}

Rational::Rational(Integer numerator)
        : numerator(std::move(numerator)), denominator(1) {}

Rational Rational::operator-() {
    return {-numerator, denominator};
}

Rational &Rational::operator=(const Rational &other) {
    Rational rational(other);
    std::swap(rational.numerator, this->numerator);
    std::swap(rational.denominator, this->denominator);
    return *this;
}

Rational &Rational::operator=(Rational &&other) noexcept {
    if (this != &other) {
        std::swap(other.numerator, this->numerator);
        std::swap(other.denominator, this->denominator);
    }
    return *this;
}

bool Rational::operator==(const Rational &other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator!=(const Rational &other) const {
    return !((*this) == other);
}

bool Rational::operator>(const Rational &other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Rational::operator<(const Rational &other) const {
    return other > (*this);
}

bool Rational::operator>=(const Rational &other) const {
    return !((*this) < other);
}

bool Rational::operator<=(const Rational &other) const {
    return other >= (*this);
}

Rational Rational::operator+(const Rational &other) const {
    auto newNumerator1 = Integer(other.denominator) * numerator;
    auto newNumerator2 = Integer(denominator) * other.numerator;

    return {newNumerator1 + newNumerator2, denominator * other.denominator};
}

Rational Rational::operator-(const Rational &other) const {
    auto negative = -Rational(other);
    return (*this) + negative;
}

Rational Rational::operator*(const Rational &other) const {
    return {numerator * other.numerator, denominator * other.denominator};
}

Rational Rational::operator/(const Rational &other) const {
    Rational secondOperand(
            Integer(other.denominator, !other.numerator.isPositive()),
            other.numerator.abs()
    );

    return (*this) * secondOperand;
}

//TODO: output decimal view
std::ostream &operator<<(std::ostream &stream, const Rational &num) {
    stream << num.numerator;
    if (num.denominator != 1) stream << '/' << num.denominator;
    return stream;
}


