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

double simulate_lognormal_random_variable(const double& S, const double& r, const double& sigma, const double& time)
{
	double R = (r - 0.5*pow(sigma, 2)) * time;
	double SD = sigma * sqrt(time);
	return S * exp(R + SD * random_normal());
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

double derivative_price_simulate_european_option_generic_with_control_variate(const double& S, const double& X,
	const double& r, const double& sigma, const double& time, const int& no_sims)
{
	double c_bs = option_price_call_black_scholes(S, S, r, sigma, time);
	double sum_payoffs = 0;
	double sum_payoffs_bs = 0;

	for (int n = 0; n < no_sims; n++)
	{
		double S_T = simulate_lognormal_random_variable(S, r, sigma, time);
		sum_payoffs += payoff_call(S_T, X);
		sum_payoffs_bs += payoff_call(S_T, S);
	}
	double c_sim = exp(-r * time) * (sum_payoffs / no_sims);
	double c_bs_sim = exp(-r * time) * (sum_payoffs_bs / no_sims);
	c_sim = c_sim - c_bs_sim + c_bs;
	return c_sim;
}

int mf()
{
	double S = 100.0;
	double X = 100.0;
	double r = 0.1;
	double sigma = 0.25;
	double times = 1.0;
	int no_sims = 5000;
	std::cout << "Black-Scholes期权定价公式（看涨）：" << option_price_call_black_scholes(S, X, r, sigma, times) << std::endl;
	std::cout << "控制变量法的结果：" << derivative_price_simulate_european_option_generic_with_control_variate(S, X, r, sigma, times, no_sims) << std::endl;
	return 0;
}