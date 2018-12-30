#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double swap_pricing_bonds_portfolio(const vector<double>& times, const vector<double>& cashflows, const vector<double>& r, const double& Q, const double& floating_rate, const double& time)
{
	double B1 = 0.0;
	double B2 = 0.0;
	for (int t = 0; t < times.size(); t++)
	{
		B1 += cashflows[t] / exp(r[t] * times[t]);
	}
	B2 = Q / exp(floating_rate * time);
	return B2 - B1;
}

int mf()
{
	vector<double> times;
	times.push_back(0.25);
	times.push_back(0.75);
	times.push_back(1.25);
	vector<double> cashflows;
	cashflows.push_back(4);
	cashflows.push_back(4);
	cashflows.push_back(104);
	vector<double> r;
	r.push_back(0.1);
	r.push_back(0.105);
	r.push_back(0.11);
	double Q = 105.1;
	double floating_rate = 0.1;
	double time = 0.25;
	cout << "利率互换的价值：" << swap_pricing_bonds_portfolio(times, cashflows, r, Q, floating_rate, time) << endl;
	return 0;
}