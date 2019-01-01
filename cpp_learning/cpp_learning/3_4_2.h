#pragma once
#include "newmat10/newmat.h"
#include <iostream>

using namespace std;

ReturnMatrix mv_calculate_portfolio_variance(const Matrix& V, const Matrix& e, const double& u, const double& r)
{
	int no_assets = e.Nrows();
	Matrix ones = Matrix(no_assets, 1);
	for (int i = 0; i < no_assets; ++i)
	{
		ones.element(i, 0);
	}
	Matrix Vinv1 = V.i();
	Matrix A = ones.t() * Vinv1 * ones;
	double a = A.element(0, 0);
	Matrix B = ones.t() * Vinv1 * e;
	double b = B.element(0, 0);
	Matrix C = e.t() * Vinv1 * e;
	double c = C.element(0, 0);
	Matrix Vinv2 = B - A * r;
	double vinv2 = Vinv2.element(0, 0);
	Matrix MV = (C - B * r) * Vinv2.i();
	double mv = MV.element(0, 0);
	MV.Release();
	return MV;
}

ReturnMatrix var_calculate_portfolio_variance(const Matrix& V, const Matrix& e, const double& u, const double& r)
{
	int no_assets = e.Nrows();
	Matrix ones = Matrix(no_assets, 1);
	for (int i = 0; i < no_assets; ++i)
	{
		ones.element(i, 0);
	}
	Matrix Vinv1 = V.i();
	Matrix A = ones.t() * Vinv1 * ones;
	double a = A.element(0, 0);
	Matrix B = ones.t() * Vinv1 * e;
	double b = B.element(0, 0);
	Matrix C = e.t() * Vinv1 * e;
	double c = C.element(0, 0);
	Matrix Vinv2 = (B - A * r) * (B - A * r);
	double vinv2 = Vinv2.element(0, 0);
	Matrix Var = (C - 2 * r * B + r * r * A) * Vinv2.i();
	double var = Var.element(0, 0);
	Var.Release();
	return Var;
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
	double u = 0.2;
	double r = 0.1;
	Matrix MV = mv_calculate_portfolio_variance(V, e, u, r);
	cout << "¾ùÖµ£º" << MV.element(0, 0) << endl;
	Matrix Var = var_calculate_portfolio_variance(V, e, u, r);
	cout << "·½²î£º" << Var.element(0, 0) << endl;
	return 0;
}