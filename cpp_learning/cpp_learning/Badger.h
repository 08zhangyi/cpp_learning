#pragma once
#include <iostream>

int mf() {
	int badger;
	std::cout << "How many badgers? ";
	std::cin >> badger;

	do {
		std::cout << "Badger ";
		badger--;
	} while (badger > 0);

	std::cout << "\n";
	return 0;
}