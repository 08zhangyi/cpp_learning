#pragma once
#include <iostream>

class Tricycle {
public:
	Tricycle(int initialAge);
	~Tricycle();
	int getSpeed();
	void setSpeed(int speed);
	void pedal();
	void brake();
private:
	int speed;
};

Tricycle::Tricycle(int initialSpeed) {
	setSpeed(initialSpeed);
}

Tricycle::~Tricycle() {
	// do nothing
}

int Tricycle::getSpeed() {
	return speed;
}

void Tricycle::setSpeed(int newSpeed) {
	if (newSpeed >= 0)
		speed = newSpeed;
}

void Tricycle::pedal() {
	setSpeed(speed + 1);
	std::cout << "\nPedaling; tricycle speed " << speed << " mph\n";
}

void Tricycle::brake() {
	setSpeed(speed - 1);
	std::cout << "\nBraking; tricycle speed " << speed << " mph\n";
}

int mf() {
	Tricycle wichita = Tricycle(5);
	wichita.pedal();
	wichita.pedal();
	wichita.brake();
	wichita.brake();
	wichita.brake();
	return 0;
}