#include <gtest/gtest.h>
#include "../VendingMachine.h"

using namespace Money;

TEST(VendingMachine, Test_Constructor)
{
	VendingMachine testee;
}

TEST(VendingMachine_Step0, putMoney)
{
	VendingMachine testee;
	testee.putMoney(COIN_10);
	EXPECT_EQ("10", testee.getTotal());
	testee.putMoney(COIN_50);
	EXPECT_EQ("60", testee.getTotal());
	testee.putMoney(COIN_100);
	EXPECT_EQ("160", testee.getTotal());
	testee.putMoney(COIN_500);
	EXPECT_EQ("660", testee.getTotal());
	testee.putMoney(BILL_1000);
	EXPECT_EQ("1660", testee.getTotal());
}
