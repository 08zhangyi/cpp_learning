#pragma once
#include <iostream>

class Mammal {
public:
	Mammal() :age(1) {}
	~Mammal() {}
	virtual void speak() const { std::cout << "Mammal speal!\n"; }

protected:
	int age;
};

class Dog : public Mammal {
public:
	void speak() const { std::cout << "Woof!\n"; }
};

class Cat : public Mammal {
public:
	void speak() const { std::cout << "Meow!\n"; }
};

void valueFunction(Mammal);
void ptrFunction(Mammal*);
void refFunctionabc(Mammal&);

int mf() {
	Mammal* ptr = nullptr;
	int choice;
	while (true) {
		bool fQuit = false;
		std::cout << "(1) dog (2) cat (0) quit: ";
		std::cin >> choice;
		switch (choice) {
		case 0:
			fQuit = true;
			break;
		case 1:
			ptr = new Dog;
			break;
		case 2:
			ptr = new Cat;
			break;
		default:
			ptr = new Mammal;
			break;
		}
		if (fQuit) {
			break;
		}
		ptrFunction(ptr);
		refFunctionabc(*ptr);
		valueFunction(*ptr);
	}
	return 0;
}

void valueFunction(Mammal mammalValue) {
	mammalValue.speak();
}

void ptrFunction(Mammal* pMammal) {
	pMammal->speak();
}

void refFunctionabc(Mammal& rMammal) {
	rMammal.speak();
}