#pragma once
#include <iostream>

void swap(int& x, int& y);

int mf() {
	int x = 5, y = 10;
	std::cout << "Main. Before swap, x: " << x << " y: " << y << std::endl;
	swap(x, y);
	std::cout << "Main. After swap, x: " << x << " y: " << y << std::endl;
	return 0;
}

void swap(int& rx, int& ry) {
	int temp;
	std::cout << "Swap. Before swap, rx: " << rx << " ry: " << ry << std::endl;
	temp = rx;
	rx = ry;
	ry = temp;
	std::cout << "Swap. After swap, rx: " << rx << " ry: " << ry << std::endl;
}