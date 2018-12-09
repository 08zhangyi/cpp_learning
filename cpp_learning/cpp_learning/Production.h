#pragma once
#include <iostream>

int mf() {
	int production[] = { 10500, 16000, 5800, 4500, 13900 };
	for (int year : production) {
		std::cout << "Output: " << year << std::endl;
	}
	return 0;
}