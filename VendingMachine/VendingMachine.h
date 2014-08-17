#pragma once
#include <iostream>
#include <map>
#include <vector>

namespace Money
{
	const int COIN_10 = 10;
	const int COIN_50 = 50;
	const int COIN_100 = 100;
	const int COIN_500 = 500;
	const int BILL_1000 = 1000;
}

class VendingMachine
{
public:
	struct ProductData
	{
		ProductData::ProductData()
		: priceOfUnit_(0)
		, number_(0) {}
		ProductData::ProductData(const int priceOfUnit, const int number)
		: priceOfUnit_(priceOfUnit)
		, number_(number) {}
		ProductData::~ProductData(){}
		int priceOfUnit_;
		int number_;
	};

	VendingMachine();
	~VendingMachine();

	std::string putMoney(const int money);
	std::string getTotal() const;
	std::string returnMoney();
	std::vector<std::string> checkStock() const;
	bool canBuy(const std::string productName) const;
	bool buy(const std::string productName);
	int getSales() const;

private:
	void trade(const int price);

private:
	int money_;
	int sales_;
	std::map<std::string, ProductData> products_;
};

