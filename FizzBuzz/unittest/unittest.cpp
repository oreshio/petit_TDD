#include <iostream>

#include <gtest/gtest.h>
#include "FizzBuzz.h"

TEST(FizzBuzz, Test1)
{
	FizzBuzz testee;
	EXPECT_EQ("1", testee.calculate(1));
}

