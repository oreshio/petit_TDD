// FizzBuzz.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

#include <iostream>
#include "FizzBuzz.h"

namespace
{
	const int INPUT_MAX = 100;
}

int _tmain(int argc, _TCHAR* argv[])
{
	FizzBuzz fizzbuzz;
	for (int i = 1; i <= INPUT_MAX; ++i)
	{
		std::cout << fizzbuzz.calculate(i).c_str() << std::endl;
	}
	return 0;
}

