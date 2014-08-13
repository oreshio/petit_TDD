#pragma once
#include <iostream>

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
	VendingMachine();
	~VendingMachine();

	void putMoney(const int money);
	std::string getTotal() const;
	std::string returnMoney();

private:
	int money_;
};

