#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;
double bond_price_discrete(const vector<double>& times, const vector<double>& cashflow, const double& r)
{
	double price = 0.0;
	for (int i = 0; i < times.size(); i++)
	{
		price += cashflow[i] / pow(1.0 + r, times[i]);
	}
	return price;
}

int mf()
{
	double r = 0.09;
	vector<double> cflows;
	cflows.push_back(10);
	cflows.push_back(10);
	cflows.push_back(110);

	vector<double> times;
	times.push_back(1);
	times.push_back(2);
	times.push_back(3);

	double B = bond_price_discrete(times, cflows, r);

	cout << "Õ®È¯¼Û¸ñ£º" << B << endl;
	return 0;
}