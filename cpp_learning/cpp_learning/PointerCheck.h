#pragma once
#include <iostream>

int mf() {
	unsigned short int myAge = 5, yourAge = 10;
	unsigned short int *pAge = &myAge;

	std::cout << "myAge:\t" << myAge;
	std::cout << "\t\tyourAge:\t" << yourAge << "\n";
	std::cout << "&myAge:\t" << &myAge;
	std::cout << "\t&yourAge:\t" << &yourAge << "\n";

	std::cout << "pAge:\t" << pAge << "\n";
	std::cout << "*pAGe:\t" << *pAge << "\n";

	pAge = &yourAge;

	std::cout << "myAge:\t" << myAge;
	std::cout << "\t\tyourAge:\t" << yourAge << "\n";
	std::cout << "&myAge:\t" << &myAge;
	std::cout << "\t&yourAge:\t" << &yourAge << "\n";

	std::cout << "pAge:\t" << pAge << "\n";
	std::cout << "*pAGe:\t" << *pAge << "\n";

	std::cout << "&pAge:\t" << &pAge << "\n";
	return 0;
}