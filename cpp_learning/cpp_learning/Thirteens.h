#pragma once
#include <iostream>

int mf() {
	int counter = 0;
	while (counter < 500) {
		counter++;
		if (counter % 13 == 0) {
			std::cout << counter << " ";
		}
	}
	std::cout << "\n";
	return 0;
}