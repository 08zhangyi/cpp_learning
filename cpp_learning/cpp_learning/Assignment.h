#pragma once
#include <iostream>

int mf() {
	int intOne;
	int &rSomeRef = intOne;

	intOne = 5;
	std::cout << "intOne:\t" << intOne << std::endl;
	std::cout << "rSomeRef:\t" << rSomeRef << std::endl;
	std::cout << "&intOne:\t" << &intOne << std::endl;
	std::cout << "&rSomeRef:\t" << &rSomeRef << std::endl;

	int intTwo = 8;
	rSomeRef = intTwo;
	std::cout << "\nintOne:\t" << intOne << std::endl;
	std::cout << "intTwo:\t" << intTwo << std::endl;
	std::cout << "rSomeRef:\t" << rSomeRef << std::endl;
	std::cout << "&intOne:\t" << &intOne << std::endl;
	std::cout << "&intTwo:\t" << &intTwo << std::endl;
	std::cout << "&rSomeRef:\t" << &rSomeRef << std::endl;

	return 0;
}