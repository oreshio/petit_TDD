#include "StdAfx.h"
#include "FizzBuzz.h"

#include <string>
#include <sstream>


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
	stream << input;
	return stream.str();
}
