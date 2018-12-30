#pragma once
#include <math.h>
#include <iostream>

double futures_value(const double& S, const double& K, const double& r, const double& time_to_maturity)
{
	return S - K * exp(-r * time_to_maturity);
}

double futures_price(const double& S, const double& r, const double& time_to_maturity)
{
	return S * exp(r*time_to_maturity);
}

int mf()
{
	double S = 930;
	double K = 950;
	double r = 0.06;
	double time_to_maturity = 0.5;

	std::cout << "远期的价值：" << futures_value(S, K, r, time_to_maturity) << std::endl;
	std::cout << "远期的价格：" << futures_price(S, r, time_to_maturity) << std::endl;

	return 0;
}