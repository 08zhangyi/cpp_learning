#pragma once
#include <iostream>

int mf() {
	float goal[4];
	goal[0] = 0.9;
	goal[1] = 0.75;
	goal[2] = 0.5;
	goal[3] = 0.25;
	float weight, target;

	std::cout << "Enter current weight: ";
	std::cin >> weight;
	std::cout << "\nEnter goal weight: ";
	std::cin >> target;
	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		float loss = (weight - target) * goal[i];
		std::cout << "Goal " << i << ": ";
		std::cout << target + loss << std::endl;
	}

	return 0;
}