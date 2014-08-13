#pragma once
#include <iostream>

class MyYear
{
public:
	explicit MyYear(const int year);
	~MyYear();

	std::string toString() const;
	bool isLeap() const;

private:
	const int year_;
};

