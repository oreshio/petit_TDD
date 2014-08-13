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
	EXPECT_EQ("5", testee.calculate(5));
	EXPECT_EQ("Fizz", testee.calculate(6));
}

