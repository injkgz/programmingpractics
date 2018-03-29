#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include <tchar.h>
#include <string.h>
#include <stdio.h>
#include "lab1.h"
#include "lab2.h"
//lab3
#include "lab3.h"
#include "MenuLab3.h"
#include "DoubleLinkedList.h"
#include "Person.h"
#include "Sex.h"
#include "Node.h"
//lab4
#include "Stack.h"
#include "StackPerson.h"
#include "MenuLab4.h"
#include "List.h"
#include "MenuStack.h"
#include "MenuList.h"
//lab5
#include "Person5.h"
#include "PersonList.h"
#include "PersonListItem.h"
#include "lab5UI.h"
#include "PersonTools.h"
#include <cctype>



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
