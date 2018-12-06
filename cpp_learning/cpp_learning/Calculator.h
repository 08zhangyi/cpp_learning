#pragma once
#include <iostream>

int add(int x, int y) {
	// add the numbers x and y together and return the sum
	std::cout << "Running calculator ...\n";
	return (x + y);
}

int mf() {
	/* this program calls an add() function to add two different
	   sets of numbers together and display the results. The
	   add() function doesn't do anything unless it is called by
	   a line in the main() function. */
	std::cout << "What is 876 + 5309?\n";
	std::cout << "The sum is " << add(867, 5309) << "\n\n";
	std::cout << "What is 777 + 9311?\n";
	std::cout << "The sum is " << add(777, 9311) << "\n";
	return 0;
}