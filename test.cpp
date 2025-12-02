#include <gtest/gtest.h>
#include "twelve.h"

using namespace twelve;

TEST(TwelveTest, DefaultConstructor) {
    Twelve t;
    Twelve expected("0");
    EXPECT_TRUE(t.Equals(expected));
}

TEST(TwelveTest, SizeConstructor) {
    Twelve t1(3, 5);
    Twelve expected1({5, 5, 5});
    EXPECT_TRUE(t1.Equals(expected1));
}

TEST(TwelveTest, StringConstructor) {
    Twelve t1("123");
    Twelve expected1("123");
    EXPECT_TRUE(t1.Equals(expected1));
    
    EXPECT_THROW(Twelve t2("12C3"), std::invalid_argument);
}

TEST(TwelveTest, CopyConstructor) {
    Twelve t1("B98");
    Twelve t2(t1);
    EXPECT_TRUE(t1.Equals(t2));
}

TEST(TwelveTest, AddMethod) {
    Twelve t1("123");
    Twelve t2("456");
    Twelve result = Twelve::Add(t1, t2);
    Twelve expected("579");
    EXPECT_TRUE(result.Equals(expected));
    Twelve t3("B");
    Twelve t4("1");
    Twelve res2 = Twelve::Add(t3, t4);
    Twelve exp2("10");
    EXPECT_TRUE(res2.Equals(exp2));
    Twelve t5("B3");
    Twelve t6("9");
    Twelve res3 = Twelve::Add(t5, t6);
    Twelve exp3("100");
    EXPECT_TRUE(res3.Equals(exp3));
}

TEST(TwelveTest, SubstractMethod) {
    Twelve t1("6A");
    Twelve t2("37");
    Twelve result = Twelve::Substract(t1, t2);
    Twelve expected("33");
    EXPECT_TRUE(result.Equals(expected));

    Twelve t3("100");
    Twelve t4("1");
    Twelve res2 = Twelve::Substract(t3, t4);
    Twelve exp2("BB");
    EXPECT_TRUE(res2.Equals(exp2));

    EXPECT_THROW(Twelve::Substract(Twelve("50"), Twelve("100")), std::invalid_argument);
}

TEST(TwelveTest, ComparisonMethods) {
    Twelve t1("100");
    Twelve t2("B0");
    Twelve t3("100");

    EXPECT_TRUE(t1.Greaters(t2));
    EXPECT_TRUE(t2.Less(t1));
    EXPECT_TRUE(t1.Equals(t3));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}