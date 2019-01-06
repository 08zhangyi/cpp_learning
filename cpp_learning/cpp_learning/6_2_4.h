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

double option_price_call_american_proportional_dividends_binomial(const double& S, const double& X, const double& r,
	const double& sigma, const double& time, const int& steps, const vector<double>& dividend_times, const vector<double>& dividend_yields)
{
	int no_dividends = dividend_times.size();
	if (no_dividends == 0)
		return option_price_call_american_binomial(S, X, r, sigma, time, steps);
	double delta_t = time / steps;
	double R = exp(r*delta_t);
	double Rinv = 1.0 / R;
	double u = exp(sigma*sqrt(delta_t));
	double uu = u * u;
	double d = 1.0 / u;
	double p_up = (R - d) / (u - d);
	double p_down = 1.0 - p_up;
	vector<int> dividend_steps(no_dividends);
	for (int i = 0; i < no_dividends; ++i)
		dividend_steps[i] = (int)(dividend_times[i] / time * steps);
	vector<double> prices(steps + 1);
	vector<double> call_values(steps + 1);
	prices[0] = S * pow(d, steps);
	for (int j = 0; j < no_dividends; ++j)
		prices[0] *= (1.0 - dividend_yields[j]);
	for (int k = 1; k <= steps; ++k)
		prices[k] = uu * prices[k - 1];
	for (int m = 0; m <= steps; ++m)
		call_values[m] = max(0.0, (prices[m] - X));
	for (int step = steps - 1; step >= 0; --step)
	{
		for (int i = 0; i <= no_dividends; ++i)
		{
			if (step == dividend_steps[i])
			{
				cout << "红利率发生步数：" << step << endl;
				for (int j = 0; j <= (step + 1); j++)
					prices[j] *= (1.0 / (1.0 - dividend_yields[i]));
			}
		}
		for (int n = 0; n <= step; ++n)
		{
			call_values[n] = (p_up * call_values[n + 1] + p_down * call_values[n]) * Rinv;
			prices[n] = d * prices[n + 1];
			call_values[n] = max(call_values[n], prices[n] - X);
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
	vector<double> dividend_times;
	dividend_times.push_back(0.25);
	dividend_times.push_back(0.75);
	vector<double> dividend_yields;
	dividend_yields.push_back(0.025);
	dividend_yields.push_back(0.075);
	cout << "期权价格：" << option_price_call_american_proportional_dividends_binomial(S, X, r, sigma, time, steps, dividend_times, dividend_yields) << endl;
	return 0;
}