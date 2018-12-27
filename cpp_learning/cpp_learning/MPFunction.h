#pragma once
#include <iostream>

class Dog
{
public:
	void speak() const { std::cout << "Woof!\n"; }
	void move() const { std::cout << "Walking to heel ...\n"; }
	void eat() const { std::cout << "Gobbling food ...\n"; }
	void growl() const { std::cout << "Grrrrr\n"; }
	void whimper() const { std::cout << "Whinning noises ...\n"; }
	void rollOver() const { std::cout << "Rolling over ...\n"; }
	void playDead() const { std::cout << "Is this the end of Little Caesar?\n"; }
};

typedef void (Dog::*PDF) () const;

int mf()
{
	const int maxFuncs = 7;
	PDF dogFunctions[maxFuncs] = { &Dog::speak, &Dog::move, &Dog::eat, &Dog::growl, &Dog::whimper, &Dog::rollOver, &Dog::playDead };

	Dog* pDog = 0;
	int method;
	bool fQuit = false;

	while (!fQuit)
	{
		std::cout << "(0) Quit (1) Speak (2) Move (3) Eat (4) Growl\n";
		std::cout << "(5) Whimper (6) Roll Over (7) Play Dead: ";
		std::cin >> method;
		if (method == 0)
		{
			fQuit = true;
			break;
		}
		else
		{
			pDog = new Dog;
			(pDog->*dogFunctions[method - 1])();
			delete pDog;
		}
		std::cout << std::endl;
	}
	return 0;
}