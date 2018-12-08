#pragma once
#include <iostream>

int mf() {
	int x = 12, y = 42, z = 88;
	std::cout << "Before -- x: " << x << "y:" << y;
	std::cout << " z: " << z << "\n\n";
	z = x = y + 13;
	std::cout << "After -- x: " << x << "y:" << y;
	std::cout << " z: " << z << "\n\n";
	return 0;
}