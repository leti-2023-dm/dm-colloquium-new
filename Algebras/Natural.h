#ifndef COLOQ_MY_TRY_NATURALM_H
#define COLOQ_MY_TRY_NATURAL_H

#include <vector>
#include <iostream>


class Natural {
private:
    std::vector<int> number; // is reversed
    void delete_starting_zeroes();

    void push_front_digit(int digit);

public:
    Natural operator*(int const &digit) const;

    Natural mul_nk(size_t k);

    Natural div_nn_dk(Natural const &other);

    [[nodiscard]] size_t size() const;

    Natural(size_t num);

    Natural();

    explicit Natural(std::vector<int> num);

    explicit Natural(const std::string &num);

    Natural(const Natural &num);

    Natural(Natural &&num) noexcept;

    Natural &operator=(Natural const &other);

    Natural &operator=(Natural &&other) noexcept;

    bool operator>(Natural const &other) const;

    bool operator<(Natural const &other) const;

    bool operator==(Natural const &other) const;

    bool operator!=(Natural const &other) const;

    bool operator>=(Natural const &other) const;

    bool operator<=(Natural const &other) const;

    int &operator[](size_t index);

    const int &operator[](size_t index) const;

    Natural &operator++();

    Natural operator+(Natural const &other) const;

    Natural operator-(Natural const &other) const;

    Natural operator*(Natural const &other) const;

    Natural operator/(Natural const &other) const;

    Natural operator%(Natural const &other) const;

    friend std::ostream &operator<<(std::ostream &stream, const Natural &num);
};


#endif //COLOQ_MY_TRY_NATURALM_H
