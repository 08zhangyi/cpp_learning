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

double bond_convexity_discrete(const vector<double>& times, const vector<double>& cashflows, const double& y)
{
	double Cx = 0.0;
	for (int t = 0; t < times.size(); t++)
	{
		Cx += cashflows[t] * times[t] * (times[t] + 1) / pow(1 + y, times[t]);
	}
	double B = bonds_price_discrete(times, cashflows, y);
	return Cx / (pow(1 + y, 2)) / B;
}

int mf()
{
	vector<double> cflows;
	cflows.push_back(10);
	cflows.push_back(10);
	cflows.push_back(110);
	vector<double> times;
	times.push_back(1);
	times.push_back(2);
	times.push_back(3);

	double y = 0.09;
	cout << "ծȯ͹�ԣ�" << bond_convexity_discrete(times, cflows, y) << endl;
	return 0;
}