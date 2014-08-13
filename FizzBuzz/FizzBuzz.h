#pragma once
#include <iostream>

class FizzBuzz
{
public:
	FizzBuzz();
	~FizzBuzz();

	std::string calculate(const int input) const;

	void call();
};

