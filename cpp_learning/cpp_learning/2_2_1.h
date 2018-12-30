#pragma once
#include <math.h>
#include <iostream>

double futures_value_for_foreign_exchange(const double& S, const double& r, const double& K, const double& rf, const double& time_to_maturity)
{
	return S * exp(-rf * time_to_maturity) - K * exp(-r * time_to_maturity);
}

double futures_price_for_foreign_exchange(const double& S, const double& r, const double& rf, const double& time_to_maturity)
{
	return S * exp((r - rf) * time_to_maturity);
}

int mf()
{
	double S = 100;
	double K = 99;
	double r = 0.10;
	double rf = 0.002;
	double time_to_maturity = 0.5;
	std::cout << "外汇期货价值：" << futures_value_for_foreign_exchange(S, r, K, rf, time_to_maturity) << std::endl;
	std::cout << "外汇期货价格：" << futures_price_for_foreign_exchange(S, r, rf, time_to_maturity) << std::endl;
	return 0;
}