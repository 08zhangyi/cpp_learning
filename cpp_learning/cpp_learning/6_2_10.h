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

double option_price_call_american_binomial(const double& S, const double& X, const double& r,
	const double& sigma, const double& time, const int& steps)
{
	double R = exp(r*(time / steps));
	double Rinv = 1.0 / R;
	double u = exp(sigma*sqrt(time / steps));
	double uu = u * u;
	double d = 1.0 / u;
	double p_up = (R - d) / (u - d);
	double p_down = 1.0 - p_up;
	vector<double> prices(steps + 1);
	vector<double> call_values(steps + 1);
	prices[0] = S * pow(d, steps);
	for (int i = 1; i <= steps; ++i)
		prices[i] = uu * prices[i - 1];
	for (int j = 0; j <= steps; j++)
		call_values[j] = max(0.0, (prices[j] - X));
	for (int step = steps - 1; step >= 0; --step)
	{
		for (int i = 0; i <= step; ++i)
		{
			call_values[i] = (p_up * call_values[i + 1] + p_down * call_values[i]) * Rinv;
			prices[i] = d * prices[i + 1];
			call_values[i] = max(call_values[i], prices[i] - X);
		}
	}
	return call_values[0];
}

double option_price_put_american_binomial(const double& S, const double& X, const double& r,
	const double& sigma, const double& time, const int& steps)
{
	double R = exp(r*(time / steps));
	double Rinv = 1.0 / R;
	double u = exp(sigma*sqrt(time / steps));
	double uu = u * u;
	double d = 1.0 / u;
	double p_up = (R - d) / (u - d);
	double p_down = 1.0 - p_up;
	vector<double> prices(steps + 1);
	vector<double> put_values(steps + 1);
	prices[0] = S * pow(d, steps);
	for (int i = 1; i <= steps; ++i)
		prices[i] = uu * prices[i - 1];
	for (int j = 0; j <= steps; j++)
		put_values[j] = max(0.0, (X - prices[j]));
	for (int step = steps - 1; step >= 0; --step)
	{
		for (int i = 0; i <= step; ++i)
		{
			put_values[i] = (p_up * put_values[i + 1] + p_down * put_values[i]) * Rinv;
			prices[i] = d * prices[i + 1];
			put_values[i] = max(put_values[i], X - prices[i]);
		}
	}
	return put_values[0];
}


void option_price_partials_american_call_binomial(const double& S, const double& X, const double& r,
	const double& sigma, const double& time, const int& no_steps,
	double& delta, double& gamma, double& theta, double& vega, double& rho)
{
	vector<double> prices(no_steps + 1);
	vector<double> call_values(no_steps + 1);
	double t_delta = time / no_steps;
	double R = exp(r*t_delta);
	double Rinv = 1.0 / R;
	double u = exp(sigma*sqrt(t_delta));
	double d = 1.0 / u;
	double uu = u * u;
	double pUp = (R - d) / (u - d);
	double pDown = 1.0 - pUp;
	prices[0] = S * pow(d, no_steps);
	int i;
	for (i = 1; i <= no_steps; ++i)
		prices[i] = uu * prices[i - 1];
	for (i = 0; i <= no_steps; ++i)
		call_values[i] = max(0.0, (prices[i] - X));
	for (int CurrStep = no_steps - 1; CurrStep >= 2; --CurrStep)
	{
		for (i = 0; i <= CurrStep; ++i)
		{
			prices[i] = d * prices[i + 1];
			call_values[i] = (pDown * call_values[i] + pUp * call_values[i + 1])*Rinv;
			call_values[i] = max(call_values[i], prices[i] - X);
		}
	}
	double f22 = call_values[2];
	double f21 = call_values[1];
	double f20 = call_values[0];
	for (i = 0; i <= 1; i++)
	{
		prices[i] = d * prices[i + 1];
		call_values[i] = (pDown * call_values[i] + pUp * call_values[i + 1])*Rinv;
		call_values[i] = max(call_values[i], prices[i] - X);
	}
	double f11 = call_values[1];
	double f10 = call_values[0];
	prices[0] = d * prices[1];
	call_values[0] = (pDown*call_values[0] + pUp * call_values[1]) * Rinv;
	call_values[0] = max(call_values[0], S - X);

	double f00 = call_values[0];
	delta = (f11 - f10) / (S*u - S * d);
	double h = 0.5 * S * (uu - d * d);
	gamma = ((f22 - f21) / (S*(uu - 1)) - (f21 - f20) / (S*(1 - d * d))) / h;
	theta = (f21 - f00) / (2 * t_delta);
	double diff = 0.02;
	double tmp_sigma = sigma + diff;
	double tmp_prices = option_price_call_american_binomial(S, X, r, tmp_sigma, time, no_steps);
	vega = (tmp_prices - f00) / diff;
	diff = 0.05;
	double tmp_r = r + diff;
	tmp_prices = option_price_call_american_binomial(S, X, tmp_r, sigma, time, no_steps);
	rho = (tmp_prices - f00) / diff;
}

