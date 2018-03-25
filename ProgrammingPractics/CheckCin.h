#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include <tchar.h>
#include <string.h>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "DoubleLinkedList.h"


using namespace std;
// isWhole нужен для того, чтобы программист выбирал тип возвращаемого значения; 
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
			cout << endl << "Вы ввели неверное значение! Попробуйте ещё раз!" << endl;
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
