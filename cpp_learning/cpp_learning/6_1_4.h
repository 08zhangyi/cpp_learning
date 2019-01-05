#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

double max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

double option_price_delta_call_black_scholes(const double& S, const double& K, const double& r, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / K) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - sigma * time_sqrt;
	double delta = N(d1);
	return delta;
}

double option_price_delta_call_european_simulated(const double& S, const double& X, const double& r, const double& sigma,
	const double& time, const int& no_sims)
{
	double R = (r - 0.5*pow(sigma, 2)) * time;
	double SD = sigma * sqrt(time);
	double sum_payoffs = 0.0;
	double sum_payoffs_q = 0.0;
	double q = S * 0.01;
	for (int n = 1; n <= no_sims; n++)
	{
		double Z = random_normal();
		double S_T = S * exp(R + SD * Z);
		sum_payoffs += max(0.0, S_T - X);
		double S_T_q = (S + q) * exp(R + SD * Z);
		sum_payoffs_q += max(0.0, S_T_q - X);
	}
	double c = exp(-r * time) * (sum_payoffs / no_sims);
	double c_q = exp(-r * time) * (sum_payoffs_q / no_sims);
	return (c_q - c) / q;
}

int mf()
{
	double S = 100.0;
	double X = 100.0;
	double r = 0.1;
	double sigma = 0.25;
	double time = 1.0;
	int no_sims = 5000;
	double call_option;
	double put_option;
	std::cout << "Black-Scholes期权定价公式（看涨）：" << option_price_delta_call_black_scholes(S, X, r, sigma, time) << std::endl;
	std::cout << "蒙特卡罗法（看涨）：" << option_price_delta_call_european_simulated(S, X, r, sigma, time, no_sims) << std::endl;
	return 0;
}