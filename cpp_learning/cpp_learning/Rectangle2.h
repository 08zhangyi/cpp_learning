#pragma once
#include <iostream>

class RectangleAll {
public:
	RectangleAll(int width, int height);
	~RectangleAll() {}
	void drawShape(int width, int height, bool useCurrentValue = false) const;

private:
	int width;
	int height;
};

RectangleAll::RectangleAll(int aWidth, int aHeight) {
	width = aWidth;
	height = aHeight;
}

void RectangleAll::drawShape(int aWidth, int aHeight, bool useCurrentValue) const {
	int printWidth;
	int printHeight;

	if (useCurrentValue == true) {
		printWidth = width;
		printHeight = height;
	}
	else {
		printWidth = aWidth;
		printHeight = aHeight;
	}
	for (int i = 0; i < printHeight; i++) {
		for (int j = 0; j < printWidth; j++)
			std::cout << "*";
		std::cout << std::endl;
	}
}

int mf() {
	RectangleAll box(20, 5);
	std::cout << "dwarShape(0, 0, true):" << std::endl;
	box.drawShape(0, 0, true);
	std::cout << "\ndrawShape(25, 4):" << std::endl;
	box.drawShape(25, 4);
	return 0;
}