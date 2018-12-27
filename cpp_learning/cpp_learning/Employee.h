#pragma once
#include "String.hpp"

class Employee
{
public:
	Employee();
	Employee(const char*, const char*, const char*, long);
	~Employee();
	Employee(const Employee&);
	Employee& operator=(const Employee&);

	const String& getFirstName() const { return firstName; }
	const String& getLastName() const { return lastName; }
	const String& getAddress() const { return address; }
	long getSalary() const { return salary; }

	void setFirstName(const String& fName) { firstName = fName; }
	void setLastName(const String& lName) { lastName = lName; }
	void setAddress(const String& newAddress) { address = newAddress; }
	void setSalary(long newSalary) { salary = newSalary; }

private:
	String firstName;
	String lastName;
	String address;
	long salary;
};

Employee::Employee(): firstName(""), lastName(""), address(""), salary(0) {}

Employee::Employee(const char* newFirstName, const char* newLastName, const char* newAddress, long newSalary) :
	firstName(newFirstName), lastName(newLastName), address(newAddress), salary(newSalary) {}

Employee::Employee(const Employee& rhs): firstName(rhs.getFirstName()), lastName(rhs.getLastName()), address(rhs.getAddress()), salary(rhs.getSalary()) {}

Employee::~Employee() {}

Employee& Employee::operator=(const Employee& rhs)
{
	if (this == &rhs)
		return *this;
	firstName = rhs.getFirstName();
	lastName = rhs.getLastName();
	address = rhs.getAddress();
	salary = rhs.getSalary();
	return *this;
}

int mf()
{
	Employee snett("Silver", "Burdett", "800 East 96th St.", 20000);
	snett.setSalary(50000);
	String lastName("Snett");
	snett.setLastName(lastName);
	snett.setFirstName("Sam");

	std::cout << "Name: ";
	std::cout << snett.getFirstName().getString();
	std::cout << " " << snett.getLastName().getString();
	std::cout << ".\nAddress: ";
	std::cout << snett.getAddress().getString();
	std::cout << ".\nSalary: ";
	std::cout << snett.getSalary() << "\n";
	return 0;
}