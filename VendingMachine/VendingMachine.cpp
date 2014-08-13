#include "VendingMachine.h"
#include <sstream>

VendingMachine::VendingMachine()
	: money_()
{
}


VendingMachine::~VendingMachine()
{
}

void VendingMachine::putMoney(const int money)
{
	money_ += money;
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
