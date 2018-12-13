#pragma once
#include <iostream>

constexpr double getPi() {
	return (double)22 / 7;
}

int mf() {
	float radius;

	std::cout << "Enter the radius of the circle: ";
	std::cin >> radius;

	double area = getPi() * (radius * radius);

	std::cout << "\nCircle's area: " << area << std::endl;

	return 0;
}