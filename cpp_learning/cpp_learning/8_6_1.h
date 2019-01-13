#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

using namespace std;

double option_price_call_and_call_european(const double& S, const double& X1, const double& X2, const double& S_time1,
	const double& r, const double& q, const double& sigma, const double& time1, const double& time2)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time1/time2);
	double a1 = (log(S / S_time1) + (-r + q + 0.5*sigma_sqr)*time1) / (sigma*sqrt(time1));
	double a2 = a1 - sigma * sqrt(time1);
	double b1 = (log(S /X2) + (r - q - 0.5*sigma_sqr)*time2) / (sigma*sqrt(time2));
	double b2 = b1 - sigma * sqrt(time2);
	double call_price = S * exp(-q * time2) * N(a1, b1, time_sqrt) - X2 * exp(-r * time2)*N(a2, b2, time_sqrt) - X1 * exp(-r * time1) * N(a2);
	return call_price;
}

double option_price_put_and_put_european(const double& S, const double& X1, const double& X2, const double& S_time1,
	const double& r, const double& q, const double& sigma, const double& time1, const double& time2)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time1 / time2);
	double a1 = (log(S / S_time1) + (-r + q + 0.5*sigma_sqr)*time1) / (sigma*sqrt(time1));
	double a2 = a1 - sigma * sqrt(time1);
	double b1 = (log(S / X2) + (r - q - 0.5*sigma_sqr)*time2) / (sigma*sqrt(time2));
	double b2 = b1 - sigma * sqrt(time2);
	double put_put = S * exp(-q * time2) * N(a1, -b1, -time_sqrt) - X2 * exp(-r * time2)*N(a2,-b2, -time_sqrt) - X1 * exp(-r * time1) * N(a2);
	return put_put;
}

int mf()
{
	double S = 150.0;
	double X1 = 50.0;
	double X2 = 100.0;
	double S_time1 = 60.0;
	double r = 0.06;
	double q = 0.03;
	double sigma = 0.03;
	double time1 = 1;
	double time2 = 2;
	cout << "欧式看涨期权的看涨期权的价格：" << option_price_call_and_call_european(S, X1, X2, S_time1, r, q, sigma, time1, time2) << endl;
	cout << "欧式看跌期权的看跌期权的价格：" << option_price_put_and_put_european(S, X1, X2, S_time1, r, q, sigma, time1, time2) << endl;
}