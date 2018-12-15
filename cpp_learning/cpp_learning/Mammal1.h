#pragma once
#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB};

class Mammal {
public:
	Mammal();
	~Mammal();

	int getAge() const;
	void setGae(int);
	int geiWeight() const;
	void setWeight(int);

	void speak();
	void sleep();

protected:
	int age;
	int weight;
};

class Dog : public Mammal {
public:
	Dog();
	~Dog();

	BREED getBreed() const;
	void setBreed(BREED);

protected:
	BREED itsBreed;
};

int mf() {
	return 0;
}