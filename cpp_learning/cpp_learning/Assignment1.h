#pragma once
#include <iostream>

class Tricycle1 {
public:
	Tricycle1();
	int getSpeed() const { return *speed;  }
	void setSpeed(int newSpeed) { *speed = newSpeed; }
	Tricycle1 operator=(const Tricycle1&);
private:
	int *speed;
};

Tricycle1::Tricycle1() {
	speed = new int;
	*speed = 5;
}

Tricycle1 Tricycle1::operator=(const Tricycle1& rhs) {
	if (this == &rhs)
		return *this;
	delete speed;
	speed = new int;
	*speed = rhs.getSpeed();
	return *this;
}

int mf() {
	Tricycle1 wichita;
	std::cout << "Wichita's speed: " << wichita.getSpeed() << std::endl;
	std::cout << "Setting Wichita's speed to 6 ..." << std::endl;
	wichita.setSpeed(6);
	Tricycle1 dallas;
	std::cout << "Dallas's speed: " << dallas.getSpeed() << std::endl;
	std::cout << "Copying Wichita to Dallas ..." << std::endl;
	wichita = dallas;
	std::cout << "Dallas's speed: " << dallas.getSpeed() << std::endl;
	return 0;
}