#pragma once
#include <math.h>
#include <iostream>

double futures_value_payed_cash_dividend(const double& S, const double& K, const double& r, const double& q, const double& time_to_maturity)
{
	return S * exp(-q * time_to_maturity) - K * exp(-r * time_to_maturity);
}

double futures_price_payed_cash_dividend(const double& S, const double& r, const double& q, const double& time_to_maturity)
{
	return S * exp((r - q) * time_to_maturity);
}

int mf()
{
	double S = 25;
	double K = 27;
	double r = 0.1;
	double q = 0.04;
	double time_to_maturity = 0.5;

	std::cout << "远期的价值：" << futures_value_payed_cash_dividend(S, K, r, q, time_to_maturity) << std::endl;
	std::cout << "远期的价格：" << futures_price_payed_cash_dividend(S, r, q, time_to_maturity) << std::endl;
	return 0;
}