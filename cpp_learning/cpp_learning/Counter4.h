#pragma once
#include <iostream>

class Counter {
public:
	Counter();
	Counter(int initialValue);
	~Counter() {}
	int getValue() const { return value; }
	void setValue(int x) { value = x; }
	Counter operator+(const Counter&);
private:
	int value;
};

Counter::Counter(int initialValue): value(initialValue){}

Counter::Counter() : value(0) {}

Counter Counter::operator+(const Counter& rhs) {
	return Counter(value + rhs.getValue());
}

int mf() {
	Counter alpha(4), beta(13), gamma;
	gamma = alpha + beta;
	std::cout << "aplha: " << alpha.getValue() << std::endl;
	std::cout << "beta: " << beta.getValue() << std::endl;
	std::cout << "gamma: " << gamma.getValue() << std::endl;
	return 0;
}