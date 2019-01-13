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

double option_price_call_bermudan_binomial(const double& S, const double& X, const double& r, const double& q,
	const double& sigma, const double& time, const vector<double>& potential_exercise_times, const int& steps)
{
	double delta_t = time / steps;
	double R = exp(r*delta_t);
	double Rinv = 1.0 / R;
	double u = exp(sigma * sqrt(delta_t));
	double uu = u * u;
	double d = 1.0 / u;
	double p_up = (exp((r - q)*(delta_t)) - d) / (u - d);
	double p_down = 1.0 - p_up;
	vector<double> prices(steps + 1);
	vector<double> call_values(steps + 1);
	vector<int> potential_exercise_steps;
	for (int i = 0; i < potential_exercise_times.size(); ++i)
	{
		double t = potential_exercise_steps[i];
		if ((t > 0.0) && (t < time))
			potential_exercise_steps.push_back(int(t / delta_t));
	}
	prices[0] = S * pow(d, steps);
	for (int j = 1; j <= steps; ++j)
		prices[j] = uu * prices[j - 1];
	for (int k = 0; k <= steps; ++k)
		call_values[k] = max(0.0, (prices[k] - X));
	for (int step = steps - 1; step >= 0; --step)
	{
		bool check_exercise_this_step = false;
		for (int j = 0; j < potential_exercise_steps.size(); ++j)
		{
			if (step == potential_exercise_steps[j])
				check_exercise_this_step = true;
		}
		for (int i = 0; i <= step; ++i)
		{
			call_values[i] = (p_up*call_values[i + 1] + p_down * call_values[i])*Rinv;
			prices[i] = d * prices[i + 1];
			if (check_exercise_this_step)
				call_values[i] = max(call_values[i], prices[i] - X);
		}
	}
	return call_values[0];
}

double option_price_put_bermudan_binomial(const double& S, const double& X, const double& r, const double& q,
	const double& sigma, const double& time, const vector<double>& potential_exercise_times, const int& steps)
{
	double delta_t = time / steps;
	double R = exp(r*delta_t);
	double Rinv = 1.0 / R;
	double u = exp(sigma * sqrt(delta_t));
	double uu = u * u;
	double d = 1.0 / u;
	double p_up = (exp((r - q)*(delta_t)) - d) / (u - d);
	double p_down = 1.0 - p_up;
	vector<double> prices(steps + 1);
	vector<double> call_values(steps + 1);
	vector<int> potential_exercise_steps;
	for (int i = 0; i < potential_exercise_times.size(); ++i)
	{
		double t = potential_exercise_steps[i];
		if ((t > 0.0) && (t < time))
			potential_exercise_steps.push_back(int(t / delta_t));
	}
	prices[0] = S * pow(d, steps);
	for (int j = 1; j <= steps; ++j)
		prices[j] = uu * prices[j - 1];
	for (int k = 0; k <= steps; ++k)
		call_values[k] = max(0.0, (X - prices[k]));
	for (int step = steps - 1; step >= 0; --step)
	{
		bool check_exercise_this_step = false;
		for (int j = 0; j < potential_exercise_steps.size(); ++j)
		{
			if (step == potential_exercise_steps[j])
				check_exercise_this_step = true;
		}
		for (int i = 0; i <= step; ++i)
		{
			call_values[i] = (p_up*call_values[i + 1] + p_down * call_values[i])*Rinv;
			prices[i] = d * prices[i + 1];
			if (check_exercise_this_step)
				call_values[i] = max(call_values[i], X - prices[i]);
		}
	}
	return call_values[0];
}

int mf()
{
	double S = 80.0;
	double X = 100.0;
	double r = 0.2;
	double time = 1.0;
	double sigma = 0.25;
	int steps = 500;
	double q = 0.0;

	vector<double> potential_exercise_times;
	potential_exercise_times.push_back(0.25);
	potential_exercise_times.push_back(0.5);
	potential_exercise_times.push_back(0.75);

	cout << "Bermudan看涨期权的价格：" << option_price_call_bermudan_binomial(S, X, r, q, sigma, time, potential_exercise_times, steps) << endl;
	cout << "Bermudan看跌期权的价格：" << option_price_put_bermudan_binomial(S, X, r, q, sigma, time, potential_exercise_times, steps) << endl;
	return 0;
}