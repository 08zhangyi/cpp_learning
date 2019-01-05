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

void option_price_european_simulated(const double& S, const double& X, const double& r, const double& sigma,
	const double& time, const int& no_sims, double& call_option, double& put_option)
{
	double R = (r - 0.5*pow(sigma, 2)) * time;
	double SD = sigma * sqrt(time);
	double sum_payoffs1 = 0.0;
	double sum_payoffs2 = 0.0;
	for (int n = 1; n <= no_sims; n++)
	{
		double S_T = S * exp(R + SD * random_normal());
		sum_payoffs1 += max(0.0, S_T - X);
		sum_payoffs2 += max(X - S_T, 0.0);
	}
	call_option= exp(-r * time) * (sum_payoffs1 / double(no_sims));
	put_option = exp(-r * time) * (sum_payoffs2 / double(no_sims));
}

int mf()
{
	double S = 100.0;
	double X = 100.0;
	double r = 0.1;
	double sigma = 0.25;
	double time = 1.0;
	int no_sims = 5000000;
	double call_option;
	double put_option;
	option_price_european_simulated(S, X, r, sigma, time, no_sims, call_option, put_option);
	std::cout << "Black-Scholes期权定价公式（看涨）：" << option_price_call_black_scholes(S, X, r, sigma, time) << std::endl;
	std::cout << "Black-Scholes期权定价公式（看跌）：" << option_price_put_black_scholes(S, X, r, sigma, time) << std::endl;
	std::cout << "蒙特卡罗法（看涨）：" << call_option << std::endl;
	std::cout << "蒙特卡罗法（看跌）：" << put_option << std::endl;
	return 0;
}