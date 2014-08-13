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
