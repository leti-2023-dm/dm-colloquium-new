#include <gtest/gtest.h>
#include "../Modules/modrat.h"

// Tests for the red_q_q function
TEST(ReduceRationalTest, TestReduceRational) {
    Rational num1(2, 4);
    Rational num2(-3, 9);

    EXPECT_EQ(red_q_q(num1), Rational(1, 2));
    EXPECT_EQ(red_q_q(num2), Rational(-1, 3));
}

// Tests for the int_q_b function
TEST(IsIntegerTest, TestIfRationalIsInteger) {
    Rational integerNum(5);
    Rational nonIntegerNum(3, 2);

    EXPECT_TRUE(int_q_b(integerNum));
    EXPECT_FALSE(int_q_b(nonIntegerNum));
}

// Tests for the trans_z_q function
TEST(TranslateIntegerToRationalTest, TestTranslationFromIntegerToRational) {
    Integer integerNum(7);
    Rational result = trans_z_q(integerNum);

    EXPECT_EQ(result, Rational(7));
}

// Tests for the trans_q_z function
TEST(TranslateRationalToIntegerTest, TestTranslationFromRationalToInteger) {
    Rational integerRational(5);
    Rational nonIntegerRational(3, 2);

    EXPECT_EQ(trans_q_z(integerRational), 5);
    EXPECT_THROW(trans_q_z(nonIntegerRational), std::invalid_argument);  // Expecting an exception for non-integer
}

// Tests for the add_qq_q function
TEST(AddRationalsTest, TestAdditionOfRationals) {
    Rational num1(1, 3);
    Rational num2(2, 5);

    EXPECT_EQ(add_qq_q(num1, num2), Rational(11, 15));
}

// Tests for the sub_qq_q function
TEST(SubtractRationalsTest, TestSubtractionOfRationals) {
    Rational num1(1, 3);
    Rational num2(2, 5);

    EXPECT_EQ(sub_qq_q(num1, num2), Rational(-1, 15));
}

// Tests for the mul_qq_q function
TEST(MultiplyRationalsTest, TestMultiplicationOfRationals) {
    Rational num1(1, 3);
    Rational num2(2, 5);

    EXPECT_EQ(mul_qq_q(num1, num2), Rational(2, 15));
}

// Tests for the div_qq_q function
TEST(DivideRationalsTest, TestDivisionOfRationals) {
    Rational num1(1, 3);
    Rational num2(2, 5);

    EXPECT_EQ(div_qq_q(num1, num2), Rational(5, 6));
}

// Tests for the pow_qn_q function
TEST(PowerOfRationalTest, TestPowerOfRational) {
    Rational base(2, 3);
    Natural exp(3);

    EXPECT_EQ(pow_qn_q(base, exp), Rational(8, 27));
}
