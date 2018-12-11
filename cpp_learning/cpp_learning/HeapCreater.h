#pragma once
#include <iostream>

class SimpleCat {
public:
	SimpleCat();
	~SimpleCat();
private:
	int itsAge;
};

SimpleCat::SimpleCat() {
	std::cout << "Constructor called\n";
	itsAge = 1;
}

SimpleCat::~SimpleCat() {
	std::cout << "Destructor called\n";
}

int mf() {
	std::cout << "SimpleCat Frisky ...\n";
	SimpleCat Frisky;

	std::cout << "SimpleCar *pRags = new SimpleCat ...\n";
	SimpleCat *pRags = new SimpleCat;

	std::cout << "delete pRags ...\n";
	delete pRags;

	std::cout << "Exiting, watch Frisky go ...\n";
	return 0;
}