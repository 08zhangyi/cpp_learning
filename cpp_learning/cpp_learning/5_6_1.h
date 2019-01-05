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

double option_price_implied_volatility_call_black_scholes_bisections(const double& S,
	const double& X, const double& r, const double& time, const double& option_price)
{
	const double ACCURACY = 1.0e-5;
	const int MAX_ITERATIONS = 100;
	const double ERROR = -1e40;

	double sigma_low = 1e-5;
	double sigma_high = 0.3;

	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		double sigma = (sigma_low + sigma_high) * 0.5;
		double price = option_price_call_black_scholes(S, X, r, sigma, time);
		double test = (price - option_price);
		if (fabs(test) < ACCURACY)
			return sigma;
		if (test < 0.0)
			sigma_low = sigma;
		else
			sigma_high = sigma;
	}
	return ERROR;
}

int mf()
{
	double S = 21;
	double X = 20;
	double r = 0.10;
	double time = 0.25;
	double c = 1.875;

	std::cout << "Òþº¬²¨¶¯ÂÊ£º";
	std::cout << option_price_implied_volatility_call_black_scholes_bisections(S, X, r, time, c) << std::endl;
	return 0;
}