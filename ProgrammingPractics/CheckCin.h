#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

inline double CheckCin(bool isWhole) // isWhole нужен для того, чтобы программист выбирал тип возвращаемого значения; 
{
	string n;
	double m;

	do
	{

		cin >> n;
		if (n == "0") { return 0; }
		m = atof(n.c_str());
		if (isWhole ) { m = nearbyint(m); }
	} while (m == 0);
	return m;
}