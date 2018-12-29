#pragma once
#include <math.h>
#include <iostream>

double compound_interest_pv_discrete(const double& times, const double& amounts, const double& r)
{
	double PV = 0.0;
	PV = amounts * pow(1 / (1.0 + r), times);
	return PV;
}

int mf()
{
	double r = 0.08;
	double times = 5;
	double amounts = 3000;
	std::cout << "¸´ÀûÏÖÖµ£º";
	std::cout << compound_interest_pv_discrete(times, amounts, r) << std::endl;
	return 0;
}