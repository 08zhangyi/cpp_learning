#pragma once
#include <math.h>
#include <iostream>
#include <vector>

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

double callable_bonds_yield_to_maturity_discrete(const vector<double>& times, const vector<double>& cashflows, const double& bondprice)
{
	const double ACCURACY = 1e-5;
	const int MAX_ITERATIONS = 200;
	double bot = 0, top = 1.0;
	while (bonds_price_discrete(times, cashflows, top) > bondprice)
	{
		top = top * 2;
	}
	double y = 0.5*(top + bot);
	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		double diff = bonds_price_discrete(times, cashflows, y) - bondprice;
		if (fabs(diff) < ACCURACY) return y;
		if (diff > 0.0) { bot = y; }
		else { top = y; }
		y = 0.5* (top + bot);
	}
	return y;
}

int mf()
{
	vector<double> cflows;
	cflows.push_back(30);
	cflows.push_back(30);
	cflows.push_back(30);
	cflows.push_back(30);
	cflows.push_back(30);
	cflows.push_back(30);
	cflows.push_back(30);
	cflows.push_back(30);
	cflows.push_back(30);
	cflows.push_back(1060);
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

	double r = 0.076;
	double B = bonds_price_discrete(times, cflows, r);

	cout << "债券价格：" << B << endl;
	cout << "到期收益率：" << 2 * callable_bonds_yield_to_maturity_discrete(times, cflows, B) << endl;
	return 0;
}