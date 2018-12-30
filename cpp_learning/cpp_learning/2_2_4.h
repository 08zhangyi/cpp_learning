#pragma once
#include <math.h>
#include <iostream>

double futures_price_for_discount_instrument(const double& V, const double& r1, const double& r2, const double& time_to_maturity1, const double& time_to_maturity2, const double& time_to_maturity)
{
	double r = (r1 * time_to_maturity1 - r2 * time_to_maturity2) / time_to_maturity;
	return V * exp(-r * time_to_maturity / 365);
}

int mf()
{
	double V = 100;
	double r1 = 0.0825;
	double time_to_maturity1 = 230;
	double r2 = 0.08;
	double time_to_maturity2 = 140;
	double time_to_maturity = 90;

	std::cout << "短期国债期货的价格：" << futures_price_for_discount_instrument(V, r1, r2, time_to_maturity1, time_to_maturity2, time_to_maturity) << std::endl;
	return 0;
}