#pragma once
#include <iostream>
#include <string.h>

typedef unsigned long pDate;

enum SERVICE { PostMaster, Interchange, Gmail, Hotmail, AOL, Internet};

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
	friend std::ostream& operator<<(std::ostream& stream, String& newString);

	int getLen() const { return len; }
	const char* getString() const { return string; }

private:
	String(int);
	char* string;
	int len;
};

String::String()
{
	string = new char[1];
	string[0] = '\0';
	len = 0;
}

String::String(int newLen)
{
	string = new char[newLen + 1];
	int i;
	for (i = 0; i < newLen; i++)
		string[i] = '\0';
	len = newLen;
}

String::String(const char* const cString)
{
	len = strlen(cString);
	string = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		string[i] = cString[i];
	string[len] = '\0';
}

String::String(const String& rhs)
{
	len = rhs.getLen();
	string = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		string[i] = rhs[i];
	string[len] = '\0';
}

String::~String()
{
	delete[] string;
	len = 0;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;
	delete[] string;
	len = rhs.getLen();
	string = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		string[i] = rhs[i];
	string[len] = '\0';
	return *this;
}

char& String::operator[](int offset)
{
	if (offset > len)
		return string[len - 1];
	else
		return string[offset];
}

char String::operator[](int offset) const
{
	if (offset > len)
		return string[len - 1];
	else
		return string[offset];
}

String String::operator+(const String& rhs)
{
	int totalLen = len + rhs.getLen();
	String temp(totalLen);
	int i, j;
	for (i = 0; i < len; i++)
		temp[i] = string[i];
	for (j = 0; j < rhs.getLen(); j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	return temp;
}

void String::operator+=(const String& rhs)
{
	int rhsLen = rhs.getLen();
	int totalLen = len + rhsLen;
	String temp(totalLen);
	int i, j;
	for (i = 0; i < len; i++)
		temp[i] = string[i];
	for (j = 0; j < rhs.getLen(); j++, i++)
		temp[i] = rhs[i - len];
	temp[totalLen] = '\0';
	*this = temp;
}

std::ostream& operator<<(std::ostream& stream, String& newString)
{
	stream << newString.getString();
	return stream;
}

class pAddress
{
public:
	pAddress(SERVICE newService, const String& newAddress, const String& newDisplay):
		service(newService), addressString(newAddress), displayString(newDisplay) {}
	~pAddress() {}
	friend std::ostream& operator<<(std::ostream& stream, pAddress& address);
	String& getDisplayString() { return displayString; }
private:
	SERVICE service;
	String addressString;
	String displayString;
};

std::ostream& operator<<(std::ostream& stream, pAddress& address)
{
	stream << address.getDisplayString();
	return stream;
}

class PostMasterMessage
{
public:
	PostMasterMessage();
	PostMasterMessage(pAddress newSender, pAddress newRecipient, const String& newSubject, const pDate& newCreationDate);

	~PostMasterMessage() {}

	void Edit();

	pAddress& getSender() { return sender; }
	pAddress& getRecipient() { return recipient; }
	String& getSubject() { return subject; }

private:
	pAddress sender;
	pAddress recipient;
	String subject;
	pDate creationDate;
	pDate lastModDate;
	pDate receiptDate;
	pDate firstReadDate;
	pDate lastReadDate;
};

PostMasterMessage::PostMasterMessage(pAddress newSender, pAddress newRecipient, const String& newSubject, const pDate& newCreationDate) :
	sender(newSender), recipient(newRecipient), subject(newSubject), creationDate(newCreationDate), lastModDate(newCreationDate), firstReadDate(0), lastReadDate(0)
{
	std::cout << "Postmaster message created. \n";
}

void PostMasterMessage::Edit()
{
	std::cout << "Postmaster message edit function called\n";
}

int mf()
{
	pAddress sender(PostMaster, "james@ekzemplo.com", "James");
	pAddress recipient(PostMaster, "sharon@ekzemplo.com", "Sharon");

	PostMasterMessage postMasterMessage(sender, recipient, "Greetings", 0);
	std::cout << "Message review... \n";
	std::cout << "From:\t\t" << postMasterMessage.getSender() << "\n";
	std::cout << "To:\t\t" << postMasterMessage.getRecipient() << "\n";
	std::cout << "Subject:\t" << postMasterMessage.getSubject() << "\n";
	return 0;
}