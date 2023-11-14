#include <gtest/gtest.h>
#include "../Modules/modint.h"

// Tests for the abs_z_n function
TEST(AbsoluteValueTest, TestAbsoluteValueOfInteger) {
    Integer num1(123);
    Integer num2(-456);
    Integer num3(0);

    EXPECT_EQ(abs_z_n(num1), 123);
    EXPECT_EQ(abs_z_n(num2), 456);
    EXPECT_EQ(abs_z_n(num3), 0);
}

// Tests for the poz_z_d function
TEST(PositiveOrZeroTest, TestPositivityOfInteger) {
    Integer positiveNum(123);
    Integer negativeNum(-456);
    Integer zero(0);

    EXPECT_EQ(poz_z_d(positiveNum), 2);    // Expecting positiveNum > 0, so result should be 2
    EXPECT_EQ(poz_z_d(negativeNum), 1);    // Expecting negativeNum < 0, so result should be 1
    EXPECT_EQ(poz_z_d(zero), 0);           // Expecting zero == 0, so result should be 0
}

// Tests for the mul_zm_z function
TEST(MultiplyByMinusOneTest, TestMultiplicationByMinusOne) {
    Integer num1(123);
    Integer num2(-456);
    Integer num3(0);

    EXPECT_EQ(mul_zm_z(num1), -123);
    EXPECT_EQ(mul_zm_z(num2), 456);
    EXPECT_EQ(mul_zm_z(num3), 0);
}

// Tests for the trans_n_z function
TEST(TranslateNaturalToIntegerTest, TestTranslationFromNaturalToInteger) {
    Natural naturalNum(12345);
    Integer result = trans_n_z(naturalNum);
    result = -result;

    EXPECT_EQ(result, -12345);
}

// Tests for the trans_z_n function
TEST(TranslateIntegerToNaturalTest, TestTranslationFromIntegerToNatural) {
    Integer positiveNum(123);
    Integer negativeNum(-456);

    EXPECT_EQ(trans_z_n(positiveNum), 123);
    EXPECT_THROW(trans_z_n(negativeNum), std::invalid_argument);  // Expecting an exception for negativeNum
}

// Tests for the add_zz_z function
TEST(AddIntegersTest, TestAdditionOfIntegers) {
    Integer num1(123);
    Integer num2(-456);

    EXPECT_EQ(add_zz_z(num1, num2), -333);
}

// Tests for the sub_zz_z function
TEST(SubtractIntegersTest, TestSubtractionOfIntegers) {
    Integer num1(123);
    Integer num2(-456);

    EXPECT_EQ(sub_zz_z(num1, num2), 579);
}

// Tests for the mul_zz_z function
TEST(MultiplyIntegersTest, TestMultiplicationOfIntegers) {
    Integer num1(123);
    Integer num2(-456);

    EXPECT_EQ(mul_zz_z(num1, num2), -56088);
}

// Tests for the div_zz_z function
TEST(DivideIntegersTest, TestDivisionOfIntegers) {
    Integer num1(123);
    Integer num2(-456);
    Integer res = div_zz_z(num1, num2);
    EXPECT_EQ(res, -123 / 456);  // Note: integer division
}

// Tests for the mod_zz_z function
TEST(ModuloIntegersTest, TestModuloOfIntegers) {
    Integer num1(123);
    Integer num2(10);

    EXPECT_EQ(mod_zz_z(num1, num2), 3);
}

// Tests for the pow_zn_z function
TEST(PowerOfIntegerTest, TestPowerOfInteger) {
    Integer num1(2);
    Natural exp(10);

    EXPECT_EQ(pow_zn_z(num1, exp), 1024);
}

