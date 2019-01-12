#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

double bond_option_price_call_zero_black_scholes(const double& B, const double& X,
	const double& R, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double d1 = (log(B / X) + (R + 0.5*sigma_sqr)*time) / (sigma*time_sqrt);
	double d2 = d1 - sigma * time_sqrt;
	double c = B * N(d1) - X * exp(-R * time) * N(d2);
	return c;
}

double bond_option_price_put_zero_black_scholes(const double& B, const double& X,
	const double& R, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double d1 = (log(B / X) + (R + 0.5*sigma_sqr)*time) / (sigma*time_sqrt);
	double d2 = d1 - sigma * time_sqrt;
	double c = X * exp(-R * time) * N(-d2) - B * N(-d1);
	return c;
}

int mf()
{
	double B = 864.55;
	double X = 1000;
	double R = 0.1;
	double sigma = 0.09;
	double time = 0.8333;

	std::cout << "零息债券看涨期权的价格：" << bond_option_price_call_zero_black_scholes(B, X, R, sigma, time) << std::endl;
	std::cout << "零息债券看跌期权的价格：" << bond_option_price_put_zero_black_scholes(B, X, R, sigma, time) << std::endl;
	return 0;
}