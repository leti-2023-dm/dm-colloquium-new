#include <gtest/gtest.h>
#include "../Modules/modint.h"

// Tests for the com_nn_d function
TEST(ComparisonTest, CompareNaturalNumbers) {
    Natural num1(12345);
    Natural num2(54321);

    EXPECT_EQ(com_nn_d(num1, num2), 1);  // Expecting num1 < num2
    EXPECT_EQ(com_nn_d(num2, num1), 2);  // Expecting num2 > num1
    EXPECT_EQ(com_nn_d(num1, num1), 0);  // Expecting num1 == num1
}

// Tests for the nzer_n_b function
TEST(ZeroCheckTest, CheckIfNaturalIsZero) {
    Natural zero;
    Natural nonZero(123);

    EXPECT_TRUE(nzer_n_b(zero));
    EXPECT_FALSE(nzer_n_b(nonZero));
}

// Tests for the add_1n_n function
TEST(AddOneTest, AddOneToNatural) {
    Natural num(999);
    Natural result = add_1n_n(num);

    EXPECT_EQ(result, Natural(1000));
}

// Tests for the add_nn_n function
TEST(AddNumbersTest, AddTwoNaturalNumbers) {
    Natural num1(12345);
    Natural num2(54321);
    Natural result = add_nn_n(num1, num2);

    EXPECT_EQ(result, 66666);
}

// Tests for the sub_nn_n function (subtract two natural numbers)
TEST(SubtractNumbersTest, SubtractTwoNaturalNumbers) {
    Natural num1(54321);
    Natural num2(12345);
    Natural result = sub_nn_n(num1, num2);

    EXPECT_EQ(result, 41976);
}

// Tests for the mul_nd_n function
TEST(MultiplyByDigitTest, MultiplyNaturalByDigit) {
    Natural num(12345);
    int digit = 5;
    Natural result = mul_nd_n(num, digit);

    EXPECT_EQ(result, 61725);
}

// Tests for the mul_nk_n function
TEST(MultiplyByPowerOf10Test, MultiplyNaturalByPowerOf10) {
    Natural num(12345);
    size_t k = 3;
    Natural result = mul_nk_n(num, k);

    EXPECT_EQ(result, 12345000);
}

// Tests for the mul_nn_n function
TEST(MultiplyNumbersTest, MultiplyTwoNaturalNumbers) {
    Natural num1(123);
    Natural num2(456);
    Natural result = mul_nn_n(num1, num2);

    EXPECT_EQ(result, 56088);
}

// Tests for the sub_ndn_n function
TEST(SubtractProductFromNaturalTest, SubtractProductFromNatural) {
    Natural num1(98765);
    Natural num2(4321);
    int digit = 5;
    Natural result = sub_ndn_n(num1, num2, digit);

    EXPECT_EQ(result, 77160);
}

// Tests for the div_nn_dk function
TEST(DivideByNaturalWithRemainderTest, DivideNaturalByNaturalWithRemainder) {
    Natural num1(10110);
    Natural num2(100);
    Natural result = div_nn_dk(num1, num2);

    EXPECT_EQ(result, 100);
}

// Tests for the div_nn_n function
TEST(DivideNumbersTest, DivideTwoNaturalNumbers) {
    Natural num1(98765);
    Natural num2(123);
    Natural result = div_nn_n(num1, num2);

    EXPECT_EQ(result, 802);
}

// Tests for the mod_nn_n function
TEST(ModuloTest, CalculateModuloOfTwoNaturalNumbers) {
    Natural num1(98765);
    Natural num2(123);
    Natural result = mod_nn_n(num1, num2);

    EXPECT_EQ(result, 119);
}

// Tests for the gcf_nn_n function
TEST(GreatestCommonFactorTest, FindGreatestCommonFactorOfTwoNaturalNumbers) {
    Natural num1(24);
    Natural num2(36);
    Natural result = gcf_nn_n(num1, num2);

    EXPECT_EQ(result, 12);
}

// Tests for the lcm_nn_n function
TEST(LeastCommonMultipleTest, FindLeastCommonMultipleOfTwoNaturalNumbers) {
    Natural num1(8);
    Natural num2(12);
    Natural result = lcm_nn_n(num1, num2);

    EXPECT_EQ(result, 24);
}

// Tests for the fact_n_n function
TEST(FactorialTest, CalculateFactorialOfNaturalNumber) {
    Natural num(5);
    Natural result = fact_n_n(num);

    EXPECT_EQ(result, 120);
}

// Tests for the sqr_n_n function
TEST(SquareTest, CalculateSquareOfNaturalNumber) {
    Natural num(7);
    Natural result = sqr_n_n(num);

    EXPECT_EQ(result, 49);
}

// Tests for the pow_nn_n function
TEST(PowerTest, CalculatePowerOfNaturalNumber) {
    Natural base(2);
    Natural exp(10);
    Natural result = pow_nn_n(base, exp);

    EXPECT_EQ(result, 1024);
}

/*
// Tests for the sqrt_n_q function
TEST(SquareRootTest, CalculateSquareRootOfNaturalNumber) {
    Natural num(25);
    Natural result = sqrt_n_q(num);

    EXPECT_EQ(result, 5);
}
*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
