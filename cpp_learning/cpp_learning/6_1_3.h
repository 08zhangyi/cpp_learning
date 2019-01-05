#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

double option_price_call_black_scholes(const double& S, const double& X, const double& r, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	double c = S * N(d1) - X * exp(-r * time)*N(d2);
	return c;
}

double option_price_put_black_scholes(const double& S, const double& X, const double& r, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	double p = X * exp(-r * time) * N(-d2) - S * N(-d1);
	return p;
}

double max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

double payoff_call(const double& price, const double& X)
{
	return max(0.0, price - X);
}

double simulate_random_variable(const double& S, const double& r, const double& sigma, const double& times)
{
	double R = (r - 0.5 * pow(sigma, 2)) * times;
	double SD = sigma * sqrt(times);
	return S * exp(R + SD * random_normal());
}

double derivative_price_simulate_european_option_generc(const double& S, const double& X, const double& r, const double& sigma,
	const double& times, const int& no_sims)
{
	double sum_payoffs = 0.0;
	for (int n = 1; n <= no_sims; n++)
	{
		double S_T = simulate_random_variable(S, r, sigma, times);
		sum_payoffs += payoff_call(S_T, X);
	}
	return exp(-r * times) * (sum_payoffs / no_sims);
}

int mf()
{
	double S = 100.0;
	double X = 100.0;
	double r = 0.1;
	double sigma = 0.25;
	double times = 1.0;
	int no_sims = 50000;
	std::cout << "Black-Scholes期权定价公式（看涨）：" << option_price_call_black_scholes(S, X, r, sigma, times) << std::endl;
	std::cout << "蒙特卡罗法（看涨）：" << derivative_price_simulate_european_option_generc(S, X, r, sigma, times, no_sims) << std::endl;
	return 0;
}