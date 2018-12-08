#pragma once
#include <iostream>

int mf() {
	int grade;
	std::cout << "Enter a grade (1-100): ";
	std::cin >> grade;
	if (grade >= 70)
		std::cout << "\nYou passed. Hooray!\n";
	else
		std::cout << "\nYou failed. Sigh.\n";
	return 0;
}