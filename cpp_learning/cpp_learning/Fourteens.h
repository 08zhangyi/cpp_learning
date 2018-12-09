#pragma once
#include <iostream>

int mf() {
	int counter = 0;
	int multiples = 0;

	while (true) {
		counter++;
		if (counter % 14 == 0) {
			std::cout << counter << " ";
			multiples++;
		}
		if (multiples > 19)
			break;
	}
	std::cout << "\n";
	return 0;
}