#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double pv_dividend(const vector<double>& dividend, const vector<double>& times, const vector<double>& r)
{
	double sum = 0.0;
	for (int i = 0; i < times.size(); i++)
	{
		sum += dividend[i] * exp(-r[i] * times[i]);
	}
	return sum;
}

double futures_value_payed_cash_dividene(const vector<double>& dividend, const vector<double>& times,
	const vector<double>& r, const double& S, const double& K, const double& r_finally, const double& time_to_maturity)
{
	double I = pv_dividend(dividend, times, r);
	return S - I - K * exp(-r_finally * time_to_maturity);
}

double futures_price_payed_cash_dividend(const vector<double>& dividend, const vector<double>& times,
	const vector<double>& r, const double& S, const double& r_finally, const double& time_to_maturity)
{
	double I = pv_dividend(dividend, times, r);
	return (S - I) * exp(r_finally * time_to_maturity);
}

int mf()
{
	double S = 900;
	double K = 910;
	double time_to_maturity = 1;

	vector<double> times;
	times.push_back(0.5);
	times.push_back(1.0);

	vector<double> dividend;
	dividend.push_back(60);
	dividend.push_back(60);

	vector<double> r;
	r.push_back(0.09);
	r.push_back(0.10);

	double r_finally = 0.10;

	cout << "远期的价格：" << futures_price_payed_cash_dividend(dividend, times, r, S, r_finally, time_to_maturity) << endl;
	cout << "远期的价值：" << futures_value_payed_cash_dividene(dividend, times, r, S, K, r_finally, time_to_maturity) << endl;
	return 0;
}