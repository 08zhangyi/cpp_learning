#pragma once
#include "newmat10/newmat.h"
#include <iostream>

using namespace std;

double investment_portfolio_variance(const Matrix& V, const Matrix& w)
{
	Matrix temp = w.t() * V * w;
	return temp.element(0, 0);
}

int mf()
{
	Matrix e(2, 1);
	e.element(0, 0) = 0.05;
	e.element(1, 0) = 0.1;
	Matrix V(2, 2);
	V.element(0, 0) = 1.0;
	V.element(1, 0) = 0.0;
	V.element(0, 1) = 0.0;
	V.element(1, 1) = 1.0;

	cout << "·½²î£º" << investment_portfolio_variance(V, e) << endl;
	return 0;
}