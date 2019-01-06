#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double max(double x, double y)
{
	if (x > y)
		return x;
	else
		return y;
}

double option_price_call_american_binomial(const double& S, const double& X, const double& r,
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
	vector<double> call_values(steps + 1);
	prices[0] = S * pow(d, steps);
	for (int i = 1; i <= steps; ++i)
		prices[i] = uu * prices[i - 1];
	for (int j = 0; j <= steps; j++)
		call_values[j] = max(0.0, (prices[j] - X));
	for (int step = steps - 1; step >= 0; --step)
	{
		for (int i = 0; i <= step; ++i)
		{
			call_values[i] = (p_up * call_values[i + 1] + p_down * call_values[i]) * Rinv;
			prices[i] = d * prices[i + 1];
			call_values[i] = max(call_values[i], prices[i] - X);
		}
	}
	return call_values[0];
}

double option_price_put_american_binomial(const double& S, const double& X, const double& r,
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
	vector<double> put_values(steps + 1);
	prices[0] = S * pow(d, steps);
	for (int i = 1; i <= steps; ++i)
		prices[i] = uu * prices[i - 1];
	for (int j = 0; j <= steps; j++)
		put_values[j] = max(0.0, (X - prices[j]));
	for (int step = steps - 1; step >= 0; --step)
	{
		for (int i = 0; i <= step; ++i)
		{
			put_values[i] = (p_up * put_values[i + 1] + p_down * put_values[i]) * Rinv;
			prices[i] = d * prices[i + 1];
			put_values[i] = max(put_values[i], X - prices[i]);
		}
	}
	return put_values[0];
}

int mf()
{
	double S = 100;
	double X = 100;
	double r = 0.025;
	double sigma = 0.25;
	double time = 1;
	int steps = 100;
	cout << "美式看涨期权的价格：" << option_price_call_american_binomial(S, X, r, sigma, time, steps) << endl;
	cout << "美式看跌期权的价格：" << option_price_put_american_binomial(S, X, r, sigma, time, steps) << endl;
	return 0;
}