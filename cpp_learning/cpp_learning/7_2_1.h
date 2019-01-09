#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

double option_price_cap_rate_european(const double& Fk, const double& Rx, const double& L, const double& r,
	const double& sigma, const double& tau, const double& k)
{
	double sigma_sqr = sigma * sigma;
	double tau_sqrt = sqrt(k*tau);
	double d1 = (log(Fk / Rx) + 0.5*sigma_sqr*k*tau) / (sigma*tau_sqrt);
	double d2 = d1 - (sigma*tau_sqrt);
	double call_price = (tau*L) / (1 + tau * Fk)*exp(-r * k*tau)*(Fk*N(d1) - Rx * N(d2));
	return call_price;
}

int mf()
{
	double Fk = 0.07;
	double Rx = 0.08;
	double L = 10000;
	double r = 0.065;
	double sigma = 0.2;
	double tau = 0.25;
	double k = 4;
	std::cout << "利率上限的价格：" << option_price_cap_rate_european(Fk, Rx, L, r, sigma, tau, k) << std::endl;
	return 0;
}