#pragma once
#include <iostream>

void convert();

float fahrenheit;
float celsius;

int mf() {
	std::cout << "Please enter the temperature in Fahrenheit: ";
	std::cin >> fahrenheit;
	convert();
	std::cout << "\nHere's the temperature in Celsius: ";
	std::cout << celsius << "\n";
	return 0;
}

void convert() {
	celsius = ((fahrenheit - 32) * 5) / 9;
}