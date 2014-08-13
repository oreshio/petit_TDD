#include "VendingMachine.h"
#include <sstream>
#include <vector>

using namespace Money;

VendingMachine::VendingMachine()
	: money_()
{
}


VendingMachine::~VendingMachine()
{
}

std::string VendingMachine::putMoney(const int money)
{
	static std::vector<int> enableMoney;
	if (enableMoney.empty())
	{
		enableMoney.push_back(COIN_10);
		enableMoney.push_back(COIN_50);
		enableMoney.push_back(COIN_100);
		enableMoney.push_back(COIN_500);
		enableMoney.push_back(BILL_1000);
	}
	for (std::vector<int>::const_iterator iterator = enableMoney.begin();
		 iterator != enableMoney.end();
		 ++iterator)
	{
		if (money == *iterator)
		{
        	money_ += money;
			return std::string();
		}
	}
	std::ostringstream stream;
	stream << money;
	return stream.str();
}

std::string VendingMachine::getTotal() const
{
	std::ostringstream stream;
	stream << money_;
	return stream.str();
}

std::string VendingMachine::returnMoney()
{
	std::ostringstream stream;
	stream << money_;
	money_ = 0;
	return stream.str();
}
