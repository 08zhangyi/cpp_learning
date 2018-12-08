#pragma once
#include <iostream>

int mf() {
	auto strength = 80;
	auto accuracy = 45.5;
	auto dexterity = 24.0;
	const auto MAXIMUM = 50;
	auto attack = strength * (accuracy / MAXIMUM);
	auto damage = strength * (dexterity / MAXIMUM);

	std::cout << "\nAttack rating: " << attack << "\n";
	std::cout << "Damage rating: " << damage << "\n";
	return 0;
}