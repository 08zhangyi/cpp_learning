#pragma once
#include <iostream>

int mf() {
	int grade;
	std::cout << "Enter a grade (1-100): ";
	std::cin >> grade;
	if (grade >= 70) {
		if (grade >= 90) {
			std::cout << "\nYou got an A. Great job!\n";
			return 0;
		}
		if (grade >= 80) {
			std::cout << "\nYou got a B. Good work!\n";
			return 0;
		}
		std::cout << "\nYou got a C. Perfectly adequate!\n";
	}
	else
		std::cout << "\nYou got an F. I failed as a parent!\n";
	return 0;
}