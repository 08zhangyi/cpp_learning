#pragma once
#include <iostream>

int mf() {
	int counter = 0;
	int multiples = 0;

	while (multiples < 19) {
		counter++;
		if (counter % 15 != 0)
			continue;
		std::cout << counter << " ";
		multiples++;
	}
	std::cout << "\n";
	return 0;
}