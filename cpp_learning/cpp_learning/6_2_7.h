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

double currency_option_price_call_american_binomial(const double& S, const double& X, const double& r,
	const double& r_f, const double& sigma, const double& time, const int& no_steps)
{
	vector<double> exchange_rates(no_steps + 1);
	vector<double> call_values(no_steps + 1);
	double t_delta = time / no_steps;
	double Rinv = exp(-r * (t_delta));
	double u = exp(sigma*sqrt(t_delta));
	double d = 1.0 / u;
	double uu = u * u;
	double pUp = (exp((r - r_f)*t_delta) - d) / (u - d);
	double pDown = 1.0 - pUp;
	exchange_rates[0] = S * pow(d, no_steps);
	int i;
	for (i = 1; i <= no_steps; ++i)
		exchange_rates[i] = uu * exchange_rates[i - 1];
	for (i = 0; i <= no_steps; ++i)
		call_values[i] = max(0.0, (exchange_rates[i] - X));
	for (int step = no_steps - 1; step >= 0; --step)
	{
		for (i = 0; i <= step; ++i)
		{
			exchange_rates[i] = d * exchange_rates[i + 1];
			call_values[i] = (pDown * call_values[i] + pUp * call_values[i + 1])*Rinv;
			call_values[i] = max(call_values[i], exchange_rates[i] - X);
		}
	}
	return call_values[0];
}

int mf()
{
	double S = 1.61;
	double X = 1.60;
	double r = 0.08;
	double r_f = 0.1;
	double sigma = 0.12;
	double time = 1.0;
	int no_steps = 100;
	cout << "指数美式期权的价格：" << currency_option_price_call_american_binomial(S, X, r, r_f, sigma, time, no_steps) << endl;
	return 0;
}
