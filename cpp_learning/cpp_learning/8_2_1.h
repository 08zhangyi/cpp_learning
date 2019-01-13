#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>

using namespace std;

double option_price_asian_geometric_average_price_call(const double& Save, const double& X, const double& r,
	const double& q, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double adj_div_yield = 0.5 * (r + q + sigma_sqr / 6);
	double adj_sigma = sigma / sqrt(3.0);
	double adj_sigma_sqr = pow(adj_sigma, 2);
	double time_sqrt = sqrt(time);
	double d1 = (log(Save / X) + (r - adj_div_yield + 0.5*adj_sigma) * time) / (adj_sigma * time_sqrt);
	double d2 = d1 - adj_sigma * time_sqrt;
	double call_price = Save * exp(-adj_div_yield * time) * N(d1) - X * exp(-r * time) * N(d2);
	return call_price;
}

int mf()
{
	double Save = 100.0;
	double X = 100.0;
	double r = 0.06;
	double q = 0.02;
	double sigma = 0.25;
	double time = 1;

	cout << "几何平均价格看涨期权的价格：" << option_price_asian_geometric_average_price_call(Save, X, r, q, sigma, time) << endl;
	return 0;
}