#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

using namespace std;

double barrier_option_price_call_down_and_in(const double& S, const double& X, const double& H, const double& r,
	const double& rf, const double& q, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double lambda = (r - rf + 0.5*sigma_sqr) / sigma_sqr;
	double y = (log((H*H) / (S*X))) / (sigma*time_sqrt);
	double c = S * exp(-q * time)*pow(H / S, 2 * lambda)*N(y) - X * exp(-r * time)*pow(H / S, (2 * lambda - 2))*N(y - sigma * time_sqrt);
	return c;
}

double barrier_option_price_put_up_and_in(const double& S, const double& X, const double& H, const double& r,
	const double& rf, const double& q, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double lambda = (r - rf + 0.5*sigma_sqr);
	double y = (log((H*H) / (S*X))) / (sigma*time_sqrt);
	double p = S * exp(-q * time)*pow(H / S, 2 * lambda)*N(y) - X * exp(-r * time)*pow(H / S, (2 * lambda - 2))*N(y - sigma * time_sqrt);
	return p;
}

int mf()
{
	double S = 80.0;
	double X = 100.0;
	double H = 90.0;
	double r = 0.02;
	double rf = 0.01;
	double q = 0.03;
	double time = 1.0;
	double sigma = 0.25;
	cout << "欧式下降敲入看涨期权的价格：" << barrier_option_price_call_down_and_in(S, X, H, r, rf, q, sigma, time) << endl;
	cout << "欧式下降敲入看跌期权的价格：" << barrier_option_price_put_up_and_in(S, X, H, r, rf, q, sigma, time) << endl;
	return 0;
}