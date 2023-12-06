#include "Polynomial.h"
#include <utility>
#include <sstream>
#include <algorithm>
#include <cstring>


Polynomial::Polynomial(std::vector<Rational> coefs) : coefficients(std::move(coefs)) {
    std::reverse(this->coefficients.begin(), this->coefficients.end());
    delete_leading_zeroes();
}


Polynomial::Polynomial(const std::string& poly) {
    Polynomial res;
    std::stringstream stream(poly);
    std::string tmp;
    while (getline(stream, tmp, '+')){
        size_t xid = tmp.find('x');
        if (xid == std::string::npos){
            res = res + Rational(tmp);
            continue;
        }
        std::string left = tmp.substr(0, xid != 0 && tmp[xid] == '*'? xid : xid - 1);
        Rational coef = Rational(left != "x" ? left: "1");
        if (xid + 2 >= tmp.size())
            continue;
        std::string right = tmp.substr(xid + 2, tmp.size() - xid - 2);
        std::stringstream sstream(right);
        size_t degre;
        sstream >> degre;
        res = res + Polynomial(coef, degre);
    }
    *this = res;
}

Polynomial::Polynomial(): Polynomial(Rational(0)) {

}


Polynomial::Polynomial(const Rational &num, size_t deg) {
    while (coefficients.size() <= deg)
        coefficients.insert(coefficients.begin(), 0);
    coefficients[deg] = num;
}

Polynomial Polynomial::operator+(const Polynomial &other) const {
    size_t i = 0;
    Polynomial res = (*this);

    while (i < this->size()) {
        Rational other_num = i < other.size() ? other[i] : 0;
        res.coefficients[i] = res[i] + other_num;
        i++;
    }
    while (i < other.size()) {
        Rational new_coef = other[i];
        res.coefficients.push_back(new_coef);
        i++;
    }
    res.delete_leading_zeroes();
    return res;
}

Polynomial Polynomial::operator-(const Polynomial &other) const {
    size_t i = 0;
    Polynomial res = (*this);

    while (i < this->size()) {
        Rational other_num = i < other.size() ? -other[i] : 0;
        res.coefficients[i] = res[i] + other_num;
        i++;
    }
    while (i < other.size()) {
        Rational new_coef = -other[i];
        res.coefficients.push_back(new_coef);
        i++;
    }
    res.delete_leading_zeroes();
    return res;
}

Polynomial Polynomial::operator*(const Rational &coef) const {
    auto res = *this;
    for (auto &pol: res.coefficients) {
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

    Natural numerator = coefficients[0].getNumerator().abs();
    bool numer_sign = !coefficients[0].getNumerator().isPositive();
    Natural denominator = coefficients[0].getDenominator();
    for (size_t i = 1; i < this->size(); ++i) {
        numer_sign = (numer_sign + !coefficients[i].getNumerator().isPositive()) % 2;
        numerator = gcf_nn_n(numerator, coefficients[i].getNumerator().abs());
        denominator = lcm_nn_n(denominator, coefficients[i].getDenominator());
    }
    Integer numer = Integer(numerator, numer_sign);
    return {numer, denominator};
}

Polynomial Polynomial::operator/(const Polynomial &other) const {
    Polynomial res = 0;
    Polynomial tmp = *this;

    while (tmp.degre() >= other.degre() && tmp.degre() > 0) {
        Polynomial div_res = tmp.div_pp_qxk(other);
        res = res + div_res;
        tmp = tmp - (other * div_res);
    }

    if (other.degre() == 0) {
        res = res + tmp[0] / other[0];
    }
    return res;
}


Polynomial Polynomial::operator%(const Polynomial &other) const {
    return (*this) - (other * ((*this) / other));
}

Polynomial Polynomial::derivative() const {
    Polynomial res = *this;
    for (int i = 2; i < res.size(); ++i) {
        res.coefficients[i] = res[i] * i;
    }
    res.coefficients.erase(res.coefficients.begin());
    return res;
}


Polynomial::Polynomial(const double &num) {
    (*this) = Polynomial(Rational(num));
}

void Polynomial::delete_leading_zeroes() {
    while (*(this->coefficients.end() - 1) == 0 && this->size() > 1)
        this->coefficients.pop_back();
}


Polynomial Polynomial::div_pp_qxk(const Polynomial &other) const {
    Polynomial res = Polynomial(coefficients[coefficients.size() - 1] / other[other.size() - 1],
                                this->size() - other.size());
    return res;
}

size_t Polynomial::degre() const {
    return this->size() - 1;
}

bool Polynomial::operator==(const Polynomial &other) const {
    if (this->degre() != other.degre())
        return false;
    for (int i = 0; i < this->size(); ++i) {
        if (coefficients[i] != other[i])
            return false;
    }
    return true;
}

bool Polynomial::operator!=(const Polynomial &other) const {
    return !((*this) == other);
}

std::ostream &operator<<(std::ostream &stream, const Polynomial &p) {
    auto deg = p.coefficients.size() - 1;
    for (size_t ind = 0; ind <= deg; ind++) {
        const Rational &coefficient = p.coefficients[deg - ind];
        const Integer &numerator = coefficient.getNumerator();
        auto isNegative = !numerator.isPositive();

        // we don't output monomials with zero coefficients
        if (numerator.abs().size() == 1 && numerator[0] == 0) continue;

        if (isNegative) stream << '(';
        stream << coefficient;
        if (isNegative) stream << ')';

        if (deg - ind != 0)
            stream << " * x^" << std::to_string(deg - ind) << " + ";
    }

    return stream;
}



