#include "MyYear.h"
#include <sstream>


MyYear::MyYear(const int year)
	: year_(year)
{
}

MyYear::~MyYear()
{
}

std::string MyYear::toString() const
{
	std::ostringstream stream;
	stream << year_;
	return stream.str();
}

bool MyYear::isLeap() const
{
	return false;
}
