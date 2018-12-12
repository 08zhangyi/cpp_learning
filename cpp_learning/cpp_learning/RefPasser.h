#pragma once
#include <iostream>

class SimpleCat {
public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();

	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }

private:
	int itsAge;
};

SimpleCat::SimpleCat() {
	std::cout << "Simple Cat Constructor ..." << std::endl;
	itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&) {
	std::cout << "Simple Cat Copy Constructor ..." << std::endl;
}

SimpleCat::~SimpleCat() {
	std::cout << "Simple Cat Destructor ..." << std::endl;
}

const SimpleCat& FunctionTwo(const SimpleCat& theCat);

int mf() {
	std::cout << "Making a cat ..." << std::endl;
	SimpleCat Frisky;
	std::cout << "Frisky is " << Frisky.GetAge() << " years old" << std::endl;
	int age = 5;
	Frisky.SetAge(age);
	std::cout << "Frisky is " << Frisky.GetAge() << " years old" << std::endl;
	std::cout << "Calling FunctionTwo ..." << std::endl;
	FunctionTwo(Frisky);
	std::cout << "Frisky is " << Frisky.GetAge() << " years old" << std::endl;
	return 0;
}

const SimpleCat& FunctionTwo(const SimpleCat& theCat) {
	std::cout << "Function Two. Returning ..." << std::endl;
	std::cout << "Frisky is now " << theCat.GetAge() << " years old \n";
	// theCat->SetAge(8);
	return theCat;
}