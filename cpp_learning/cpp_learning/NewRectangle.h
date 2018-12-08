#pragma once
#include <iostream>

int mf() {
	typedef unsigned short USHORT;
	USHORT width = 26;
	USHORT length = 40;
	USHORT area = width * length;

	std::cout << "Width: " << width << "\n";
	std::cout << "Length: " << length << "\n";
	std::cout << "Area: " << area << "\n";
	return 0;
}