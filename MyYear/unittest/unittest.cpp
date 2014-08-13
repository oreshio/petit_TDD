#include <iostream>

#include <gtest/gtest.h>

#include "../MyYear.h"

TEST(MyYear, Test_Constructor)
{
	MyYear testee(1978);
	EXPECT_EQ("1978", testee.toString());
	EXPECT_EQ(false, testee.isLeap());
}
