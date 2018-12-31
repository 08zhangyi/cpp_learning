#pragma once
#include <vector>
#include <iostream>

using namespace std;

double average(const vector<double>& data_amounts, const vector<double>& data_times) 
{
	vector<double> yield(data_times.size());
	int i;
	double sum = 0.0;
	for (i = 1; i < data_times.size(); i++)
	{
		yield[i] = (data_amounts[i] - data_amounts[i - 1]) / data_amounts[i - 1];
		sum += yield[i];
	}
	double average = sum/(data_times.size() - 1);
	return average;
}

double variance(const vector<double>& data_amount, const vector<double>& data_times)
{
	vector<double> yield(data_times.size());
	int i;
	double sum_1 = 0.0;
	double sum_2 = 0.0;
	for (i = 1; i < data_amount.size(); i++)
	{
		yield[i] = (data_amount[i] - data_amount[i - 1]) / data_amount[i - 1];
		sum_1 += yield[i];
	}
	double average = sum_1 / (data_times.size() - 1);
	for (i = 1; i < data_amount.size(); i++)
	{
		yield[i] = (data_amount[i] - data_amount[i - 1]) / data_amount[i - 1];
		sum_2 += (yield[i] - average) * (yield[i] - average);
	}
	double var = sum_2 / (data_times.size() - 1);
	return var;
}

int mf()
{
	vector<double> data_amounts;
	data_amounts.push_back(6.24);
	data_amounts.push_back(6.25);
	data_amounts.push_back(6.47);
	data_amounts.push_back(6.76);
	data_amounts.push_back(7.01);
	data_amounts.push_back(6.76);
	data_amounts.push_back(6.47);
	data_amounts.push_back(6.45);
	data_amounts.push_back(6.56);
	data_amounts.push_back(7.22);
	vector<double> data_times;
	data_times.push_back(0);
	data_times.push_back(1);
	data_times.push_back(2);
	data_times.push_back(3);
	data_times.push_back(4);
	data_times.push_back(5);
	data_times.push_back(6);
	data_times.push_back(7);
	data_times.push_back(8);
	data_times.push_back(9);
	cout << "ÆÚÍû£º" << average(data_amounts, data_times) << endl;
	cout << "·½²î£º" << variance(data_amounts, data_times) << endl;
	return 0;
}