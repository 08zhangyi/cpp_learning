#pragma once
#include <iostream>

int mf() {
	int intOne;
	int &rSomeRef = intOne;

	intOne = 5;
	std::cout << "intOne: " << intOne << std::endl;
	std::cout << "rSomeRef: " << rSomeRef << std::endl;

	std::cout << "&intOne: " << &intOne << std::endl;
	std::cout << "&rSomeRef: " << &rSomeRef << std::endl;
	return 0;
}