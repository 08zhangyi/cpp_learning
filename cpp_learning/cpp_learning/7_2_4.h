#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

double bond_option_price_call_future_black_scholes(const double& F, const double& X,
	const double& R, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double d1 = (log(F / X) + (R + 0.5*sigma_sqr)*time) / (sigma*time_sqrt);
	double d2 = d1 - sigma * time_sqrt;
	double c = exp(-R * time)*(F*N(d1) - X * N(d2));
	return c;
}

double bond_option_price_put_future_black_scholes(const double& F, const double& X,
	const double& R, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double d1 = (log(F / X) + (R + 0.5*sigma_sqr)*time) / (sigma*time_sqrt);
	double d2 = d1 - sigma * time_sqrt;
	double c = exp(-R * time)*(X * N(-d2) - F * N(-d1));
	return c;
}

int mf()
{
	double F = 95;
	double X = 98;
	double R = 0.11;
	double sigma = 0.025;
	double time = 3.0;

	std::cout << "债券看涨期权的价格：" << bond_option_price_call_future_black_scholes(F, X, R, sigma, time) << std::endl;
	return 0;
}