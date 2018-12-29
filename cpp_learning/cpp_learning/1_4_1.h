#pragma once
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double dividend_discount_model(const vector<double>& dividend_times, const vector<double>& dividend_amounts, const double& r)
{
	double value = 0.0;
	for (int t = 0; t < dividend_times.size(); t++)
	{
		value += dividend_amounts[t] / pow(1.0 + r, dividend_times[t]);
	}
	return value;
}

int mf()
{
	double r = 0.05;
	vector<double> dividend_amounts;
	dividend_amounts.push_back(0.1);
	dividend_amounts.push_back(0.2);
	dividend_amounts.push_back(0.5);
	dividend_amounts.push_back(0.5);
	dividend_amounts.push_back(0.8);
	dividend_amounts.push_back(0.6);
	dividend_amounts.push_back(0.7);
	vector<double> dividend_times;
	dividend_times.push_back(1);
	dividend_times.push_back(2);
	dividend_times.push_back(3);
	dividend_times.push_back(4);
	dividend_times.push_back(5);
	dividend_times.push_back(6);
	dividend_times.push_back(7);
	cout << "¹ÉÆ±¼Û¸ñ£º";
	cout << dividend_discount_model(dividend_times, dividend_amounts, r) << endl;
	return 0;
}