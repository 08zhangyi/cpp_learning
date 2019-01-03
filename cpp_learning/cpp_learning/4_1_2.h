#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

double security_market_line(const vector<double>& index, const vector<double>& portfolio, const vector<double>& times, const double& r)
{
	double sum1 = 0.0;
	double sum2 = 0.0;
	for (int i = 1; i < times.size(); i++)
	{
		sum1 += index[i];
		sum2 += portfolio[i];
	}
	double average1 = sum1 / (times.size() - 1);
	double average2 = sum2 / (times.size() - 1);
	double sum_1 = 0.0;
	double sum12 = 0.0;
	for (int j = 1; j < times.size(); j++)
	{
		sum_1 += (index[j] - average1) * (index[j] - average1);
		sum12 += (index[j] - average1) * (portfolio[j] - average2);
	}
	double sigma1 = sum_1 / (times.size() - 1);
	double cover = sum12 / (times.size() - 1);
	double pi = 1 / (1 + r) * (average2 - (average1 - (1 + r) * index[0]) * cover / sigma1);
	return pi;
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
	times.push_back(1);
	times.push_back(2);
	times.push_back(3);
	times.push_back(4);
	double r = 0.06;
	cout << "证券收益率：" << security_market_line(index, portfolio, times, r) << endl;
	return 0;
}