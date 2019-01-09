#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double max(double x, double y)
{
	if (x > y)
		return x;
	else
		return y;
}

double option_price_call_european_finite_diff_explicit(const double& S, const double& X, const double& r, const double& sigma, const double& time,
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

	vector<double> a(M);
	vector<double> b(M);
	vector<double> c(M);

	double r1 = 1.0 / (1.0 + r * delta_t);
	double r2 = delta_t / (1.0 + r * delta_t);
	for (unsigned int j = 1; j < M; j++)
	{
		a[j] = r2 * 0.5 * j * (-r + sigma_sqr);
		b[j] = r1 * (1.0 - sigma_sqr * j*j*delta_t);
		c[j] = r2 * 0.5*j*(r + sigma_sqr * j);
	}
	vector<double> f_next(M + 1);
	for (unsigned int n = 0; n <= M; ++n)
		f_next[n] = max(0.0, S_values[n] - X);
	vector<double> f(M + 1);
	for (int t = N - 1; t >= 0; --t)
	{
		f[0] = 0;
		for (unsigned m = 1; m < M; ++m)
			f[m] = a[m] * f_next[m - 1] + b[m] * f_next[m] + c[m] * f_next[m + 1];
		f[M] = 0;
		for (unsigned n = 0; n <= M; ++n)
			f_next[n] = f[n];
	}
	return f[M / 2];
}

double option_price_put_european_finite_diff_explicit(const double& S, const double& X, const double& r, const double& sigma, const double& time,
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

	vector<double> a(M);
	vector<double> b(M);
	vector<double> c(M);

	double r1 = 1.0 / (1.0 + r * delta_t);
	double r2 = delta_t / (1.0 + r * delta_t);
	for (unsigned int j = 1; j < M; j++)
	{
		a[j] = r2 * 0.5 * j * (-r + sigma_sqr);
		b[j] = r1 * (1.0 - sigma_sqr * j*j*delta_t);
		c[j] = r2 * 0.5*j*(r + sigma_sqr * j);
	}
	vector<double> f_next(M + 1);
	for (unsigned int n = 0; n <= M; ++n)
		f_next[n] = max(0.0, X - S_values[n]);
	vector<double> f(M + 1);
	for (int t = N - 1; t >= 0; --t)
	{
		f[0] = 0;
		for (unsigned m = 1; m < M; ++m)
			f[m] = a[m] * f_next[m - 1] + b[m] * f_next[m] + c[m] * f_next[m + 1];
		f[M] = 0;
		for (unsigned n = 0; n <= M; ++n)
			f_next[n] = f[n];
	}
	return f[M / 2];
}

int mf()
{
	double S = 50.0;
	double X = 50.0;
	double r = 0.1;
	double sigma = 0.4;
	double time = 0.4167;
	int no_S_steps = 20;
	int no_t_steps = 11;
	cout << "欧式看涨期权的价格" << option_price_call_european_finite_diff_explicit(S, X, r, sigma, time, no_S_steps, no_t_steps) << endl;
	cout << "欧式看跌期权的价格" << option_price_put_european_finite_diff_explicit(S, X, r, sigma, time, no_S_steps, no_t_steps) << endl;
	return 0;
}