void option_price_partials_american_put_binomial(const double& S, const double& X, const double& r,
	const double& sigma, const double& time, const int& no_steps,
	double& delta, double& gamma, double& theta, double& vega, double& rho)
{
	vector<double> prices(no_steps + 1);
	vector<double> put_values(no_steps + 1);
	double t_delta = time / no_steps;
	double R = exp(r*t_delta);
	double Rinv = 1.0 / R;
	double u = exp(sigma*sqrt(t_delta));
	double d = 1.0 / u;
	double uu = u * u;
	double pUp = (R - d) / (u - d);
	double pDown = 1.0 - pUp;
	prices[0] = S * pow(d, no_steps);
	int i;
	for (i = 1; i <= no_steps; ++i)
		prices[i] = uu * prices[i - 1];
	for (i = 0; i <= no_steps; ++i)
		put_values[i] = max(0.0, (X - prices[i]));
	for (int CurrStep = no_steps - 1; CurrStep >= 2; --CurrStep)
	{
		for (i = 0; i <= CurrStep; ++i)
		{
			prices[i] = d * prices[i + 1];
			put_values[i] = (pDown * put_values[i] + pUp * put_values[i + 1])*Rinv;
			put_values[i] = max(put_values[i], X - prices[i]);
		}
	}
	double f22 = put_values[2];
	double f21 = put_values[1];
	double f20 = put_values[0];
	for (i = 0; i <= 1; i++)
	{
		prices[i] = d * prices[i + 1];
		put_values[i] = (pDown * put_values[i] + pUp * put_values[i + 1])*Rinv;
		put_values[i] = max(put_values[i], X - prices[i]);
	}
	double f11 = put_values[1];
	double f10 = put_values[0];
	prices[0] = d * prices[1];
	put_values[0] = (pDown*put_values[0] + pUp * put_values[1]) * Rinv;
	put_values[0] = max(put_values[0], X - S);

	double f00 = put_values[0];
	delta = (f11 - f10) / (S*u - S * d);
	double h = 0.5 * S * (uu - d * d);
	gamma = ((f22 - f21) / (S*(uu - 1)) - (f21 - f20) / (S*(1 - d * d))) / h;
	theta = (f21 - f00) / (2 * t_delta);
	double diff = 0.02;
	double tmp_sigma = sigma + diff;
	double tmp_prices = option_price_put_american_binomial(S, X, r, tmp_sigma, time, no_steps);
	vega = (tmp_prices - f00) / diff;
	diff = 0.05;
	double tmp_r = r + diff;
	tmp_prices = option_price_put_american_binomial(S, X, tmp_r, sigma, time, no_steps);
	rho = (tmp_prices - f00) / diff;
}

int mf()
{
	double S = 100.0;
	double X = 100.0;
	double r = 0.1;
	double sigma = 0.25;
	double time = 1.0;
	int no_steps = 100;

	double delta, gamma, theta, vage, rho;
	option_price_partials_american_put_binomial(S, X, r, sigma, time, no_steps, delta, gamma, theta, vage, rho);
	cout << "Delta=" << delta << endl;
	cout << "Gamma=" << gamma << endl;
	cout << "Theta=" << theta << endl;
	cout << "Vega=" << vage << endl;
	cout << "Rho=" << rho << endl;
	return 0;
}