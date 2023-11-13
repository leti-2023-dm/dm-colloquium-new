#include "Polynimial.h"
#include <utility>
#include <sstream>
#include <algorithm>


Polynimial::Polynimial(std::vector<Rational> coefs): coefficients(std::move(coefs)) {
    std::reverse(this->coefficients.begin(), this->coefficients.end());
    delete_leading_zeroes();
}

Polynimial::Polynimial(const std::string& poly) {

}

Polynimial::Polynimial() {
    (*this) = Polynimial(Rational(0));
}

Polynimial::Polynimial(const Rational& num) {
    coefficients[0] = num;
}

Polynimial Polynimial::operator+(const Polynimial &other) const {
    size_t i = 0;
    Polynimial res = (*this);
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

Polynimial Polynimial::operator-(const Polynimial &other) const {
    size_t i = 0;
    Polynimial res = (*this);
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

Polynimial Polynimial::operator*(const Rational &coef) const {
    auto res = *this;
    for (auto& pol: res.coefficients) {
        pol = pol * coef;
    }
    return res;
}

Polynimial Polynimial::operator*(const Polynimial &other) const {
    Polynimial res = 0;
    for (size_t i = 0; i < other.size(); ++i) {
        res = res + ((*this) * other[i]).mul_pxk(i);
    }
    return res;
}

Polynimial Polynimial::mul_pxk(size_t k) const {
    auto res = (*this);
    for (size_t i = 0; i < k; ++i) {
        res.coefficients.insert(res.coefficients.begin(), 0);
    }
    return res;
}

Rational Polynimial::operator[](size_t index) const {
    return coefficients[index];
}

size_t Polynimial::size() const {
    return coefficients.size();
}

Rational Polynimial::fac_p() const {
    return Rational();
}

Polynimial Polynimial::operator/(const Polynimial &other) const {
    return Polynimial();
}

Polynimial Polynimial::operator%(const Polynimial &other) const {
    return Polynimial();
}

Polynimial Polynimial::der() const {
    return Polynimial();
}

Polynimial &Polynimial::operator=(const Polynimial &other) {
    Polynimial tmp(other);
    std::swap(tmp.coefficients, this->coefficients);
    return *this;
}

Polynimial &Polynimial::operator=(Polynimial &&other) noexcept {
    if (this != &other)
        std::swap(other.coefficients, this->coefficients);
    return *this;
}

Polynimial::Polynimial(const double &num) {
    (*this) = Polynimial(Rational(num));
}

void Polynimial::delete_leading_zeroes() {
    while (*(this->coefficients.end() - 1) == 0 && this->size() > 1)
        this->coefficients.pop_back();
}
