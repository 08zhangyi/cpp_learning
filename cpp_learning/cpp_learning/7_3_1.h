#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

double bond_option_price_call_zero_american_rendleman_bartter(const double& X,
	const double& option_maturity, const double& S, const double& M, const double& interest, const double& bond_maturity, const double& maturity_payment, const int& no_steps)
{
	double delta_t = bond_maturity / no_steps;
	double u = exp(S * sqrt(delta_t));
	double d = 1 / u;
	double p_up = (exp(M*delta_t) - d) / (u - d);
	double p_down = 1.0 - p_up;
	vector<double> r(no_steps + 1);
	r[0] = interest * pow(d, no_steps);
	double uu = u * u;
	for (int i = 1; i <= no_steps; ++i)
		r[i] = r[i - 1] * uu;
	vector<double> P(no_steps + 1);
	for (int j = 0; j <= no_steps; ++j)
		P[j] = maturity_payment;
	int no_call_steps = int(no_steps * option_maturity / bond_maturity);
	for (int curr_step = no_steps; curr_step > no_call_steps; --curr_step)
	{
		for (int i = 0; i < curr_step; i++)
		{
			r[i] = r[i] * u;
			P[i] = exp(-r[i] * delta_t) * (p_down*P[i] + p_up * P[P + 1]);
		}
	}
	vector<double> C(no_call_steps + 1);
	for (int k = 0; k <= no_call_steps; ++k)
		C[k] = max(0.0, P[k] - X);
	for (int curr_step_ = no_call_steps; curr_step_ >= 0; --curr_step_)
	{
		for (int i = 0; i < curr_step_; i++)
		{
			r[i] = r[i] * u;
			P[i] = exp(-r[i] * delta_t) * (p_down*P[i] + p_up * P[i + 1]);
			C[i] = max(P[i] - X, exp(-r[i] * delta_t)*(p_up*C[i + 1] + p_down * C[i]));
		}
	}
	return C[0];
}

int mf()
{
	double X = 950;
	double S = 0.15;
	double M = 0.05;
	double r = 0.10;
	double option_maturity = 4;
	double bond_maturity = 5;
	double maturity_payment = 1000;
	int no_steps = 100;

	std::cout << "零息债券期权的价格：" << bond_option_price_call_zero_american_rendleman_bartter(X, option_maturity, S, M, r, bond_maturity, maturity_payment, no_steps) << std::endl;
	return 0;
}