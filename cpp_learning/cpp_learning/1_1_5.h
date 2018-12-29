#pragma once
#include <math.h>
#include <iostream>

double actual_rate_discrete(const double& interest_times, const double& r)
{
	double actual_rate = 0.0;
	actual_rate = pow(1.0 + r / interest_times, interest_times) - 1;
	return actual_rate;
}

int mf()
{
	double r = 0.08;
	double interest_times_1 = 2;
	double interest_times_2 = 4;

	std::cout << "实际利率 1：";
	std::cout << 100 * actual_rate_discrete(interest_times_1, r) << std::endl;

	std::cout << "实际利率 2：";
	std::cout << 100 * actual_rate_discrete(interest_times_2, r) << std::endl;
	return 0;
}