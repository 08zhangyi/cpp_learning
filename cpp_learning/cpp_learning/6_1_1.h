#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

double simulate_random_variable(const double& S, const double& r, const double& sigma, const double& time)
{
	double R = (r - 0.5 * pow(sigma, 2)) * time;
	double SD = sigma * sqrt(time);
	return S * exp(R + SD * random_normal());
}

int mf()
{
	double S = 10;
	double r = 0.01;
	double sigma = 0.3;
	double time = 0.5;

	std::cout << "下一时刻标的资产的价格：" << simulate_random_variable(S, r, sigma, time) << std::endl;
	return 0;
}