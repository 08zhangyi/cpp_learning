#pragma once
#include <math.h>
#include <iostream>

double coupon_bond_price(const double& times, const double& face_value, const double& r)
{
	double bondprice = 0.0;
	bondprice = face_value / pow(1.0 + r, times);
	return bondprice;
}

int mf()
{
	double r = 0.04;
	double face_value = 1000;
	double times = 16;
	std::cout << "Õ®È¯¼Û¸ñ£º";
	std::cout << coupon_bond_price(times, face_value, r) << std::endl;
	return 0;
}