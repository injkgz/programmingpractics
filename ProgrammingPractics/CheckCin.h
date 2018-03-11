#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "lab1.h"
#include "lab2.h"

using namespace std;
// isWhole нужен для того, чтобы программист выбирал тип возвращаемого значения; 
inline double CheckCin(bool isWhole)
{
	string n;
	double m;
//TODO: Внимательно прочитайте стандарт оформления кода RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: и приведите свой код в соответстие со стандартом
	do
	{
		cin >> n;
		if (n == "0") { return 0; }
		m = atof(n.c_str());
		if (isWhole)
			m = nearbyint(m);
	} while (m == 0);
	return m;
}

inline void GetPause()
{
	cout << endl;
	system("pause");
}
