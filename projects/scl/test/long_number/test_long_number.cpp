#include <gtest/gtest.h>
#include "long_number.hpp"
TEST(get_digits_number, check_positive) {
ISurin::LongNumber x("12345");
EXPECT_EQ(5, x.get_digits_number())
<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
ISurin::LongNumber x("-1");
EXPECT_EQ(1, x.get_digits_number())
<< "Неправильно подсчитано количество разрядов в числе " << x;
}

class EqualityFixture : public testing::Test {
public:
    ISurin::LongNumber one_v1 = ISurin::LongNumber("1");
    ISurin::LongNumber one_v2 = ISurin::LongNumber("1");
    ISurin::LongNumber seven = ISurin::LongNumber("7");
    ISurin::LongNumber eleven = ISurin::LongNumber("11");
    ISurin::LongNumber twelve = ISurin::LongNumber("12");
    ISurin::LongNumber negative_one = ISurin::LongNumber("-1");
    ISurin::LongNumber hundred = ISurin::LongNumber("1000");
    ISurin::LongNumber num_1 = ISurin::LongNumber("143043646467550005435000");
    ISurin::LongNumber num_2 = ISurin::LongNumber("143043646467550005435000000");
    ISurin::LongNumber num_3 = ISurin::LongNumber("143043646467267836806260550005435000");
};

TEST_F(EqualityFixture, equal) {
ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
ASSERT_FALSE(one_v1 == negative_one)
<< "Проверка " << one_v1 << " == " << negative_one;
}

TEST_F(EqualityFixture, less) {
EXPECT_LT(one_v1 , twelve) << "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(EqualityFixture, great) {
EXPECT_GT(twelve, one_v1) << "Проверка " << twelve << " > " << one_v1;
}

TEST_F(EqualityFixture, sum) {
ISurin::LongNumber result = one_v1 + eleven;
EXPECT_EQ(result , twelve) << "Проверка " << one_v1 << " + " << eleven << " = " << twelve;
}

TEST_F(EqualityFixture, diff) {
ISurin::LongNumber result = twelve - one_v1;
EXPECT_EQ(result , eleven) << "Проверка " << twelve << " - " << eleven << " = " << eleven;
}

TEST_F(EqualityFixture, multiplie) {
ISurin::LongNumber result = hundred * num_1;
EXPECT_EQ(result , num_2) << "Проверка " << hundred << " * " << num_1 << " = " << num_2;
}

TEST_F(EqualityFixture, module) {
ISurin::LongNumber result = num_3 % eleven;
EXPECT_EQ(result , seven) << "Проверка " << num_3 << " - " << eleven << " = " << seven;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}