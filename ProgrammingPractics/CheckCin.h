#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"

using namespace std;
// isWhole нужен для того, чтобы программист выбирал тип возвращаемого значения; 
inline double CheckCin(bool isWhole)
{
	string stringForCheck;
	double correctValue;
//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: и приведите свой код в соответстие со стандартом
	//сделано
	//TODO: Нет. Всё ещё непонятное именование переменных. Есть ошибки форматирования по RSDN.
	do
	{
		cin >> stringForCheck;
		if (stringForCheck == "0")
		{ 
			return 0; 
		}
		correctValue = atof(stringForCheck.c_str());
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
