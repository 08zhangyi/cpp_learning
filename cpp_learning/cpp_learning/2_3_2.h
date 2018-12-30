#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double currency_swap_pricing(const double& S, const vector<double>& times, const vector<double>& cflows1, const vector<double>& cflows2, const double& y1, const double& y2)
{
	double Bf = 0.0;
	double Bd = 0.0;
	for (int i = 0; i < times.size(); i++)
	{
		Bf += cflows1[i] * exp(-y1 * times[i]);
		Bd += cflows2[i] * exp(-y2 * times[i]);
	}
	return S * Bf - Bd;
}

int mf()
{
	double S = 1 / 110;
	vector<double> times;
	times.push_back(1);
	times.push_back(2);
	times.push_back(3);
	vector<double> cflows1;
	cflows1.push_back(60.0);
	cflows1.push_back(60.0);
	cflows1.push_back(1260.0);
	vector<double> cflows2;
	cflows2.push_back(0.8);
	cflows2.push_back(0.8);
	cflows2.push_back(10.8);
	double y1 = 0.04;
	double y2 = 0.09;
	cout << "»¥»»¼ÛÖµ=" << currency_swap_pricing(S, times, cflows1, cflows2, y1, y2) << endl;
	return 0;
}