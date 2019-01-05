#pragma once
#include "normdist.h"
#include <math.h>
#include <iostream>

double option_price_call_black_scholes(const double& S, const double& X, const double& r, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	double c = S * N(d1) - X * exp(-r * time)*N(d2);
	return c;
}

double option_price_implied_volatility_call_black_scholes_newton(const double& S,
	const double& X, const double& r, const double& time, const double& option_price)
{
	const int MAX_ITERATIONS = 100;
	const double ACCURACY = 1.0e-4;
	double time_qrt = sqrt(time);
	double sigma = (option_price / S) / (0.398 * time_qrt);

	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		double price = option_price_call_black_scholes(S, X, r, sigma, time);
		double diff = option_price - price;
		if (fabs(diff) < ACCURACY)
			return sigma;
		double d1 = (log(S / X) + r * time) / (sigma*time_qrt) + 0.5*sigma*time_qrt;
		double vega = S * time_qrt * n(d1);
		sigma = sigma + diff / vega;
	}
	return -99e10;
}

int mf()
{
	double S = 21;
	double X = 20;
	double r = 0.10;
	double time = 0.25;
	double c = 1.875;

	std::cout << "Òþº¬²¨¶¯ÂÊ£º";
	std::cout << option_price_implied_volatility_call_black_scholes_newton(S, X, r, time, c) << std::endl;
	return 0;
}