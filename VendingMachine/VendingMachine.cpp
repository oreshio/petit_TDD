#include "VendingMachine.h"
#include <sstream>
#include <vector>

using namespace Money;

namespace
{
	std::string toString(const int value)
	{
		std::ostringstream stream;
		stream << value;
		return stream.str();
	}
}

VendingMachine::VendingMachine()
	: money_()
	, products_()
{
	products_["Cola"] = ProductData(120, 5);
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
	return toString(money);
}

std::string VendingMachine::getTotal() const
{
	return toString(money_);
}

std::string VendingMachine::returnMoney()
{
	std::ostringstream stream;
	stream << money_;
	money_ = 0;
	return stream.str();
}

std::string VendingMachine::checkStock() const
{
	std::string totalOutput;
	for (std::map<std::string, ProductData>::const_iterator iterator = products_.begin();
		 iterator != products_.end();
		 ++iterator)
	{
		std::string output;
		output.append(toString(iterator->second.priceOfUnit_));
		output.append(",");
		output.append(iterator->first);
		output.append(",");
		output.append(toString(iterator->second.number_));

		totalOutput.append(output);
	}
	return totalOutput;
}

bool VendingMachine::canBuy(const std::string productName) const
{
	std::map<std::string, ProductData>::const_iterator iterator = products_.find(productName);
	if (iterator == products_.end())
	{
		return false;
	}
	if (0 == iterator->second.number_)
	{
		return false;
	}
	if (money_ < iterator->second.priceOfUnit_)
	{
		return false;
	}
	return true;
}

bool VendingMachine::buy(const std::string productName)
{
	if (!canBuy(productName))
	{
		return false;
	}
	std::map<std::string, ProductData>::iterator iterator = products_.find(productName);
	if (iterator == products_.end())
	{
		return false;
	}
	--(iterator->second.number_);
	money_ -= iterator->second.priceOfUnit_;
	return true;
}
