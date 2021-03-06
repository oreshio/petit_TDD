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

	EXPECT_EQ("1660", testee.returnMoney());
	EXPECT_EQ("0", testee.getTotal());
}

TEST(VendingMachine_Step1, putAndReturnMoney)
{
	VendingMachine testee;
	EXPECT_EQ("1", testee.putMoney(1));
	EXPECT_EQ("5", testee.putMoney(5));
	EXPECT_EQ("", testee.putMoney(COIN_10));
	EXPECT_EQ("11", testee.putMoney(11));
	EXPECT_EQ("", testee.putMoney(BILL_1000));
	EXPECT_EQ("1001", testee.putMoney(1001));
	EXPECT_EQ("5000", testee.putMoney(5000));
	EXPECT_EQ("10000", testee.putMoney(10000));
	EXPECT_EQ("1010", testee.getTotal());
	EXPECT_EQ("1010", testee.returnMoney());
	EXPECT_EQ("0", testee.getTotal());
}


TEST(VendingMachine_Step2, checkStock)
{
	VendingMachine testee;
	EXPECT_EQ(3, testee.checkStock().size());
	EXPECT_EQ("120,コーラ,5", testee.checkStock().at(0));
	EXPECT_EQ("200,レッドブル,5", testee.checkStock().at(1));
	EXPECT_EQ("100,水,5", testee.checkStock().at(2));
}

TEST(VendingMachine_Step3, canBuy_1)
{
	VendingMachine testee;
	EXPECT_EQ(false, testee.canBuy("コーラ"));
	EXPECT_EQ("", testee.putMoney(COIN_50));
	EXPECT_EQ(false, testee.canBuy("コーラ"));
	EXPECT_EQ("", testee.putMoney(COIN_100));
	EXPECT_EQ(true, testee.canBuy("コーラ"));
	EXPECT_EQ(false, testee.canBuy("レッドブル"));
}

TEST(VendingMachine_Step3, canBuy_2)
{
	VendingMachine testee;
	EXPECT_EQ(false, testee.canBuy("コーラ"));
	EXPECT_EQ("", testee.putMoney(COIN_10));
	EXPECT_EQ("", testee.putMoney(COIN_10));
	EXPECT_EQ("", testee.putMoney(COIN_100));
	EXPECT_EQ(true, testee.canBuy("コーラ"));
}

TEST(VendingMachine_Step3, buy_1)
{
	VendingMachine testee;
	EXPECT_EQ("", testee.putMoney(COIN_10));
	EXPECT_EQ("", testee.putMoney(COIN_10));
	EXPECT_EQ("", testee.putMoney(COIN_100));
	EXPECT_EQ("120", testee.getTotal());
	EXPECT_EQ(true, testee.canBuy("コーラ"));
	EXPECT_EQ(true, testee.buy("コーラ"));
	EXPECT_EQ("0", testee.getTotal());
}

TEST(VendingMachine_Step3, buy_returnMoney)
{
	VendingMachine testee;
	EXPECT_EQ("", testee.putMoney(BILL_1000));
	EXPECT_EQ("1000", testee.getTotal());
	EXPECT_EQ(true, testee.canBuy("コーラ"));
	EXPECT_EQ(true, testee.buy("コーラ"));
	EXPECT_EQ("880", testee.getTotal());
	EXPECT_EQ(true, testee.buy("コーラ"));
	EXPECT_EQ("760", testee.getTotal());
	EXPECT_EQ(true, testee.buy("コーラ"));
	EXPECT_EQ("640", testee.getTotal());
	EXPECT_EQ(true, testee.buy("コーラ"));
	EXPECT_EQ("520", testee.getTotal());
	EXPECT_EQ(true, testee.buy("コーラ"));
	EXPECT_EQ("400", testee.getTotal());
	EXPECT_EQ(false, testee.buy("コーラ"));
	EXPECT_EQ(false, testee.canBuy("コーラ"));

	EXPECT_EQ("400", testee.returnMoney());
	EXPECT_EQ("0", testee.getTotal());
}

TEST(VendingMachine_Step3, getSales_returnMoney)
{
	VendingMachine testee;
	EXPECT_EQ(0, testee.getSales());
	EXPECT_EQ("", testee.putMoney(BILL_1000));
	EXPECT_EQ("1000", testee.getTotal());
	EXPECT_EQ(true, testee.buy("コーラ"));
	EXPECT_EQ(120, testee.getSales());
	EXPECT_EQ(true, testee.buy("コーラ"));
	EXPECT_EQ(240, testee.getSales());

	EXPECT_EQ("760", testee.returnMoney());
	EXPECT_EQ("0", testee.getTotal());
	EXPECT_EQ(240, testee.getSales());
}

TEST(VendingMachine_Step4, canBuyProductList)
{
	VendingMachine testee;
	EXPECT_EQ(0, testee.canBuyProductList().size());
	testee.putMoney(COIN_50);
	EXPECT_EQ(0, testee.canBuyProductList().size());
	testee.putMoney(COIN_50);
	EXPECT_EQ(1, testee.canBuyProductList().size());
	EXPECT_EQ("水", testee.canBuyProductList().at(0));
	testee.putMoney(COIN_10);
	EXPECT_EQ(1, testee.canBuyProductList().size());
	EXPECT_EQ("水", testee.canBuyProductList().at(0));
	testee.putMoney(COIN_10);
	EXPECT_EQ(2, testee.canBuyProductList().size());
	EXPECT_EQ("コーラ", testee.canBuyProductList().at(0));
	EXPECT_EQ("水", testee.canBuyProductList().at(1));
	testee.putMoney(COIN_10);
	EXPECT_EQ(2, testee.canBuyProductList().size());
	EXPECT_EQ("コーラ", testee.canBuyProductList().at(0));
	EXPECT_EQ("水", testee.canBuyProductList().at(1));
	testee.putMoney(COIN_100);
	EXPECT_EQ(3, testee.canBuyProductList().size());
	EXPECT_EQ("コーラ", testee.canBuyProductList().at(0));
	EXPECT_EQ("レッドブル", testee.canBuyProductList().at(1));
	EXPECT_EQ("水", testee.canBuyProductList().at(2));
}