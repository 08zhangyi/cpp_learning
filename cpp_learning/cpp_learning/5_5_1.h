#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

void option_price_partials_call_back_scholes(double& S, double& X, double& r, double& sigma, double& time, double& Delta, double& Gamma, double& Theta, double& Vega, double& Rho)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	
	Delta = N(d1);
	Gamma = n(d1) / (S*sigma*time_sqrt);
	Theta = -(S*sigma*n(d1)) / (2 * time_sqrt) - r * X*exp(-r * time)*N(d2);
	Vega = S * time_sqrt*n(d1);
	Rho = X * time * exp(-r * time)*N(d2);
}

int mf()
{
	std::cout << "欧式看涨期权偏导数" << std::endl;
	double S = 50;
	double X = 50;
	double r = 0.10;
	double sigma = 0.30;
	double time = 0.50;
	double Delta, Gamma, Theta, Vega, Rho;
	option_price_partials_call_back_scholes(S, X, r, sigma, time, Delta, Gamma, Theta, Vega, Rho);
	std::cout << "Delta：" << Delta << std::endl;
	std::cout << "Gamma：" << Gamma << std::endl;
	std::cout << "Theta：" << Theta << std::endl;
	std::cout << "Vega：" << Vega << std::endl;
	std::cout << "Rho：" << Rho << std::endl;
	return 0;

}