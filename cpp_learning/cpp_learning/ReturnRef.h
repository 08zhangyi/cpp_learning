#pragma once
#include <iostream>

class SimpleCat {
public:
	SimpleCat(int age, int weight);
	~SimpleCat();

	int GetAge() const { return itsAge; }
	int GetWeight() const { return itsWeight; }

private:
	int itsAge;
	int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight):itsAge(age), itsWeight(weight) {}

SimpleCat& TheFunction();

int mf() {
	SimpleCat& rCat = TheFunction();
	int age = rCat.GetAge();
	std::cout << "rCat is " << age << " years old!" << std::endl;
	return 0;
}

SimpleCat& TheFunction() {
	SimpleCat Frisky(5, 9);
	return Frisky;
}