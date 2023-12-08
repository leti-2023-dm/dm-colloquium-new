#include "Natural.h"
#include <algorithm>
#include <utility>
#include <cmath>

Natural::Natural(size_t num) {
    auto natural = Natural(std::to_string(num));
    *this = natural;
}

Natural::Natural(std::vector<int> num) : number(std::move(num)) {
    std::reverse(this->number.begin(), this->number.end());
    int buf = 0;
    for (auto digit: this->number) {
        digit += buf;
        buf = 0;
        while (digit > 9) {
            digit -= 10;
            buf += 1;
        }
    }
    while (buf != 0) {
        this->number.push_back(buf % 10);
        buf /= 10;
    }
//    delete_starting_zeroes();
}

Natural::Natural(const std::string &num) {
    for (auto digitChar: num) {
        if (!isdigit(digitChar))
            throw std::invalid_argument("Not a number");
        int digit = digitChar - '0';
        this->number.insert(this->number.begin(), digit);
    }
    delete_starting_zeroes();
}

Natural::Natural(const Natural &num) = default;

Natural::Natural(Natural &&num) noexcept = default;

Natural &Natural::operator=(const Natural &other) {
    Natural tmp(other);
    std::swap(tmp.number, this->number);
    return *this;
}

Natural &Natural::operator=(Natural &&other) noexcept {
    if (this != &other)
        std::swap(other.number, this->number);
    return *this;
}

bool Natural::operator>(const Natural &other) const{
    if (this->size() > other.size())
        return true;
    if (this->size() < other.size())
        return false;
    for (auto i = this->size() - 1; i > 0; --i)
        if (this->number[i] != other.number[i])
            return this->number[i] > other.number[i];
    if (this->number[0] != other.number[0])
        return this->number[0] > other.number[0];
    return false;
}

bool Natural::operator<(const Natural &other) const{
    if (this->size() < other.size())
        return true;
    if (this->size() > other.size())
        return false;
    for (auto i = this->size() - 1; i > 0; --i)
        if (this->number[i] != other.number[i])
            return this->number[i] < other.number[i];
    if (this->number[0] != other.number[0])
        return this->number[0] < other.number[0];
    return false;
}

bool Natural::operator==(const Natural &other) const{
    if (this->size() != other.size())
        return false;
    for (auto i = 0; i < this->size(); ++i)
        if (this->number[i] != other.number[i])
            return false;
    return true;
}

bool Natural::operator!=(const Natural &other) const{
    return !(*this == other);
}

bool Natural::operator>=(const Natural &other) const{
    return !(*this < other);
}

bool Natural::operator<=(const Natural &other) const {
    return !(*this > other);
}

size_t Natural::size() const {
    return this->number.size();
}

void Natural::delete_starting_zeroes() {
    while (*(this->number.end() - 1) == 0 && this->size() > 1)
        this->number.pop_back();
}

std::ostream &operator<<(std::ostream &stream, const Natural &num) {
    for (auto i = num.number.end() - 1; i >= num.number.begin(); --i)
        stream << (int) *i;
    return stream;
}

Natural &Natural::operator++() {
    this->number[0] += 1;
    int buf = 0;
    for (auto digit: this->number) {
        digit += buf;
        buf = 0;
        while (digit > 9) {
            digit -= 10;
            buf += 1;
        }
    }
    if (buf != 0)
        this->number.push_back(buf);
    return *this;
}

Natural Natural::operator+(const Natural &other) const{
    size_t i = 0;
    int buf = 0;
    Natural res = (*this);
    while (i < this->size() ){
        int other_num = i < other.size()? other[i] : 0;
        res[i] = res[i] + other_num + buf;
        buf = res[i] / 10;
        res[i] %= 10;
        ++i;
    }
    while (i < other.size()) {
        int new_digit = other[i] + buf;
        buf = new_digit / 10;
        new_digit %= 10;
        res.number.push_back(new_digit);
        i++;
    }
    while (buf != 0) {
        res.number.push_back(buf % 10);
        buf /= 10;
    }
    return res;
}

int& Natural::operator[](size_t index) {
    return this->number[index];
}

const int &Natural::operator[](size_t index) const {
    return this->number[index];
}

Natural::Natural() {
    *this = 0;
}

Natural Natural::operator-(const Natural &other) const{
    if ((*this) < other)
        throw std::invalid_argument("subtrahend is greater then minuend");
    int buf = 0;
    size_t i;
    Natural res = (*this);
    for (i = 0; i < other.size(); ++i) {
        res[i] -= other[i] + buf;
        buf = 0;
        if (res[i] < 0){
            res[i] += 10;
            buf = 1;
        }
    }
    while (buf != 0){
        res[i] -= buf;
        buf = 0;
        if (res[i] < 0){
            res[i] += 10;
            buf = 1;
        }
        i++;
    }
    res.delete_starting_zeroes();
    return res;
}

Natural Natural::operator*(const int &digit) const{
    if (digit < 0 || digit > 9)
        throw std::invalid_argument("Not a digit");
    if ((*this) == 0 || digit == 0) {
        return 0;
    }
    if (digit == 1)
        return *this;

    int buf = 0;
    Natural res = (*this);
    for (auto& num_digit: res.number) {
        num_digit = num_digit * digit + buf;
        buf = num_digit / 10;
        num_digit %= 10;
    }
    if (buf != 0)
        res.number.push_back(buf);
    return res;
}

Natural Natural::operator*(const Natural &other) const{
    if ((*this) == 0 || other == 0)
        return 0;
    if ((*this) == 1 )
        return other;
    if (other == 1)
        return *this;

    Natural a, b, res = 0;
    if ((*this) >= other){
        a = *this;
        b = other;
    } else{
        b = *this;
        a = other;
    }
    for (size_t i = 0; i < b.size(); ++i) {
        Natural a1 = a * b[i];
        a1 = a1.mul_nk(i);
        res = res + a1;
    }
    return res;
}

Natural Natural::mul_nk(size_t k) {
    if ((*this) == 0)
        return 0;
    Natural tmp = (*this);
    for (size_t i = 0; i < k; ++i)
        tmp.number.insert(tmp.number.begin(), 0);
    return tmp;
}

Natural Natural::div_nn_dk(Natural const &other) {
    if ((*this) < other)
        return 0;
    auto k = this->number.end() - 1;
    Natural divisible = 0;
    while (divisible < other)
        divisible.push_front_digit(*(k--));
    Natural res = 1;
    Natural tmp = other;
    while (tmp <= divisible){
        tmp = tmp + other;
        ++res;
    }
    res = res - 1;
    size_t power = k - this->number.begin() + 1;
    res = res.mul_nk(power);
    return res;
}

void Natural::push_front_digit(int digit) {
    if ((*this) == 0)
        this->number[0] = digit;
    else
        this->number.insert(this->number.begin(), digit);
}

Natural Natural::operator/(const Natural &other) const {
    Natural res = 0;
    Natural tmp = *this;
    while(tmp >= other){
        Natural div_res = tmp.div_nn_dk(other);
        res = res + div_res;
        tmp = tmp - (other * div_res);
    }
    return res;
}

Natural Natural::operator%(const Natural &other) const {
    return (*this) - (other * ((*this) / other));
}

