#pragma once
#include <math.h>
#include <iostream>

using namespace std;

double futures_price_for_longterm_bond(const double& S, const double& I, const double& r, const double& time_to_maturity)
{
	return (S - I) * exp(r * time_to_maturity);
}

int mf()
{
	double S = 121.98;
	double I = 5.803;
	double r = 0.1;
	double time_to_maturity = 2;
	cout << "中长期国债期货的价格：" << futures_price_for_longterm_bond(S, I, r, time_to_maturity) << endl;
	return 0;

}