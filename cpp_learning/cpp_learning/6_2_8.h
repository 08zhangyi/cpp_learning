#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

double futures_option_price_call_american_binomial(const double& S, const double& X, const double& r,
	const double& sigma, const double& time, const int& no_steps)
{
	vector<double> futures_prices(no_steps + 1);
	vector<double> call_values(no_steps + 1);
	double t_delta = time / no_steps;
	double Rinv = exp(-r * (t_delta));
	double u = exp(sigma*sqrt(t_delta));
	double d = 1.0 / u;
	double uu = u * u;
	double pUp = (1 - d) / (u - d);
	double pDown = 1.0 - pUp;
	futures_prices[0] = S * pow(d, no_steps);
	int i;
	for (i = 1; i <= no_steps; ++i)
		futures_prices[i] = uu * futures_prices[i - 1];
	for (i = 0; i <= no_steps; ++i)
		call_values[i] = max(0.0, (futures_prices[i] - X));
	for (int step = no_steps - 1; step >= 0; --step)
	{
		for (i = 0; i <= step; ++i)
		{
			futures_prices[i] = d * futures_prices[i + 1];
			call_values[i] = (pDown * call_values[i] + pUp * call_values[i + 1])*Rinv;
			call_values[i] = max(call_values[i], futures_prices[i] - X);
		}
	}
	return call_values[0];
}

int mf()
{
	double F = 50.0;
	double X = 45.0;
	double r = 0.08;
	double sigma = 0.2;
	double time = 0.5;
	int no_steps = 100;
	cout << "指数美式期权的价格：" << futures_option_price_call_american_binomial(F, X, r, sigma, time, no_steps) << endl;
	return 0;
}
