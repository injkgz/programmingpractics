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
	string n;
	double m;
//TODO: ����������� ���������� �������� ���������� ���� RSDN https://rsdn.org/article/mag/200401/codestyle.XML
//TODO: � ��������� ���� ��� � ����������� �� ����������
	//�������
	//TODO: ���. �� ��� ���������� ���������� ����������. ���� ������ �������������� �� RSDN.
	do
	{
		cin >> n;
		if (n == "0") { return 0; }
		m = atof(n.c_str());
		if (isWhole)
		m = nearbyint(m);
	} 
	while (m == 0);
	return m;
}

inline void GetPause()
{
	cout << endl;
	system("pause");
}
