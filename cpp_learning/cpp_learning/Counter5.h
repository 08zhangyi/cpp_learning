#pragma once
#include <iostream>

class Counter {
public:
	Counter();
	~Counter() {}
	int getValue() const { return value; }
	void setValue(int newValue) { value = newValue;  }
private:
	int value;
};

Counter::Counter() : value(0) {}

int mf() {
	int beta = 5;
	Counter alpha = beta;
	std::cout << "alpjha: " << alpha.getValue() << std::endl;
	return 0;
}