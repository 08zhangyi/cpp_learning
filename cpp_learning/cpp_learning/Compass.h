#pragma once
#include <iostream>

int mf() {
	enum Direction {North, Northeast, East, Southeast, South, Southwest, West, Northwest};
	Direction heading;
	heading = Southeast;
	std::cout << "Moving " << heading << std::endl;
	return 0;
}