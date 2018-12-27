#pragma once
#include <math.h>
#include <iostream>

void discount_function_discrete(double& times, double& r, double& at_1, double& at_2)
{
	at_1 = pow(1.0 + r * times, -1);
	at_2 = 1 / pow(1.0 + r, times);
}

int mf()
{
	double r = 0.05;
	double times = 10;
	double at_1, at_2;
	discount_function_discrete(times, r, at_1, at_2);

	std::cout << "�������ֺ���ֵ��" << at_1 << std::endl;
	std::cout << "�������ֺ���ֵ��" << at_2 << std::endl;
	return 0;
}