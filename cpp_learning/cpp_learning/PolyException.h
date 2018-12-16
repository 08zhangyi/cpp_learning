#pragma once
#include <iostream>

const int defaultSize = 10;

class XBoundary {};

class XSize {
public:
	XSize(int newSize):size(newSize) {}
	~XSize() {}
	virtual int getSize() { return size; }
	virtual void printError() {
		std::cout << "Size error. Received: " << size << "\n";
	}
protected:
	int size;
};

class XTooBig: public XSize {
public:
	XTooBig(int newSize) :XSize(size) {}
	virtual void printError() {
		std::cout << "Too big! Received: " << XSize::size << "\n";
	}
};

class XTooSmall : public XSize {
public:
	XTooSmall(int newSize) :XSize(size) {}
	virtual void printError() {
		std::cout << "Too small! Received: " << XSize::size << "\n";
	}
};

class XZero : public XTooSmall {
public:
	XZero(int newSize) :XTooSmall(size) {}
	virtual void printError() {
		std::cout << "Zero Received: " << XSize::size << "\n";
	}
};

class XNegative : public XSize {
public:
	XNegative(int newSize) :XSize(size) {}
	virtual void printError() {
		std::cout << "Negative! Received: " << XSize::size << "\n";
	}
};

class Array {
public:
	Array(int size = defaultSize);
	Array(const Array &rhs);
	~Array() { delete[] pType; }
	Array& operator=(const Array&);
	int& operator[](int offSet);
	const int& operator[](int offSet) const;

	int getSize() const { return size; }

	friend std::ostream& operator<<(std::ostream&, const Array&);

private:
	int *pType;
	int size;
};

Array::Array(int newSize) :size(newSize) {
	if (newSize == 0)
		throw XZero(size);
	if (newSize < 0)
		throw XNegative(size);
	if (newSize < 10)
		throw XTooSmall(size);
	if (newSize > 30000)
		throw XTooBig(size);
	pType = new int[size];
	for (int i = 0; i < size; i++)
		pType[i] = 0;
}

Array& Array::operator=(const Array &rhs) {
	if (this == &rhs)
		return *this;
	delete[] pType;
	size = rhs.getSize();
	pType = new int[size];
	for (int i = 0; i < size; i++)
		pType[i] = rhs[i];
	return *this;
}

Array::Array(const Array &rhs) {
	size = rhs.getSize();
	pType = new int[size];
	for (int i = 0; i < size; i++)
		pType[i] = rhs[i];
}

int& Array::operator[](int offSet) {
	int size = getSize();
	if (offSet >= 0 && offSet < size)
		return pType[offSet];
	throw XBoundary();
	return pType[offSet];
}

const int& Array::operator[](int offSet) const {
	int size = getSize();
	if (offSet >= 0 && offSet < size)
		return pType[offSet];
	throw XBoundary();
	return pType[offSet];
}

std::ostream& operator<<(std::ostream& output, const Array& array) {
	for (int i = 0; i < array.getSize(); i++)
		output << "[" << i << "] " << array[i] << "\n";
	return output;
}

int mf() {
	try {
		int choice;
		std::cout << "Enter the array size: ";
		std::cin >> choice;
		Array intArray(choice);
		for (int j = 0; j < 100; j++) {
			intArray[j] = j;
			std::cout << "intArray[" << j << "] OK ..." << "\n";
		}
	}
	catch (XBoundary) {
		std::cout << "Unable to process your input\n";
	}
	catch (XSize& exception) {
		exception.printError();
	}
	catch (...) {
		std::cout << "Something went wrong," << "but I've no idea what!" << "\n";
	}
	return 0;
}