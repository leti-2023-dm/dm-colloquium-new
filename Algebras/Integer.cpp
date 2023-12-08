#include "Integer.h"


Integer::Integer()
        : natural(0),
          sign(false) {}

Integer::Integer(Natural num, bool sign)
        : natural(std::move(num)),
          sign(num != 0 && sign) {}

Integer::Integer(const Natural &num)
        : Integer(num, false) {}

Integer::Integer(const std::string &num)
        : sign(num.at(0) == '-'),
         natural(num.substr(sign)) {}

Integer::Integer(long int num)
        : sign(num < 0),
          natural(num < 0 ? -num : num) {}


Integer::Integer(Integer &&num) noexcept = default;

Integer::Integer(const Integer &num) = default;


Natural Integer::abs() const {
    return natural;
}

bool Integer::isPositive() const {
    return !sign;
}

Integer Integer::operator-() {;
    return Integer(natural, natural != 0 && !sign);
}


Integer &Integer::operator=(const Integer &other) {
    Integer tmp(other);
    std::swap(tmp.natural, this->natural);
    std::swap(tmp.sign, this->sign);
    return *this;
}

Integer &Integer::operator=(Integer &&other) noexcept {
    if (this != &other) {
        std::swap(other.natural, this->natural);
        std::swap(other.sign, this->sign);
    }
    return *this;
}

Integer Integer::operator+(const Integer &other) {
    Natural a, b, res = 0;
    bool res_sign;
    if (natural >= other.natural) {
        a = natural;
        res_sign = this->sign;
        b = other.natural;
    } else {
        b = natural;
        res_sign = other.sign;
        a = other.natural;
    }

    if (sign == other.sign)
        res = a + b;
    else
        res = a - b;
    return Integer(res, res_sign);
}

Integer Integer::operator-(const Integer &other) {
    auto newOther = other;
    return (*this) + (-newOther);
}

Integer Integer::operator*(const Integer &other) const {
    return Integer(natural * other.natural, sign != other.sign);
}

Integer Integer::operator*(const Natural &other) const {
    return (*this) * Integer(other);
}

Integer Integer::operator/(const Integer &other) {
    if (other == 0)
        throw std::invalid_argument("Divide by zero");
    return Integer(natural / other.natural + (sign? 1: 0), sign != other.sign);
}

Integer Integer::operator%(const Integer &other) {
    auto a = (*this);
    auto b = other;
    auto q = a / b;
    return a - b * q;
}

std::ostream &operator<<(std::ostream &stream, const Integer &num) {
    if (num.sign) stream << '-';
    stream << num.natural;
    return stream;
}


int &Integer::operator[](size_t index) {
    return natural[index];
}


const int &Integer::operator[](size_t index) const {
    return natural[index];
}

bool Integer::operator==(const Integer &other) const {
    return natural == other.natural && sign == other.sign;
}

bool Integer::operator!=(const Integer &other) const {
    return !((*this) == other);
}

bool Integer::operator>(const Integer &other) const {
    if (isPositive() && !other.isPositive())
        return true;
    if (!isPositive() && other.isPositive())
        return false;
    if (isPositive())
        return natural > other.natural;
    return natural < other.natural;
}

bool Integer::operator>=(const Integer &other) const {
    return !(other > (*this));
}


bool Integer::operator<(const Integer &other) const {
    return other > (*this);
}

bool Integer::operator<=(const Integer &other) const {
    return other >= (*this);
}


