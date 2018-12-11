#pragma once
#include <iostream>
namespace this_ns {

	class Rectangle {
	public:
		Rectangle();
		~Rectangle();
		void SetLength(int length) { this->itsLength = length; }
		int GetLength() const { return this->itsLength; }
		void SetWidth(int width) { this->itsWidth = width; }
		int GetWidth() const { return this->itsWidth; }
	private:
		int itsLength;
		int itsWidth;
	};

	Rectangle::Rectangle() {
		itsWidth = 5;
		itsLength = 10;
	}

	Rectangle::~Rectangle() {
	}

	int mf() {
		Rectangle theRect;
		std::cout << "theRect is " << theRect.GetLength() << " feet long." << std::endl;
		std::cout << "theRect is " << theRect.GetWidth() << " feet wide." << std::endl;
		theRect.SetLength(20);
		theRect.SetWidth(10);
		std::cout << "theRect is " << theRect.GetLength() << " feet long." << std::endl;
		std::cout << "theRect is " << theRect.GetWidth() << " feet wide." << std::endl;
		return 0;
	}
}