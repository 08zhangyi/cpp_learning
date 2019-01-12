#pragma once
#include <math.h>
#include <iostream>
#include "normdist.h"

using namespace std;

double term_structure_discount_factor_vasicek(const double& time, const double& r, const double& a,
	const double& b, const double& sigma)
{
	double A, B;
	double sigma_sqr = sigma * sigma;
	double aa = a * a;
	if (a == 0.0)
	{
		B = time;
		A = exp(sigma_sqr * pow(time, 3)) / 6.0;
	}
	else
	{
		B = (1.0 - exp(-a * time)) / a;
		A = exp(((B - time) * (aa * b - 0.5 * sigma_sqr)) / aa - ((sigma_sqr * B * B) / (4 * a)));
	}
	double dfact = A * exp(-B * r);
	return dfact;
}

double bond_option_price_call_zero_vasicek(const double& X, const double& r, const double& option_time_to_maturity,
	const double& bond_time_to_maturity, const double& a, const double& b, const double& sigma)
{
	double T_t = option_time_to_maturity;
	double s_t = bond_time_to_maturity;
	double T_s = s_t - T_t;
	double v_t_T;
	double sigma_P;
	if (a == 0.0)
	{
		v_t_T = sigma * sqrt(T_t);
		sigma_P = sigma * T_s * sqrt(T_t);
	}
	else
	{
		v_t_T = sqrt(sigma * sigma * (1 - exp(-2 * a * T_t)) / (2 * a));
		double B_T_s = (1 - exp(-a * T_s)) / a;
		sigma_P = v_t_T * B_T_s;
	}
	double h = (1.0 / sigma_P) * log(term_structure_discount_factor_vasicek(s_t, r, a, b, sigma) / (term_structure_discount_factor_vasicek(T_t, r, a, b, sigma) * X));
	double c = term_structure_discount_factor_vasicek(s_t, r, a, b, sigma) * N(h) - X * term_structure_discount_factor_vasicek(T_t, r, a, b, sigma) * N(h - sigma_P);
	return c;
}

int mf()
{
	double a = 0.1;
	double b = 0.1;
	double sigma = 0.02;
	double r = 0.05;
	double X = 0.9;
	double option_time_to_maturity = 1;
	double bond_time_to_maturity = 5;

	cout << "欧式债券看涨期权的价格：" << bond_option_price_call_zero_vasicek(X, r, option_time_to_maturity, bond_time_to_maturity, a, b, sigma) << endl;
	return 0;
}