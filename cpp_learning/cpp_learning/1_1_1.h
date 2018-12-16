#pragma once
#include <iostream>

double simple_interest_discrete(const double& times, const double& r)
{
	double a_t = 1.0;
	a_t = (1.0 + r * times);
	return a_t;
}