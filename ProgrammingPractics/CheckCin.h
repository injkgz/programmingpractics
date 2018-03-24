#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"

using namespace std;
// isWhole ����� ��� ����, ����� ����������� ������� ��� ������������� ��������; 
inline double CheckCin(bool isWhole)
{
	string stringForCheck;
	double correctValue;
	do
	{
		cin >> stringForCheck;

		if (stringForCheck == "0")
		{
			return 0;
		}

		correctValue = atof(stringForCheck.c_str());

		if (correctValue == 0)
		{
			cout << endl << "�� ����� �������� ��������! ���������� ��� ���!" << endl;
		}

		if (isWhole)
		{
			correctValue = nearbyint(correctValue);
		}
	} 
	while (correctValue == 0);
	return correctValue;
}

inline void GetPause()
{
	cout << endl;
	system("pause");
}
