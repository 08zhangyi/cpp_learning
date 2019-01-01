#pragma once
#include "newmat10/newmat.h"
#include <iostream>

using namespace std;

ReturnMatrix mv_calculate_portfolio_weightg(const Matrix& V)
{
	int no_assets = V.Nrows();
	Matrix ones = Matrix(no_assets, 1);
	for (int i = 0; i < no_assets; ++i)
	{
		ones.element(i, 0) = 1;
	}
	Matrix Vinv = V.i();
	Matrix A = Vinv * ones;
	double a = A.element(0, 0);
	Matrix B = ones.t() * Vinv * ones;
	double b = B.element(0, 0);
	Matrix Binb = B.i();
	double binb = Binb.element(0, 0);
	Matrix C = A * Binb;
	double c = C.element(0, 0);
	C.Release();
	return C;
}

ReturnMatrix mv_calculate_portfolio_weightd(const Matrix& V, const Matrix& e)
{
	int no_assets = V.Nrows();
	Matrix ones = Matrix(no_assets, 1);
	for (int i = 0; i < no_assets; ++i)
	{
		ones.element(i, 0) = 1;
	}
	Matrix Vinv = V.i();
	Matrix A = Vinv * e;
	double a = A.element(0, 0);
	Matrix B = ones.t() * Vinv * e;
	double b = B.element(0, 0);
	Matrix Binb = B.i();
	double binb = Binb.element(0, 0);
	Matrix C = A * Binb;
	double c = C.element(0, 0);
	C.Release();
	return C;
}

int mf()
{
	Matrix V(2, 2);
	V.element(0, 0) = 1.0;
	V.element(1, 0) = 0.0;
	V.element(0, 1) = 0.0;
	V.element(1, 1) = 1.0;
	Matrix e(2, 1);
	e.element(0, 0) = 0.2;
	e.element(1, 0) = 0.5;
	Matrix wg = mv_calculate_portfolio_weightg(V);
	Matrix wd = mv_calculate_portfolio_weightd(V, e);

	cout << "wg1£º" << wg.element(0, 0) << endl;
	cout << "wg2£º" << wg.element(1, 0) << endl;
	cout << "wd1£º" << wd.element(0, 0) << endl;
	cout << "wd2£º" << wd.element(1, 0) << endl;
	return 0;
}