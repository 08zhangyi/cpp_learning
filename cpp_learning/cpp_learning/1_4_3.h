#pragma once
#include <iostream>

double H_model(const double& D0, const double& g0, const double& g, const double& r, const double &H)
{
	double value = 0.0;
	value = D0 * ((1 + g) + H * (g0 - g)) / (r - g);
	return value;
}

int mf()
{
	double D0 = 1;
	double g0 = 0.06;
	double g = 0.03;
	double r = 0.08;
	double H = 4.0;

	std::cout << "¹ÉÆ±¼Û¸ñ£º" << H_model(D0, g0, g, r, H) << std::endl;
	return 0;
}