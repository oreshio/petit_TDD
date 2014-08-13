#include "MyYear.h"
#include <sstream>

namespace
{
	const int VALUE_400 = 400;
	const int VALUE_100 = 100;
	const int VALUE_4 = 4;
}

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
	if (0 == year_ % VALUE_400)
	{
		return true;
	}
	else if (0 == year_ % VALUE_100)
	{
		return false;
	}
	else if (0 == year_ % VALUE_4)
	{
		return true;
	}
	return false;
}
