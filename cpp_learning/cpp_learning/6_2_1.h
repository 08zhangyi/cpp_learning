#pragma once
#include <math.h>
#include <vector>
#include <iostream>
#include "normdist.h"

using namespace std;

double option_price_call_black_scholes(const double& S, const double& X, const double& r, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	double c = S * N(d1) - X * exp(-r * time)*N(d2);
	return c;
}

double max(double x, double y)
{
	if (x > y)
		return x;
	else
		return y;
}

double option_price_call_european_binomial(const double& S, const double& X, const double& r,
	const double& sigma, const double& time, const int& steps)
{
	double R = exp(r*(time / steps));
	double Rinv = 1.0 / R;
	double u = exp(sigma*sqrt(time / steps));
	double uu = u * u;
	double d = 1.0 / u;
	double p_up = (R - d) / (u - d);
	double p_down = 1.0 - p_up;
	vector<double> prices(steps + 1);
	prices[0] = S * pow(d, steps);
	for (int i = 1; i <= steps; ++i)
		prices[i] = uu * prices[i - 1];
	vector<double> call_values(steps + 1);
	for (int j = 0; j <= steps; j++)
		call_values[j] = max(0.0, (prices[j] - X));
	for (int step = steps - 1; step >= 0; --step)
	{
		for (int i = 0; i <= step; ++i)
		{
			call_values[i] = (p_up * call_values[i + 1] + p_down * call_values[i]) * Rinv;
		}
	}
	return call_values[0];
}

int mf()
{
	double S = 100;
	double X = 100;
	double r = 0.025;
	double sigma = 0.25;
	double time = 1;
	int steps = 100;
	cout << "Black-Scholes期权定价公式的结果：" << option_price_call_black_scholes(S, X, r, sigma, time) << endl;
	cout << "二叉树法的结果：" << option_price_call_european_binomial(S, X, r, sigma, time, steps) << endl;
	return 0;
}