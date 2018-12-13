#pragma once
#include <iostream>

class TricycleAll {
public:
	TricycleAll();
	TricycleAll(const TricycleAll&);
	~TricycleAll();
	int getSpeed() const { return *speed;  }
	void setSpeed(int newSpeed) { *speed = newSpeed; }
	void pedal();
	void brake();
private:
	int *speed;
};

TricycleAll::TricycleAll() {
	speed = new int;
	*speed = 5;
}

TricycleAll::TricycleAll(const TricycleAll& rhs) {
	speed = new int;
	*speed = rhs.getSpeed();
}

TricycleAll::~TricycleAll() {
	delete speed;
	speed = nullptr;
}

void TricycleAll::pedal() {
	setSpeed(*speed + 1);
	std::cout << "\nPedaling " << getSpeed() << " mph" << std::endl;
}

void TricycleAll::brake() {
	setSpeed(*speed - 1);
	std::cout << "\nPedaling " << getSpeed() << " mph" << std::endl;
}

int mf() {
	std::cout << "Creating trike named wichita ...";
	TricycleAll wichita;
	wichita.pedal();
	std::cout << "Creating trike named dallas ..." << std::endl;
	TricycleAll dallas = wichita;
	std::cout << "wichita's speed: " << wichita.getSpeed() << std::endl;
	std::cout << "dallas's speed: " << dallas.getSpeed() << std::endl;
	std::cout << "setting wichita to 10 ..." << std::endl;
	wichita.setSpeed(10);
	std::cout << "wichita's speed: " << wichita.getSpeed() << std::endl;
	std::cout << "dallas's speed: " << dallas.getSpeed() << std::endl;
	return 0;
}