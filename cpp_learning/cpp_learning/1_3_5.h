#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double bonds_price_discrete(const vector<double>& times, const vector<double>& cashflows, const double& y)
{
	double p = 0;
	for (int i = 0; i < times.size(); i++)
	{
		p += cashflows[i] / (pow(1 + y, times[i]));
	}
	return p;
}

double bonds_duration_discrete(const vector<double>& cashflow_times, const vector<double>& cashflows, const double& y)
{
	double bond_price = 0.0;
	double D = 0.0;
	for (int i = 0; i < cashflow_times.size(); i++)
	{
		D += cashflow_times[i] * cashflows[i] / pow(1 + y, cashflow_times[i]);
		bond_price += cashflows[i] / pow(1 + y, cashflow_times[i]);
	}
	return D / bond_price;
}

int mf()
{
	vector<double> cflows;
	cflows.push_back(5);
	cflows.push_back(5);
	cflows.push_back(5);
	cflows.push_back(5);
	cflows.push_back(5);
	cflows.push_back(5);
	cflows.push_back(5);
	cflows.push_back(5);
	cflows.push_back(5);
	cflows.push_back(105);
	vector<double> times;
	times.push_back(1);
	times.push_back(2);
	times.push_back(3);
	times.push_back(4);
	times.push_back(5);
	times.push_back(6);
	times.push_back(7);
	times.push_back(8);
	times.push_back(9);
	times.push_back(10);

	double y = 0.09;
	double B = bonds_price_discrete(times, cflows, y);
	cout << "Õ®È¯¾ÃÆÚ£º" << bonds_duration_discrete(times, cflows, y) << endl;
	return 0;
}