#include <iostream>

#include <gtest/gtest.h>
#include "FizzBuzz.h"

TEST(FizzBuzz, Test1)
{
	FizzBuzz testee;
	EXPECT_EQ("1", testee.calculate(1));
	EXPECT_EQ("2", testee.calculate(2));
	EXPECT_EQ("Fizz", testee.calculate(3));
	EXPECT_EQ("4", testee.calculate(4));
	EXPECT_EQ("Buzz", testee.calculate(5));
	EXPECT_EQ("Fizz", testee.calculate(6));
	EXPECT_EQ("7", testee.calculate(7));
	EXPECT_EQ("8", testee.calculate(8));
	EXPECT_EQ("Fizz", testee.calculate(9));
	EXPECT_EQ("Buzz", testee.calculate(10));
	EXPECT_EQ("11", testee.calculate(11));
	EXPECT_EQ("Fizz", testee.calculate(12));
	EXPECT_EQ("13", testee.calculate(13));
	EXPECT_EQ("14", testee.calculate(14));
	EXPECT_EQ("FizzBuzz", testee.calculate(15));
}

