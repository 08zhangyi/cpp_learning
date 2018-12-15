#pragma once
#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal {
public:
	Mammal() { std::cout << "Mammal constructor ...\n"; }
	~Mammal() { std::cout << "Mammal desctructor ...\n"; }

	void speak() const { std::cout << "Mammal sound!\n"; }
	void sleep() const { std::cout << "Shhh. I'm sleeping.\n"; }

protected:
	int age;
	int weight;
};

class Dog : public Mammal {
public:
	Dog() { std::cout << "Dog constructor ...\n"; }
	~Dog() { std::cout << "Dog destructor ...\n"; }

	void wagTail() { std::cout << "Tail wagging ...\n"; }
	void begForFood() { std::cout << "Begging for fod ...\n"; }
	void speak()  const { std::cout << "Woof!\n"; }

protected:
	BREED itsBreed;
};

int mf() {
	Mammal bigAnimal;
	Dog fido;
	bigAnimal.speak();
	fido.speak();
	return 0;
}