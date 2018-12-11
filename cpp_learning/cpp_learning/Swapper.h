#pragma once
#include <iostream>

int mf() {
	int value1 = 12500;
	int value2 = 17000;
	int *pointer2 = nullptr;

	pointer2 = &value2;
	value1 = *pointer2;
	pointer2 = nullptr;

	std::cout << "value1 = " << value1 << "\n";

	return 0;
}