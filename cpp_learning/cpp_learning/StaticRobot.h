#pragma once
#include <iostream>

class Robot
{
public:
	Robot(int newAge = 1) : age(newAge) { howManyRobots++; }
	virtual ~Robot() { howManyRobots--; }
	virtual int getAge() { return age; }
	virtual void setAge(int newAge) { age = newAge; }
	static int howManyRobots;

private:
	int age;
};

int Robot::howManyRobots = 0;

int mf()
{
	const int maxRobots = 5;
	Robot* gestalt[maxRobots];
	int i;
	for (i = 0; i < maxRobots; i++)
		gestalt[i] = new Robot(i);

	for (i = 0; i < maxRobots; i++)
	{
		std::cout << "There are ";
		std::cout << Robot::howManyRobots;
		std::cout << " robots left!\n";
		std::cout << "Deleting the one which is ";
		std::cout << gestalt[i]->getAge();
		std::cout << " years old\n";
		delete gestalt[i];
		gestalt[i] = 0;
	}
	return 0;
}