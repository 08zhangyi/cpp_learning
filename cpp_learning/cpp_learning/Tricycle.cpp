#include "Tricycle.hpp"

Tricycle::Tricycle(int initialSpeed) {
	setSpeed(initialSpeed);
}

Tricycle::~Tricycle() {
	// do nothing
}

void Tricycle::setSpeed(int newSpeed) {
	if (newSpeed >= 0)
		speed = newSpeed;
}

int tricycle_ns::mf() {
	Tricycle wichita(5);
	wichita.pedal();
	wichita.pedal();
	wichita.brake();
	wichita.brake();
	wichita.brake();
	return 0;
}