#pragma once
#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal {
public:
	Mammal() : age(2), weight(5) {}
	~Mammal() {}

	int getAge() const { return age; }
	void setAge(int newAge) { age = newAge; }
	int geiWeight() const { return weight; }
	void setWeight(int newWeight) { weight = newWeight; }

	void speak() const { std::cout << "Mammal sound!\n"; }
	void sleep() const { std::cout << "Shhh. I'm sleeping.\n"; }

protected:
	int age;
	int weight;
};

class Dog : public Mammal {
public:
	Dog() : breed(YORKIE) {}
	~Dog() {}

	BREED getBreed() const { return breed; }
	void setBreed(BREED newBreed) { breed = newBreed; }

	void wagTail() { std::cout << "Tail wagging ...\n"; }
	void begForFood() { std::cout << "Begging for fod ...\n"; }

protected:
	BREED breed;
};

int mf() {
	Dog fido;
	fido.speak();
	fido.wagTail();
	std::cout << "Fido is " << fido.getAge() << " years old\n";
	return 0;
}