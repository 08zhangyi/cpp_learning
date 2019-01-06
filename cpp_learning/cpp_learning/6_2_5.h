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

double option_price_call_american_discrete_dividends_binomial(const double& S, const double& X, const double& r,
	const double& sigma, const double& time, const int& steps, const vector<double>& dividend_times, const vector<double>& dividend_amounts)
{
	int no_dividends = dividend_times.size();
	if (no_dividends == 0)
		return option_price_call_american_binomial(S, X, r, sigma, time, steps);
	int steps_beforn_dividend = (int)(dividend_times[0] / time * steps);
	const double R = exp(r*(time / steps));
	const double Rinv = 1.0 / R;
	const double u = exp(sigma*sqrt(time / steps));
	const double uu = u * u;
	const double d = 1.0 / u;
	const double p_up = (R - d) / (u - d);
	const double p_down = 1.0 - p_up;
	double dividend_amount = dividend_amounts[0];
	vector<double> tmp_dividend_times(no_dividends - 1);
	vector<double> tmp_dividend_amounts(no_dividends - 1);
	for (int i = 0; i < (no_dividends); ++i)
	{
		tmp_dividend_amounts[i] = dividend_amounts[i + 1];
		tmp_dividend_times[i] = dividend_times[i + 1] - dividend_times[0];
	}
	vector<double> prices(steps_beforn_dividend + 1);
	vector<double> call_values(steps_beforn_dividend + 1);
	prices[0] = S * pow(d, steps_beforn_dividend);
	for (int j = 1; j <= steps_beforn_dividend; ++j)
		prices[j] = uu * prices[j - 1];
	for (int k = 0; k <= steps_beforn_dividend; ++k)
	{
		double value_alive = option_price_call_american_discrete_dividends_binomial(prices[k] - dividend_amount, X, r, sigma, time - dividend_times[0], steps - steps_beforn_dividend, tmp_dividend_times, tmp_dividend_amounts);
		call_values[k] = max(value_alive, (prices[k] - X));
	}
	for (int step = steps_beforn_dividend - 1; step >= 0; --step)
	{
		for (int m = 0; m <= step; ++m)
		{
			prices[m] = d * prices[m + 1];
			call_values[m] = (p_down * call_values[m] + p_up * call_values[m + 1] * Rinv);
			call_values[m] = max(call_values[m], prices[m] - X);
		}
	}
	return call_values[0];
}

int mf()
{
	double S = 100;
	double X = 100;
	double r = 0.1;
	double sigma = 0.25;
	double time = 1.0;
	int steps = 100;
	vector<double> dividend_times;
	dividend_times.push_back(0.25);
	dividend_times.push_back(0.75);
	vector<double> dividend_amounts;
	dividend_amounts.push_back(2.5);
	dividend_amounts.push_back(2.5);
	cout << "期权价格：" << option_price_call_american_discrete_dividends_binomial(S, X, r, sigma, time, steps, dividend_times, dividend_amounts) << endl;
	return 0;
}