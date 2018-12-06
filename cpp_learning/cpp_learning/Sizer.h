#pragma once
#include <iostream>

int mf() {
	std::cout << "The size of an integer:\t\t";
	std::cout << sizeof(int) << " bytes\n";
	std::cout << "The size of a short integer:\t";
	std::cout << sizeof(short) << " bytes\n";
	std::cout << "The size of a long integer:\t";
	std::cout << sizeof(long) << " bytes\n";
	std::cout << "The size of a character:\t";
	std::cout << sizeof(char) << " bytes\n";
	std::cout << "The size of a boolean:\t\t";
	std::cout << sizeof(bool) << " bytes\n";
	std::cout << "The size of a float:\t\t";
	std::cout << sizeof(float) << " bytes\n";
	std::cout << "The size of a double float:\t";
	std::cout << sizeof(double) << " bytes\n";
	std::cout << "The size of a long long int:\t";
	std::cout << sizeof(long long int) << " bytes\n";
	return 0;
}