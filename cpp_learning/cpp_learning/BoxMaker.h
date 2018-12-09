#pragma once
#include <iostream>

int mf() {
	int rows, columns;
	char character;

	std::cout << "How many rows? ";
	std::cin >> rows;
	std::cout << "How many columns? ";
	std::cin >> columns;
	std::cout << "What character to display? ";
	std::cin >> character;
	std::cout << "\n";

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << character;
		}
		std::cout << "\n";
	}
	return 0;
}