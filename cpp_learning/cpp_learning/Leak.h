#pragma once
#include <iostream>

class SimpleCat {
public:
	SimpleCat(int age, int weight);
	~SimpleCat() {};

	int GetAge() { return itsAge; }
	int GetWeight() { return itsWeight; }

private:
	int itsAge;
	int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight) :itsAge(age), itsWeight(weight) {}

SimpleCat& TheFunction();

int mf() {
	SimpleCat& rCat = TheFunction();
	int age = rCat.GetAge();
	std::cout << "rCat is " << age << " years old!" << std::endl;
	std::cout << "&rCat: " << &rCat << std::endl;
	SimpleCat *pCat = &rCat;
	delete pCat;
	return 0;
}

SimpleCat& TheFunction() {
	SimpleCat *pFrisky = new SimpleCat(5, 9);
	std::cout << "pFirsky: " << pFrisky << std::endl;
	return *pFrisky;
}