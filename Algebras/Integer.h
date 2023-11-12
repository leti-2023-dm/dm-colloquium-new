#ifndef DM_COLLOQUIUM_NEW_INTEGER_H
#define DM_COLLOQUIUM_NEW_INTEGER_H

#include "Natural.h"

class Integer {
private:
    //True - negative, False - positive
    bool sign;
    Natural natural;

public:
    explicit Integer();

    Integer(long int num);

    explicit Integer(const Natural &num);

    explicit Integer(const std::string &num);

    explicit Integer(Natural num, bool sign);

    Integer(const Integer &num);

    Integer(Integer &&num) noexcept;

    Integer &operator=(Integer const &other);

    Integer &operator=(Integer &&other) noexcept;

    bool isPositive() const;

    Natural abs() const;

    //Invert number
    Integer operator-();

    bool operator>(Integer const &other) const;

    bool operator<(Integer const &other) const;

    bool operator==(Integer const &other) const;

    bool operator!=(Integer const &other) const;

    bool operator>=(Integer const &other) const;

    bool operator<=(Integer const &other) const;

    Integer operator+(Integer const &other);

    Integer operator-(Integer const &other);

    Integer operator*(Integer const &other) const;

    Integer operator*(Natural const &other) const;

    Integer operator/(Integer const &other);

    Integer operator%(Integer const &other);

    int &operator[](size_t index);

    const int &operator[](size_t index) const;

    friend std::ostream &operator<<(std::ostream &stream, const Integer &num);
};


#endif