#pragma once
#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal {
public:
	void move() const { std::cout << "Mammal moves one step\n"; }
	void move(int distance) const { std::cout << "Mammal moves " << distance << " steps\n"; }

protected:
	int age;
	int weight;
};

class Dog : public Mammal {
public:
	void move() const;
};

void Dog::move() const {
	std::cout << "Dog moves ...\n";
	Mammal::move(3);
}

int mf() {
	Mammal bigAnimal;
	Dog fido;
	bigAnimal.move();
	bigAnimal.move(2);
	fido.Mammal::move(6);
	return 0;
}