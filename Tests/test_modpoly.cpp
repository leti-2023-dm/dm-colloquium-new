#include <gtest/gtest.h>
#include "../Modules/modpoly.h"


// Tests for the add_pp_p function
TEST(AddPolynomialsTest, TestAdditionOfPolynomials) {
    Polynomial pol1({Rational(1), 2, 3});
    Polynomial pol2({Rational(-1), 3, 5});
    Polynomial polr({Rational(5), Rational(8)});

    EXPECT_EQ(add_pp_p(pol1, pol2), polr);
}

// Tests for the sub_pp_p function
TEST(SubtractPolynomialsTest, TestSubtractionOfPolynomials) {
    Polynomial pol1({Rational(1), 2, 3});
    Polynomial pol2({Rational(-1), 3, 5});
    Polynomial polr({Rational(2), -1, -2});

    EXPECT_EQ(sub_pp_p(pol1, pol2), polr);
}

// Tests for the mul_pq_p function
TEST(MultiplyPolynomialByRationalTest, TestMultiplicationOfPolynomialByRational) {
    Polynomial pol({Rational(1), 2, 3});
    Rational num(2, 3);
    Polynomial polr({Rational(2, 3), Rational(4, 3), 2});

    EXPECT_EQ(mul_pq_p(pol, num), polr);
}

// Tests for the mul_pxk_p function
TEST(MultiplyPolynomialByPowerOfXTest, TestMultiplicationOfPolynomialByPowerOfX) {
    Polynomial pol({Rational(1), 2, 3});
    Polynomial polr({Rational(1), 2, 3, 0, 0});

    EXPECT_EQ(mul_pxk_p(pol, 2), polr);
}

// Tests for the led_p_q function
TEST(LeadingCoefficientTest, TestLeadingCoefficientOfPolynomial) {
    Polynomial pol({Rational(1), 2, 3});

    EXPECT_EQ(led_p_q(pol), Rational(1));
}

// Tests for the deg_p_n function
TEST(DegreeOfPolynomialTest, TestDegreeOfPolynomial) {
    Polynomial pol({Rational(1), 2, 3});

    EXPECT_EQ(deg_p_n(pol), 2);
}

// Tests for the fac_p_q function
TEST(FactorialOfPolynomialTest, TestFactorialOfPolynomial) {
    Polynomial pol({Rational(1, 2), 2, 3});

    EXPECT_EQ(fac_p_q(pol), Rational(1, 2));
}

// Tests for the mul_pp_p function
TEST(MultiplyPolynomialsTest, TestMultiplicationOfPolynomials) {
    Polynomial pol1({Rational(1), 2, 3});
    Polynomial pol2({Rational(-1), 3, 5});
    Polynomial polr({Rational(-1), 1, 8, 19, 15});

    EXPECT_EQ(mul_pp_p(pol1, pol2), polr);
}

TEST(DividePolynomialsTest, TestDivisionOfPolynomials) {
    Polynomial pol1({Rational(1), 2, 3, 4});
    Polynomial pol2({Rational(1), Rational(2)});
    Polynomial polr({Rational(1), 0, 1});
}

// Tests for the mod_pp_p function
TEST(ModuloPolynomialsTest, TestModuloOfPolynomials) {
    Polynomial pol1({Rational(1), 2, 3, 4});
    Polynomial pol2({Rational(1), Rational(2)});
    Polynomial polr(Rational(-2));

    EXPECT_EQ(mod_pp_p(pol1, pol2), polr);
}

// Tests for the gcf_pp_p function
TEST(GreatestCommonFactorTest, TestGreatestCommonFactorOfPolynomials) {
    Polynomial pol1({Rational(2), 4, 6});
    Polynomial pol2({Rational(-2), -4, -6});
    Polynomial polr1({Rational(2), 4, 6});
    Polynomial polr2({Rational(-2), -4, -6});
    Polynomial res = gcf_pp_p(pol1, pol2);
    EXPECT_TRUE(res == polr1 || res == polr2);
}

// Tests for the der_p_p function
TEST(DerivativeOfPolynomialTest, TestDerivativeOfPolynomial) {
    Polynomial pol({Rational(1), 2, 3, 4});
    Polynomial polr({Rational(3), 4, 3});

    EXPECT_EQ(der_p_p(pol), polr);
}

// Tests for the solve_pq_q function
TEST(SolvePolynomialTest, TestSolvingPolynomial) {
    Polynomial pol({Rational(1), 2, 3});
    Rational val1(2, 3);
    Rational val2(0);

    EXPECT_EQ(solve_pq_q(pol, val1), Rational(43, 9));
    EXPECT_EQ(solve_pq_q(pol, val2), Rational(3));
}


// Tests for the nmr_p_p function
TEST(NMRPolynomialTest, TestNMRPolynomial) {
    Polynomial pol({Rational(1), 2, 1});
    Polynomial polr({Rational(1, 2), Rational(1, 2)});

    EXPECT_EQ(nmr_p_p(pol) , polr);
}

