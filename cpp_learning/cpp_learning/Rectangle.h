#pragma once
#include <iostream>

class RectangleAll {
public:
	RectangleAll(int width, int height);
	~RectangleAll() {}

	void drawShape() const;
	void drawShape(int width, int height) const;

private:
	int width;
	int height;
};

RectangleAll::RectangleAll(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
}

void RectangleAll::drawShape() const {
	drawShape(width, height);
}

void RectangleAll::drawShape(int width, int height) const {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			std::cout << "*";
		std::cout << std::endl;
	}
}

int mf() {
	RectangleAll box(30, 5);
	std::cout << "dwarShape():" << std::endl;
	box.drawShape();
	std::cout << "\ndrawShape(40, 2):" << std::endl;
	box.drawShape(40, 2);
	return 0;
}