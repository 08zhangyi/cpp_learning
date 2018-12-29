#pragma once
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;
double more_cash_flow_pv_discrete(const vector<double>& cflow_times, const vector<double>& cflow_amounts, const double& r)
{
	double PV = 0.0;
	for (int t = 0; t < cflow_times.size(); t++)
	{
		PV += cflow_amounts[t] / pow(1.0 + r, cflow_times[t]);
	}
	return PV;
}

int mf()
{
	double r = 0.1;
	vector<double> cflow_amounts;
	cflow_amounts.push_back(100.0);
	cflow_amounts.push_back(200.0);
	cflow_amounts.push_back(300.0);
	cflow_amounts.push_back(400.0);
	cflow_amounts.push_back(500.0);
	vector<double> cflow_times;
	cflow_times.push_back(1);
	cflow_times.push_back(2);
	cflow_times.push_back(3);
	cflow_times.push_back(4);
	cflow_times.push_back(5);

	cout << "多期复利现值：";
	cout << more_cash_flow_pv_discrete(cflow_times, cflow_amounts, r) << endl;
	return 0;
}