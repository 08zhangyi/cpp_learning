#pragma once
#include <math.h>
#include <iostream>

double compound_interest_fv_discrete(const double& times, const double& amounts, const double& r)
{
	double FV = 1.0;
	FV = amounts * pow(1.0 + r, times);
	return FV;
}

int mf()
{
	double r = 0.08;
	double times = 10;
	double amounts = 100;
	std::cout << "¸´ÀûÖÕÖµ£º";
	std::cout << compound_interest_fv_discrete(times, amounts, r) << std::endl;
	return 0;
}