#pragma once
#include <iostream>

int mf() {
	char name[50];
	char quest[80];
	char velocity[80];

	std::cout << "\nWhat is your name? ";
	std::cin.getline(name, 49);
	std::cout << "\nWhat is your quest? ";
	std::cin.getline(quest, 79);
	std::cout << "\nWhat is the velocity of an unladen swallow? ";
	std::cin.getline(velocity, 79);

	std::cout << "\nName: " << name << std::endl;
	std::cout << "Quest: " << quest << std::endl;
	std::cout << "Velocity: " << velocity << std::endl;
	return 0;
}