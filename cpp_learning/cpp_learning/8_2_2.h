#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

using namespace std;

double option_price_asian_arithmetic_average_price_call(const double& Save, const double& X, const double& r,
	const double& q, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double m1 = Save * (exp((r - q)*time) - 1) / ((r - q)*time);
	double m2 = Save * Save * (2 * exp((2 * (r - q) + sigma_sqr)*time)) / ((r - q + sigma_sqr)*(2 * r - 2 * q + sigma_sqr)*time*time) +
		2 * Save*Save / ((r - q)*time*time)*(1 / (2 * (r - q) + sigma_sqr) - exp((r - q)*time) / (r - q + sigma_sqr));
	double F = m1;
	double sigma_a = 1 / time * log(m2 / (m1*m1));
	double d1 = (log(F / X) + (0.5*sigma_a*sigma_a)*time) / (sqrt(sigma_a)*time_sqrt);
	double d2 = d1 - sqrt(sigma_a)*time_sqrt;
	double c = exp(-r * time)*(F*N(d1) - X * N(d2));
	return c;
}

int mf()
{
	double S = 100.0;
	double X = 30.0;
	double r = 0.05;
	double q = 0.03;
	double sigma = 0.3;
	double time = 1;

	cout << "看涨期权的价格：" << option_price_asian_arithmetic_average_price_call(S, X, r, q, sigma, time) << endl;
	return 0;
}