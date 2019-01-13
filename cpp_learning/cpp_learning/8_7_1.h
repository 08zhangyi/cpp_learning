#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

using namespace std;

double asset_exchange_option_price_call(const double& S1, const double& S2, const double& q1, const double& q2,
	const double& sigma1, const double& sigma2, const double& rho, const double& time)
{
	double sigma1_sqr = sigma1 * sigma1;
	double sigma2_sqr = sigma2 * sigma2;
	double time_sqrt = sqrt(time);
	double sigma = sqrt(sigma1_sqr + sigma2_sqr - 2 * rho * sigma1 * sigma2);
	double d1 = (log(S2 / S1) + (q1 - q2 + 0.5 * sigma * sigma) * time) / (sigma * time_sqrt);
	double d2 = d1 - sigma * time_sqrt;
	return S2 * exp(-q2 * time) * N(d1) - S1 * exp(-q1 * time) * N(d2);
}

int mf()
{
	double S1 = 90.0;
	double S2 = 100.0;
	double q1 = 0.025;
	double q2 = 0.03;
	double sigma1 = 0.02;
	double sigma2 = 0.01;
	double rho = 0.89;
	double time = 1;
	cout << "资产交换期权的价格：" << asset_exchange_option_price_call(S1, S2, q1, q2, sigma1, sigma2, rho, time) << endl;
	return 0;
}