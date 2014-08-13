#include "StdAfx.h"
#include "FizzBuzz.h"

#include <string>
#include <sstream>

namespace
{
	const int FIZZ_VALUE = 3;
	const int BUZZ_VALUE = 5;
	const int FIZZ_BUZZ_VALUE = 15;
}

FizzBuzz::FizzBuzz(void)
{
}


FizzBuzz::~FizzBuzz(void)
{
}

void FizzBuzz::call()
{
	std::cout << "Called";
}

std::string FizzBuzz::calculate(const int input) const
{
	std::ostringstream stream;
	if (0 == input % FIZZ_VALUE)
	{
		return "Fizz";
	}
	else if (0 == input % BUZZ_VALUE)
	{
		return "Buzz";
	}
	else if (0 == input % FIZZ_BUZZ_VALUE)
	{
		return "FizzBuzz";
	}
	stream << input;
	return stream.str();
}
