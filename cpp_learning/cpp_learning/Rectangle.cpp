#include "Rectangle.hpp"

Rectangle::Rectangle(int newTop, int newLeft, int newBottom, int newRight) {
	top = newTop;
	left = newLeft;
	bottom = newBottom;
	right = newRight;
	upperLeft.setX(left);
	upperLeft.setY(top);
	upperRight.setX(right);
	upperRight.setY(top);
	lowerLeft.setX(left);
	lowerLeft.setY(bottom);
	lowerRight.setX(right);
	lowerRight.setY(bottom);
}

void Rectangle::setUpperLeft(Point location) {
	upperLeft = location;
	upperRight.setY(location.getY());
	lowerLeft.setX(location.getX());
	top = location.getY();
	left = location.getX();
}

void Rectangle::setLowerLeft(Point location) {
	lowerLeft = location;
	lowerRight.setY(location.getY());
	upperLeft.setX(location.getX());
	bottom = location.getY();
	left = location.getX();
}

void Rectangle::setLowerRight(Point location) {
	lowerRight = location;
	lowerLeft.setY(location.getY());
	upperRight.setX(location.getX());
	bottom = location.getY();
	right = location.getX();
}

void Rectangle::setUpperRight(Point location) {
	upperRight = location;
	upperLeft.setY(location.getY());
	lowerRight.setX(location.getX());
	top = location.getY();
	right = location.getX();
}

void Rectangle::setTop(int newTop) {
	top = newTop;
	upperLeft.setY(top);
	upperRight.setY(top);
}

void Rectangle::setLeft(int newLeft) {
	left = newLeft;
	upperLeft.setX(left);
	lowerLeft.setX(left);
}

void Rectangle::setBottom(int newBottom) {
	bottom = newBottom;
	lowerLeft.setY(bottom);
	lowerRight.setY(bottom);
}

void Rectangle::setRight(int newRight) {
	right = newRight;
	upperRight.setX(right);
	lowerRight.setX(right);
}

int Rectangle::getArea() const {
	int width = right - left;
	int height = top - bottom;
	return (width * height);
}

int rectangle_ns::main() {
	Rectangle myRectangle(100, 20, 50, 80);
	int area = myRectangle.getArea();
	std::cout << "Area: " << area << std::endl;
	std::cout << "Upper Left X Coordinate: ";
	std::cout << myRectangle.getUpperLeft().getX() << std::endl;
	return 0;
}