#pragma once
#include <iostream>

float convert(float);

int mf() {
	float fahrenheit;
	float celsius;

	std::cout << "Please enter the temperature in Fahrenheit: ";
	std::cin >> fahrenheit;
	celsius = convert(fahrenheit);
	std::cout << "\nHere's the temperature in Celsius: ";
	std::cout << celsius << "\n";
	return 0;
}

float convert(float fahrenheit) {
	float celsius;
	celsius = ((fahrenheit - 32) * 5) / 9;
	return celsius;
}