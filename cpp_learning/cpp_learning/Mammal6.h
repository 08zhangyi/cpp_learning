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
	void move() const { std::cout << "Dog moves 5 steps\n"; }
};

int mf() {
	Mammal bigAnimal;
	Dog fido;
	bigAnimal.move();
	bigAnimal.move(2);
	fido.move();
	// fido.move(10);
	return 0;
}