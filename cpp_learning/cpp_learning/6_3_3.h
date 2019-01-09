#pragma once
#include <math.h>
#include <vector>
#include <iostream>
#include "newmat10/newmat.h"
#include "normdist.h"

using namespace std;

double max(double x, double y)
{
	if (x > y)
		return x;
	else
		return y;
}

double option_price_call_black_scholes(const double& S, const double& X, const double& r, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	double c = S * N(d1) - X * exp(-r * time)*N(d2);
	return c;
}

double option_price_put_black_scholes(const double& S, const double& X, const double& r, const double& sigma, const double& time)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / X) + r * time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma * time_sqrt);
	double p = X * exp(-r * time) * N(-d2) - S * N(-d1);
	return p;
}

double option_price_call_european_finite_diff_implicit(const double& S, const double& X, const double& r, const double& sigma, const double& time,
	const int& no_S_steps, const int& no_t_steps)
{
	double sigma_sqr = sigma * sigma;
	unsigned int M;
	if ((no_S_steps % 2) == 1)
		M = no_S_steps + 1;
	else
		M = no_S_steps;
	double delta_S = 2.0 * S / M;
	vector<double> S_values(M + 1, 0.0);
	for (unsigned int m = 0; m <= M; m++)
		S_values[m] = m * delta_S;
	int N = no_t_steps;
	double delta_t = time / N;

	BandMatrix A(M + 1, 1, 1);
	A = 0.0;
	A.element(0, 0) = 1.0;
	for (int j = 1; j < M; ++j)
	{
		A.element(j, j - 1) = 0.5 * j * delta_t * (r - sigma_sqr * j);
		A.element(j, j) = 1.0 + delta_t * (r + sigma_sqr * j * j);
		A.element(j, j + 1) = 0.5 * j * delta_t * (-r - sigma_sqr * j);
	}
	A.element(M, M) = 1.0;
	ColumnVector B(M + 1);
	for (int m = 0; m <= M; ++m)
		B.element(m) = max(0.0, S_values[m] - X);
	ColumnVector F = A.i() * B;
	for (int t = N - 1; t > 0; --t)
	{
		B = F;
		F = A.i() * B;
	}
	return F.element(M / 2);
}

double option_price_put_european_finite_diff_implicit(const double& S, const double& X, const double& r, const double& sigma, const double& time,
	const int& no_S_steps, const int& no_t_steps)
{
	double sigma_sqr = sigma * sigma;
	unsigned int M;
	if ((no_S_steps % 2) == 1)
		M = no_S_steps + 1;
	else
		M = no_S_steps;
	double delta_S = 2.0 * S / M;
	vector<double> S_values(M + 1);
	for (unsigned int m = 0; m <= M; m++)
		S_values[m] = m * delta_S;
	int N = no_t_steps;
	double delta_t = time / N;

	BandMatrix A(M + 1, 1, 1);
	A = 0.0;
	A.element(0, 0) = 1.0;
	for (int j = 1; j < M; ++j)
	{
		A.element(j, j - 1) = 0.5 * j * delta_t * (r - sigma_sqr * j);
		A.element(j, j) = 1.0 + delta_t * (r + sigma_sqr * j * j);
		A.element(j, j + 1) = 0.5 * j * delta_t * (-r - sigma_sqr * j);
	}
	A.element(M, M) = 1.0;
	ColumnVector B(M + 1);
	for (int m = 0; m <= M; ++m)
		B.element(m) = max(0.0, X - S_values[m]);
	ColumnVector F = A.i() * B;
	for (int t = N - 1; t > 0; --t)
	{
		B = F;
		F = A.i() * B;
	}
	return F.element(M / 2);
}

int mf()
{
	double S = 50.0;
	double X = 50.0;
	double r = 0.1;
	double sigma = 0.4;
	double time = 0.4167;
	int no_S_steps = 200;
	int no_t_steps = 200;
	cout << "欧式看涨期权的价格（Black-Scholes期权定价公式）：" << option_price_call_black_scholes(S, X, r, sigma, time) << endl;
	cout << "欧式看涨期权的价格（内含有限差分法）" << option_price_call_european_finite_diff_implicit(S, X, r, sigma, time, no_S_steps, no_t_steps) << endl;
	cout << "欧式看跌期权的价格（Black-Scholes期权定价公式）：" << option_price_put_black_scholes(S, X, r, sigma, time) << endl;
	cout << "欧式看跌期权的价格（内含有限差分法）" << option_price_put_european_finite_diff_implicit(S, X, r, sigma, time, no_S_steps, no_t_steps) << endl;
	return 0;
}