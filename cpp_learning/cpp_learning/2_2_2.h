#pragma once
#include <math.h>
#include <iostream>

double futures_price_for_stock_index(const double& S, const double& r, const double& rf, const double& time_to_maturity)
{
	return S * exp((r - rf) * time_to_maturity);
}

int mf()
{
	double S = 400;
	double r = 0.08;
	double rf = 0.03;
	double time_to_maturity = 0.25;
	std::cout << "外汇期货价格：" << futures_price_for_stock_index(S, r, rf, time_to_maturity) << std::endl;
	return 0;
}