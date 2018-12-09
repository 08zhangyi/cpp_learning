#pragma once
#include <iostream>

bool isLeapYear(int year);

int mf() {
	int input;
	std::cout << "Enter a year: ";
	std::cin >> input;
	if (isLeapYear(input))
		std::cout << input << " is a leap year\n";
	else
		std::cout << input << " is not a leap year\n";
	return 0;
}

bool isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else return false;
}