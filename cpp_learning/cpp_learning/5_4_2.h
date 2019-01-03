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

double option_price_american_call_one_dividend(const double& S, const double& X, const double& r, const double& sigma, const double& tau, const double& D1, const double& tau1)
{
	if (D1 <= X * (1.0 - exp(-r * (tau - tau1))))
		return option_price_call_black_scholes(S - exp(-r * tau1)*D1, X, r, sigma, tau);
	const double ACCURACY = 1e-6;
	double sigma_sqr = sigma * sigma;
	double tau_sqrt = sqrt(tau);
	double tau1_sqrt = sqrt(tau1);
	double rho = -sqrt(tau1 / tau);
	double S_bar = 0;
	double S_low = 0;
	double S_high = S;
	double c = option_price_call_black_scholes(S_high, X, r, sigma, tau - tau1);
	double test = c - S_high - D1 + X;
	while ((test > 0.0) && (S_high <= 1e10))
	{
		S_high *= 2.0;
		c = option_price_call_black_scholes(S_high, X, r, sigma, tau - tau1);
		test = c - S_high - D1 + X;
	}
	if (S_high > 1e10)
		return option_price_call_black_scholes(S - D1 * exp(-r * tau1), X, r, sigma, tau);
	S_bar = 0.5 * S_high;
	c = option_price_call_black_scholes(S_bar, X, r, sigma, tau - tau1);
	test = c - S_bar - D1 + X;
	while ((fabs(test) > ACCURACY) && ((S_high - S_low) > ACCURACY))
	{
		if (test < 0.0)
			S_high = S_bar;
		else
			S_low = S_bar;
		S_bar = 0.5 * (S_high + S_low);
		c = option_price_call_black_scholes(S_bar, X, r, sigma, tau - tau1);
		test = c - S_bar - D1 + X;
	}
	double a1 = (log((S - D1 * exp(-r * tau1)) / X) + (r + 0.5*sigma_sqr)*tau) / (sigma * tau_sqrt);
	double a2 = a1 - sigma * tau_sqrt;
	double b1 = (log((S - D1 * exp(-r * tau1)) / S_bar) + (r + 0.5*sigma_sqr)*tau1) / (sigma * tau1_sqrt);
	double b2 = b1 - sigma * tau1_sqrt;
	double C = (S - D1 * exp(-r * tau1))*N(b1) + (S - D1 * exp(-r * tau1))*N(a1, -b1, rho) - (X * exp(-r * tau))*N(a2, -b2, rho) - (X - D1)*exp(-r * tau1)*N(b2);
	return C;
}

int mf()
{
	double S = 100.0;
	double X = 100.0;
	double r = 0.1;
	double sigma = 0.25;
	double tau = 1.0;
	double tau1 = 0.5;
	double D1 = 10.0;
	std::cout << "支付已知红利的美式看涨期权的价格：" << option_price_american_call_one_dividend(S, X, r, sigma, tau, D1, tau1) << std::endl;
	return 0;
}