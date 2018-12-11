#pragma once
#include <iostream>

class SimpleCat {
public:
	SimpleCat();
	~SimpleCat();
	int GetAge() const { return *itsAge;  }
	void SetAge(int age) { *itsAge = age; }
	int GetWeight() const { return *itsWeight; }
	void SetWeight(int weight) { *itsWeight = weight; }
private:
	int *itsAge;
	int *itsWeight;
};

SimpleCat::SimpleCat() {
	itsAge = new int(2);
	itsWeight = new int(5);
}

SimpleCat::~SimpleCat() {
	delete itsAge;
	delete itsWeight;
}

int mf() {
	SimpleCat *Frisky = new SimpleCat;
	std::cout << "Frisky is " << Frisky->GetAge() << " years old" << std::endl;
	Frisky->SetAge(5);
	std::cout << "Frisky is " << Frisky->GetAge() << " years old" << std::endl;
	delete Frisky;
	return 0;
}