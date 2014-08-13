#include <iostream>

#include <gtest/gtest.h>
#include "FizzBuzz.h"

TEST(FizzBuzz, Test1)
{
	FizzBuzz testee;
	EXPECT_EQ("1", testee.calculate(1));
}

//// Run all the tests that were declared with TEST()
//int main(int argc, char **argv){
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
