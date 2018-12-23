#pragma once
#include <iostream>
#include <math.h>

double simple_interest_discrete(const double& times, const double& r)
{
	double a_t = 1.0;
	a_t = (1.0 + r * times);
	return a_t;
}

double compound_interest_discrete(const double& times, const double& r)
{
	double a_t = 1.0;
	a_t = pow(1 + r, times);
	return a_t;
}

int mf()
{
	double r = 0.05;
	double times = 10;
	std::cout << "单利计息：";
	std::cout << simple_interest_discrete(times, r) << std::endl;
	std::cout << "复利计息：";
	std::cout << compound_interest_discrete(times, r) << std::endl;
	return 0;
}