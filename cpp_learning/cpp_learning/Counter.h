#pragma once
#include <iostream>

class Counter {
public:
	Counter();
	~Counter() {}
	int getValue() const { return value;  }
	void setValue(int x) { value = x;  }
private:
	int value;
};

Counter::Counter(): value(0) {}

int mf() {
	Counter c;
	std::cout << "The value of c is " << c.getValue() << std::endl;
	return 0;
}