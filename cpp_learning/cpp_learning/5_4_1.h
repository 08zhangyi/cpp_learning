#pragma once
#include <math.h>
#include <vector>
#include "normdist.h"
#include <iostream>

using namespace std;

double option_price_call_black_scholes_dividens(const double& S, const double& X, const double& r, const vector<double>& dividens, const vector<double>& dividens_times, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double PV = 0.0;
	for (int i = 0; i < dividens_times.size(); i++)
	{
		PV += dividens[i] * exp(-r * dividens_times[i]);
	}
	double adjusted_S = S - PV;
	double d1 = (log(adjusted_S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	double c = adjusted_S * N(d1) - X * exp(-r * time)*N(d2);
	return c;
}

double option_price_put_black_scholes_dividens(const double& S, const double& X, const double& r, const vector<double>& dividens, const vector<double>& dividens_times, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double PV = 0.0;
	for (int i = 0; i < dividens_times.size(); i++)
	{
		PV += dividens[i] * exp(-r * dividens_times[i]);
	}
	double adjusted_S = S - PV;
	double d1 = (log(adjusted_S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	double p = X * exp(-r * time) * N(-d2) - adjusted_S * N(-d1);
	return p;
}

int mf()
{
	double S = 40;
	double X = 40;
	double r = 0.09;
	double sigma = 0.30;
	double time = 0.50;

	vector<double> dividens_times;
	dividens_times.push_back(0.0);
	dividens_times.push_back(0.0833);
	dividens_times.push_back(0.1667);
	dividens_times.push_back(0.25);
	dividens_times.push_back(0.3333);
	dividens_times.push_back(0.4167);
	dividens_times.push_back(0.5);
	vector<double> dividens;
	dividens.push_back(0);
	dividens.push_back(0);
	dividens.push_back(0.5);
	dividens.push_back(0);
	dividens.push_back(0);
	dividens.push_back(0.5);
	dividens.push_back(0);
	cout << "欧式看涨期权的价格：" << option_price_call_black_scholes_dividens(S, X, r, dividens, dividens_times, sigma, time) << endl;
	cout << "欧式看跌期权的价格：" << option_price_put_black_scholes_dividens(S, X, r, dividens, dividens_times, sigma, time) << endl;
	return 0;
}