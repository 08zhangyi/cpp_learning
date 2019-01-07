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

double index_option_price_call_american_binomial(const double& S, const double& X, const double& r,
	const double& y, const double& sigma, const double& time, const int& no_steps)
{
	vector<double> Index_value(no_steps + 1);
	vector<double> call_values(no_steps + 1);
	double t_delta = time / no_steps;
	double Rinv = exp(-r * (t_delta));
	double u = exp(sigma*sqrt(t_delta));
	double d = 1.0 / u;
	double uu = u * u;
	double pUp = (exp((r - y)*t_delta) - d) / (u - d);
	double pDown = 1.0 - pUp;
	Index_value[0] = S * pow(d, no_steps);
	int i;
	for (i = 1; i <= no_steps; ++i)
		Index_value[i] = uu * Index_value[i - 1];
	for (i = 0; i <= no_steps; ++i)
		call_values[i] = max(0.0, (Index_value[i] - X));
	for (int step = no_steps - 1; step >= 0; --step)
	{
		for (i = 0; i <= step; ++i)
		{
			Index_value[i] = d * Index_value[i + 1];
			call_values[i] = (pDown * call_values[i] + pUp * call_values[i + 1])*Rinv;
			call_values[i] = max(call_values[i], Index_value[i] - X);
		}
	}
	return call_values[0];
}

int mf()
{
	double Index = 930;
	double X = 900;
	double r = 0.08;
	double y = 0.05;
	double sigma = 0.4;
	double time = 0.4;
	double no_steps = 100;
	cout << "指数美式期权的价格：" << index_option_price_call_american_binomial(Index, X, r, y, sigma, time, no_steps) << endl;
	return 0;
}