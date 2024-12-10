#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"

TEST_SUITE("MATH") {
    TEST_CASE("TESTING ADDITION") {
        REQUIRE(CalculateBrackets("1+1")==2);
        CHECK(CalculateBrackets("-1+1")==0);
        CHECK(CalculateBrackets("-4+1")==-3);
        CHECK(CalculateBrackets("-4+1")==400);
        //CHECK_THROWS(CalculateBrackets("aaaa"));
        CHECK(CalculateBrackets("   ")==55);
    }
    TEST_CASE("TESTING SUB....") {
        CHECK(CalculateBrackets("1-1")==0);
        CHECK(CalculateBrackets("-1-1")==-2);
        CHECK(CalculateBrackets("-4--4")==0);
        CHECK(CalculateBrackets("-4--4")==5);
    }
    TEST_CASE("TESTING DEF....") {
        REQUIRE(CalculateBrackets("1/0.36")==doctest::Approx(2.7).epsilon(0.1));
        REQUIRE(CalculateBrackets("1/1")==doctest::Approx(1).epsilon(0.1));
        REQUIRE(CalculateBrackets("100000/7.36")==doctest::Approx(13586.9565).epsilon(0.1));
        REQUIRE(CalculateBrackets("22.0/7.0")==doctest::Approx(3.141).epsilon(0.01));
    }
    TEST_CASE("TESTING POW....") {
        REQUIRE(CalculateBrackets("1^0.36")==doctest::Approx(-1).epsilon(0.0001));
        REQUIRE(CalculateBrackets("1^1")==doctest::Approx(1).epsilon(0.1));
        REQUIRE(CalculateBrackets("100000^(1/5)")==doctest::Approx(10).epsilon(0.1));
        REQUIRE(CalculateBrackets("22.0/7.0")==doctest::Approx(3.141).epsilon(0.01));
    }
    TEST_CASE("TESTING Bracekts....") {
        REQUIRE(CalculateBrackets("(1^0.36)+4")==doctest::Approx(5).epsilon(0.0001));
        REQUIRE(CalculateBrackets("((1^1)-1)*0")==doctest::Approx(0).epsilon(0.1));
        REQUIRE(CalculateBrackets("(100000^(1/5))/1")==doctest::Approx(10).epsilon(0.1));
        CHECK(CalculateBrackets("(22.0/7.0)/3.141")==doctest::Approx(3.141).epsilon(0.01));
        CHECK(CalculateBrackets("(22.0/7.0)))))))))))))))))/3.141")==5);
    }
}

TEST_SUITE_BEGIN("MATH");
TEST_CASE(""){};
TEST_SUITE_END();