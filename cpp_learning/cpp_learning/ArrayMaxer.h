#pragma once
#include <iostream>

constexpr int getArraySize()
{
	return 1024;
}

int mf()
{
	int bolts[getArraySize()];
	int boltsSize = sizeof(bolts) / sizeof(bolts[0]);

	for (int i = 0; i < boltsSize; i++)
	{
		bolts[i] = i * boltsSize;
	}

	std::cout << "Value of bolts[10]: " << bolts[10] << std::endl;
	return 0;
}