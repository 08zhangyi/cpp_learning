#pragma once
#include <iostream>

int mf() {
	int number;
	std::cout << "Enter a number: ";
	std::cin >> number;
	std::cout << "\nFirst 10 Multiples of " << number << "\n";
	for (int counter = 0; counter < 11; counter++) {
		std::cout << number * counter << " ";
	}
	std::cout << "\n";
	return 0;
}