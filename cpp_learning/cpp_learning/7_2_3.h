#pragma once
#include <math.h>
#include "normdist.h"
#include <iostream>
#include <vector>

using namespace std;

double bond_option_price_call_zero_black_scholes(const double& B, const double& X,
	const double& R, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double d1 = (log(B / X) + (R + 0.5*sigma_sqr)*time) / (sigma*time_sqrt);
	double d2 = d1 - sigma * time_sqrt;
	double c = B * N(d1) - X * exp(-R * time) * N(d2);
	return c;
}

double bond_option_price_put_zero_black_scholes(const double& B, const double& X,
	const double& R, const double& sigma, const double& time)
{
	double sigma_sqr = sigma * sigma;
	double time_sqrt = sqrt(time);
	double d1 = (log(B / X) + (R + 0.5*sigma_sqr)*time) / (sigma*time_sqrt);
	double d2 = d1 - sigma * time_sqrt;
	double c = X * exp(-R * time) * N(-d2) - B * N(-d1);
	return c;
}

double bond_option_price_call_coupon_bond_black_scholes(const double& B, const double& X,
	const double& R, const double& sigma, const double& time, const vector<double> coupon_times, const vector<double> coupon_amounts)
{
	double adjusted_B = B;
	for (unsigned int i = 0; i < coupon_times.size(); i++)
	{
		if (coupon_times[i] <= time)
		{
			adjusted_B -= coupon_amounts[i] * exp(-R * coupon_times[i]);
		}
	}
	return bond_option_price_call_zero_black_scholes(adjusted_B, X, R, sigma, time);
}

double bond_option_price_put_coupon_bond_black_scholes(const double& B, const double& X,
	const double& R, const double& sigma, const double& time, const vector<double> coupon_times, const vector<double> coupon_amounts)
{
	double adjusted_B = B;
	for (unsigned int i = 0; i < coupon_times.size(); i++)
	{
		if (coupon_times[i] <= time)
		{
			adjusted_B -= coupon_amounts[i] * exp(-R * coupon_times[i]);
		}
	}
	return bond_option_price_put_zero_black_scholes(adjusted_B, X, R, sigma, time);
}


int mf()
{
	double B = 100;
	double X = 100;
	double R = 0.05;
	double sigma = 0.1;
	double time = 1;
	vector<double> coupon_times;
	coupon_times.push_back(0.5);
	vector<double> coupon_amounts;
	coupon_amounts.push_back(1);

	cout << "零息债券看涨期权的价格：" << bond_option_price_call_zero_black_scholes(B, X, R, sigma, time) << endl;
	cout << "零息债券看跌期权的价格：" << bond_option_price_put_zero_black_scholes(B, X, R, sigma, time) << endl;
	cout << "付息债券看涨期权的价格：" << bond_option_price_call_coupon_bond_black_scholes(B, X, R, sigma, time, coupon_times, coupon_amounts) << endl;
	cout << "付息债券看跌期权的价格：" << bond_option_price_put_coupon_bond_black_scholes(B, X, R, sigma, time, coupon_times, coupon_amounts) << endl;
	return 0;
}