#pragma once
#include <iostream>
#include <string.h>

class String
{
public:
	String();
	String(const char* const);
	String(const String&);
	~String();

	char& operator[](int offset);
	char operator[](int offset) const;
	String operator+(const String&);
	void operator+=(const String&);
	String& operator=(const String&);

	int getLen() const { return len; }
	const char* getString() const { return value; }

private:
	String(int);
	char* value;
	int len;
};

String::String()
{
	value = new char[1];
	value[0] = '\0';
	len = 0;
}

String::String(int len)
{
	value = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		value[i] = '\0';
	len = len;
}

String::String(const char* const cString)
{
	len = strlen(cString);
	value = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		value[i] = cString[i];
	value[len] = '\0';
}

String::String(const String& rhs)
{
	len = rhs.getLen();
	value = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		value[i] = rhs[i];
	value[len] = '\0';
}

String::~String()
{
	delete[] value;
	len = 0;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;
	delete[] value;
	len = rhs.getLen();
	value = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		value[i] = rhs[i];
	value[len] = '\0';
	return *this;
}

char& String::operator[](int offset)
{
	if (offset > len)
		return value[len - 1];
	else
		return value[offset];
}

char String::operator[](int offset) const
{
	if (offset > len)
		return value[len - 1];
	else
		return value[offset];
}

String String::operator+(const String& rhs)
{
	int totalLen = len + rhs.getLen();
	int i, j;
	String temp(totalLen);
	for (i = 0; i < len; i++)
		temp[i] = value[i];
	for (j = 0; j < rhs.getLen(); j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	return temp;
}

void String::operator+=(const String& rhs)
{
	int rhsLen = rhs.getLen();
	int totalLen = len + rhs.getLen();
	int i, j;
	String temp(totalLen);
	for (i = 0; i < len; i++)
		temp[i] = value[i];
	for (j = 0; j < rhs.getLen(); j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	*this = temp;
}