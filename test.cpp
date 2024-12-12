#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"

TEST_SUITE("MATH") {
    TEST_CASE("TESTING ADDITION") {
        REQUIRE(CalculateBrackets("1+1") == 2);
        CHECK(CalculateBrackets("-1+1") == 0);
        CHECK(CalculateBrackets("-4+1") == -3);
        CHECK_THROWS(CalculateBrackets("aaaa")); 
        CHECK_THROWS(CalculateBrackets("   ")); 
    }

    TEST_CASE("TESTING SUBTRACTION") {
        CHECK(CalculateBrackets("1-1") == 0);
        CHECK(CalculateBrackets("-1-1") == -2);
        CHECK(CalculateBrackets("-4--4") == 0);
        CHECK_THROWS(CalculateBrackets("4..5-1")); 
    }

    TEST_CASE("TESTING DIVISION") {
        REQUIRE(CalculateBrackets("1/0.36") == doctest::Approx(2.7).epsilon(0.1));
        REQUIRE(CalculateBrackets("1/1") == doctest::Approx(1).epsilon(0.1));
        REQUIRE(CalculateBrackets("100000/7.36") == doctest::Approx(13586.9565).epsilon(0.1));
        REQUIRE(CalculateBrackets("22.0/7.0") == doctest::Approx(3.141).epsilon(0.01));
        CHECK_THROWS(CalculateBrackets("1/0")); 
    }

    TEST_CASE("TESTING EXPONENTIATION") {
        REQUIRE(CalculateBrackets("2^3") == 8);
        REQUIRE(CalculateBrackets("5^0") == 1);
        REQUIRE(CalculateBrackets("9^(0.5)") == doctest::Approx(3).epsilon(0.01)); 
        CHECK_THROWS(CalculateBrackets("1^^2")); 
    }

    TEST_CASE("TESTING BRACKETS") {
        REQUIRE(CalculateBrackets("(1+2)*3") == 9);
        REQUIRE(CalculateBrackets("((2+3)*2)") == 10);
        REQUIRE(CalculateBrackets("(((4+5)*2)-3)") == 15);
        CHECK_THROWS(CalculateBrackets("(1+2))")); 
        CHECK_THROWS(CalculateBrackets("((1+2)")); 
    }

    TEST_CASE("TESTING FLOATING-POINT VALIDATION") {
        CHECK_THROWS(CalculateBrackets("1..2+3")); 
        CHECK_THROWS(CalculateBrackets("3+4.5.6")); 
        CHECK(CalculateBrackets("3.14+2.86") == doctest::Approx(6).epsilon(0.01));
    }

    TEST_CASE("TESTING COMPLEX EXPRESSIONS") {
        REQUIRE(CalculateBrackets("(1+2)*(3+4)") == 21);
        REQUIRE(CalculateBrackets("((2+3)^2)/(1+1)") == 12.5);
        REQUIRE(CalculateBrackets("3+(2*(1+(4/2)))") == 9);
        CHECK_THROWS(CalculateBrackets("3+((2*5)))))")); 
    }
}

TEST_SUITE_BEGIN("MATH");
TEST_SUITE_END();
