#pragma once
#include <iostream>

int mf() {
	int myAge;
	int *pAge = nullptr;

	myAge = 5;
	pAge = &myAge;
	std::cout << "myAge: " << myAge << "\n";
	std::cout << "*pAge: " << *pAge << "\n\n";

	std::cout << "*pAge = 7\n";
	*pAge = 7;
	std::cout << "*pAge: " << *pAge << "\n";
	std::cout << "myAge: " << myAge << "\n\n";

	std::cout << "myAge = 9\n";
	myAge = 9;
	std::cout << "myAge: " << myAge << "\n";
	std::cout << "*pAge: " << *pAge << "\n";
	
	// ¶àÖØÖ¸Õë
	int ** a = nullptr;
	int *b = nullptr;
	int c = 5;
	b = &c;
	a = &b;
	std::cout << **a << "\n";
	return 0;
}