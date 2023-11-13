#include "Polynomial.h"
#include <utility>
#include <sstream>
#include <algorithm>


Polynomial::Polynomial(std::vector<Rational> coefs): coefficients(std::move(coefs)) {
    std::reverse(this->coefficients.begin(), this->coefficients.end());
    delete_leading_zeroes();
}

Polynomial::Polynomial(const std::string& poly) {

}

Polynomial::Polynomial() {
    (*this) = Polynomial(Rational(0));
}

Polynomial::Polynomial(const Rational& num) {
    coefficients[0] = num;
}

Polynomial Polynomial::operator+(const Polynomial &other) const {
    size_t i = 0;
    Polynomial res = (*this);
    while (i < this->size() ){
        Rational other_num = i < other.size()? other[i] : 0;
        res[i] = res[i] + other_num;
        ++i;
    }
    while (i < other.size()) {
        Rational new_coef = other[i];
        res.coefficients.push_back(new_coef);
        i++;
    }
    return res;
}

Polynomial Polynomial::operator-(const Polynomial &other) const {
    size_t i = 0;
    Polynomial res = (*this);
    while (i < this->size() ){
        Rational other_num = i < other.size()? -other[i] : 0;
        res[i] = res[i] + other_num;
        ++i;
    }
    while (i < other.size()) {
        Rational new_coef = -other[i];
        res.coefficients.push_back(new_coef);
        i++;
    }
    return res;
}

Polynomial Polynomial::operator*(const Rational &coef) const {
    auto res = *this;
    for (auto& pol: res.coefficients) {
        pol = pol * coef;
    }
    return res;
}

Polynomial Polynomial::operator*(const Polynomial &other) const {
    Polynomial res = 0;
    for (size_t i = 0; i < other.size(); ++i) {
        res = res + ((*this) * other[i]).mul_pxk(i);
    }
    return res;
}

Polynomial Polynomial::mul_pxk(size_t k) const {
    auto res = (*this);
    for (size_t i = 0; i < k; ++i) {
        res.coefficients.insert(res.coefficients.begin(), 0);
    }
    return res;
}

Rational Polynomial::operator[](size_t index) const {
    return coefficients[index];
}

size_t Polynomial::size() const {
    return coefficients.size();
}

Rational Polynomial::fac_p() const {
    return Rational();
}

Polynomial Polynomial::operator/(const Polynomial &other) const {
    return Polynomial();
}

Polynomial Polynomial::operator%(const Polynomial &other) const {
    return Polynomial();
}

Polynomial Polynomial::der() const {
    return Polynomial();
}

Polynomial &Polynomial::operator=(const Polynomial &other) {
    Polynomial tmp(other);
    std::swap(tmp.coefficients, this->coefficients);
    return *this;
}

Polynomial &Polynomial::operator=(Polynomial &&other) noexcept {
    if (this != &other)
        std::swap(other.coefficients, this->coefficients);
    return *this;
}

Polynomial::Polynomial(const double &num) {
    (*this) = Polynomial(Rational(num));
}

void Polynomial::delete_leading_zeroes() {
    while (*(this->coefficients.end() - 1) == 0 && this->size() > 1)
        this->coefficients.pop_back();
}

std::ostream &operator<<(std::ostream &stream, const Polynomial &p) {
    auto deg = p.coefficients.size() - 1;
    for (size_t ind = 0; ind <= deg; ind++) {
        const Rational& coefficient = p.coefficients[deg - ind];
        const Integer& numerator = coefficient.getNumerator();
        auto isNegative = !numerator.isPositive();

        // we don't output monomials with zero coefficients
        if(numerator.abs().size() == 1 && numerator[0] == 0) continue;

        if (isNegative) stream << '(';
        stream << coefficient;
        if (isNegative) stream << ')';

        if (deg - ind != 0)
            stream << " * x^" << std::to_string(deg - ind) << " + ";
    }

    return stream;
}


