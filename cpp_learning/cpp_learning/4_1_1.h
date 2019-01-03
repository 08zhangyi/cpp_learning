#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double security_market_line(const vector<double>& index, const vector<double>& portfolio, const vector<double>& times, const double& r)
{
	vector<double> yield1(times.size());
	vector<double> yield2(times.size());
	int i;
	double sum1 = 0.0;
	double sum2 = 0.0;
	for (i = 1; i < times.size(); i++)
	{
		yield1[i] = (index[i] - index[i - 1]) / index[i - 1];
		yield2[i] = (portfolio[i] - portfolio[i - 1]) / portfolio[i - 1];
		sum1 += yield1[i];
		sum2 += yield2[i];
	}
	double average1 = sum1 / (times.size() - 1);
	double average2 = sum2 / (times.size() - 1);
	double sum_1 = 0.0;
	double sum_2 = 0.0;
	double sum12 = 0.0;
	for (i = 1; i < times.size(); i++)
	{
		yield1[i] = (index[i] - index[i - 1]) / index[i - 1];
		yield2[i] = (portfolio[i] - portfolio[i - 1]) / portfolio[i - 1];
		sum_1 += (yield1[i] - average1) * (yield1[i] - average1);
		sum_2 += (yield2[i] - average2) * (yield2[i] - average2);
		sum12 += (yield1[i] - average1) * (yield2[i] - average2);
	}
	double sigma1 = sum_1 / (times.size() - 1);
	double sigma2 = sum_2 / (times.size() - 1);
	double cover = sum12 / (times.size() - 1);
	double bata = cover / sigma1;
	double ri = r + (average1 - r) * bata;
	return ri;
}

int mf()
{
	vector<double> index;
	index.push_back(1500);
	index.push_back(1600);
	index.push_back(1800);
	index.push_back(2100);
	vector<double> portfolio;
	portfolio.push_back(6.24);
	portfolio.push_back(6.38);
	portfolio.push_back(6.26);
	portfolio.push_back(6.30);
	vector<double> times;
	times.push_back(0);
	times.push_back(1);
	times.push_back(3);
	times.push_back(4);
	double r = 0.06;
	cout << "证券收益率：" << security_market_line(index, portfolio, times, r) << endl;
	return 0;
}