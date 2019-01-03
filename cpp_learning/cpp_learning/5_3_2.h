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

int mf()
{
	double S = 50;
	double X = 50;
	double r = 0.10;
	double sigma = 0.30;
	double time = 0.50;
	std::cout << "欧式看涨期权的价格：" << option_price_call_black_scholes(S, X, r, sigma, time) << std::endl;
	std::cout << "欧式看跌期权的价格：" << option_price_put_black_scholes(S, X, r, sigma, time) << std::endl;
	return 0;
}