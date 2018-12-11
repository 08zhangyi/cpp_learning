#pragma once
#include <iostream>

int mf() {
	int localVariable = 5;
	int *pLocal = &localVariable;
	int *pHeap = new int;
	if(pHeap == nullptr) {
		std::cout << "Error! No memory for pHeap!!";
		return 1;
	}
	*pHeap = 7;
	std::cout << "localVariable: " << localVariable << "\n";
	std::cout << "*pLocal: " << *pLocal << "\n";
	std::cout << "*pHeap: " << *pHeap << "\n";
	delete pHeap;
	pHeap = new int;
	if (pHeap == nullptr) {
		std::cout << "Error! No memory for pHeap!!";
		return 1;
	}
	*pHeap = 9;
	std::cout << "*pHeap: " << *pHeap << "\n";
	delete pHeap;
	return 0;
}