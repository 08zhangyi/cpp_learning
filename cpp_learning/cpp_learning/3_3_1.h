#pragma once
#include "newmat10/newmat.h"
#include <iostream>

using namespace std;

ReturnMatrix weight_calculate_portpolio_given_mean_unconstrained(const Matrix& V, const Matrix& e, const double& u)
{
	int no_assets = e.Nrows();
	Matrix ones = Matrix(no_assets, 1);
	Matrix Vinv = V.i();
	for (int i = 0; i < no_assets; ++i)
	{
		ones.element(i, 0) = 1;
	}
	Matrix A = ones.t() * Vinv * ones;
	double a = A.element(0, 0);
	Matrix B = ones.t() * Vinv * e;
	double b = B.element(0, 0);
	Matrix C = e.t() * Vinv * e;
	double c = C.element(0, 0);
	Matrix D = A * C - B * B;
	double d = D.element(0, 0);
	Matrix g = Vinv * (c*ones - b * e)*(1.0 / d);
	Matrix h = Vinv * (a*e - b * ones) * (1.0 / d);
	Matrix w = g + h * u;
	w.Release();
	return w;
}

ReturnMatrix var_calculate_portpolio_variance(const Matrix& V, const Matrix& e, const double& u)
{
	int no_assets = e.Nrows();
	Matrix ones = Matrix(no_assets, 1);
	for (int i = 0; i < no_assets; ++i)
	{
		ones.element(i, 0) = 1;
	}
	Matrix Vinv1 = V.i();
	Matrix A = ones.t() * Vinv1 * ones;
	double a = A.element(0, 0);
	Matrix B = ones.t() * Vinv1 * e;
	double b = B.element(0, 0);
	Matrix C = e.t() * Vinv1 * e;
	double c = C.element(0, 0);
	Matrix D = A * C - B * B;
	double d = D.element(0, 0);
	Matrix Var = (a*u*u - 2 * b*u + c)*D.i();
	double var = Var.element(0, 0);
	Var.Release();
	return Var;
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
	double u = 0.075;
	Matrix w = weight_calculate_portpolio_given_mean_unconstrained(e, V, u);
	cout << "w1£º" << w.element(0, 0) << endl;
	cout << "w2£º" << w.element(1, 0) << endl;
	return 0;
}