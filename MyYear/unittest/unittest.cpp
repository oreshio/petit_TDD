#include <iostream>

#include <gtest/gtest.h>

#include "../MyYear.h"

TEST(MyYear, Test_Constructor)
{
	MyYear testee(1978);
	EXPECT_EQ("1978", testee.toString());
	EXPECT_EQ(false, testee.isLeap());
}

TEST(MyYear, Test_Uruu_4)
{
	MyYear testee(4);
	EXPECT_EQ("4", testee.toString());
	EXPECT_EQ(true, testee.isLeap());
}

TEST(MyYear, Test_Uruu_Minus1)
{
	MyYear testee(-1);
	EXPECT_EQ("-1", testee.toString());
	EXPECT_EQ(false, testee.isLeap());
}

TEST(MyYear, Test_Uruu_20)
{
	MyYear testee(20);
	EXPECT_EQ("20", testee.toString());
	EXPECT_EQ(true, testee.isLeap());
}

TEST(MyYear, Test_Uruu_100)
{
	MyYear testee(100);
	EXPECT_EQ("100", testee.toString());
	EXPECT_EQ(false, testee.isLeap());
}

TEST(MyYear, Test_Uruu_400)
{
	MyYear testee(400);
	EXPECT_EQ("400", testee.toString());
	EXPECT_EQ(true, testee.isLeap());
}

TEST(MyYear, Test_Uruu_401)
{
	MyYear testee(401);
	EXPECT_EQ("401", testee.toString());
	EXPECT_EQ(false, testee.isLeap());
}
