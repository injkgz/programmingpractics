﻿#include "lab1.h"


// Расчёт и вывод суммы непроизвольных чисел
void GetSumm()
{
	int a = 5;
	int b = 3;

	cout << "Hello, World!\n";
	cout << "\n Variable a equals " << a;
	cout << "\n Variable b equals " << b;
	cout << "\n Summ of a and b equal = " << a + b;
}
// Расчёт и вывод результата деления непроизвольных чисел
void GetDivision()
{
	int a = 5;
	int b = 3;

	float z = 5.0;
	float y = 3.0;

	cout << "Float variables division: \n" << z / y;
	cout << endl << "Integer variables division:\n" << a / b;
}

// Расчёт и вывод суммы произвольных чисел, вводимых пользователем
void GetSummArbitrary()
{
	// Вводимые пользователем значения
	int a;
	int b;

	cout << "-- - Program for integer summation-- - ";
	cout << "\n\n Enter first integer value: ";
	a = CheckCin(true);
	cout << "\n\n Enter second integer value: ";
	b = CheckCin(true);
	cout << " \n Summ of " << a << "+" << b << " and equals=" << a + b;
}

// Работа с указателями и вывод адресов ячеек памяти
void PointerInstruments()
{
	int value;
	int* pointer;
	int anotherValue;


	value = 5;
	pointer = &value; // для просмотра адреса ячейки переменной value
	anotherValue = *pointer; //  для вывода значения хранящегося по адресу указателя

	cout << "Value, stored in pointer: " << anotherValue << endl;
	cout << "Address in pointer: " << pointer << endl;
	cout << "Value in pointer:" << *pointer << endl;
}
// Проверка произвольных значений, вводимых пользователем, на чётность и нечётность
void CheckEvenOdd()
{
	int a;

	cout << "Enter value for check on even/odd: ";
	cin >> a;

	if (a % 2 == 0)
	{
		cout << "\n Value is " << a << " even!";
	}
	else
	{
		cout << "\n Value is " << a << " odd!";
	}
}
// Проверка на кратность 5 и 2 значений, введённых пользователем
void MultiplicationCheck()
{
	int a;

	cout << "Enter value for check on even/odd: ";
	cin >> a;
	if (a % 5 == 0)
	{
		cout << "\n Value " << a << " multiples 5!" << endl;;
	}
	else if (a % 2 == 0)
	{
		cout << "\n Value " << a << " multiples 2!" << endl;
	}
	else
	{
		cout << "\n Value " << a << " doesn`t multiply 5 or 2!" << endl;
	}
}
// Использование цикла с предусловием
void CycleWithPrecondition()
{
	int a = 0;

	while (a < 5)
	{
		cout << "Value is " << a << " now \n";
		a++;
	}
}
// Использование цикла с постусловием
void CycleWithPothcondition()
{
	int a = 0;

	do
	{
		cout << "Value is " << a << " now \n";
		a++;
	} while (a < 5);
}
// Использование цикла с итерацией
void IterationCycle()
{
	int a = 10;

	for (int i = 0; i < 10; i++)
	{
		cout << "Iteration =" << i << endl;
	}

	cout << endl << endl;

	for (int i = 0; i < a; i++)
	{
		a--;
		cout << "Iteration " << i << "   Value is " << a << endl;;
	}
}
// Использование оператора break для прерывания цикла
void BreakingCycle()
{
	int a = 10;

	for (int i = 0; i < 10; ++i)
	{
		a--;
		if (i >= a)
		{
			cout << endl << "I is more or equal A! Break of cycle";
			break;
		}
	}
	cout << "\n A is " << a;
}
// Преобразование float и integer в друг друга
void IntegerFloatTransformation()
{
	int a = 5;
	int b = 3;

	float z;

	z = a;
	cout << endl << "Value of z is " << z << endl;
	a = (int)z;
	cout << endl << "Value of a is \n" << a << endl;
	z = a / b;
	cout << endl << "Value of z is \n" << z << endl;
	z = ((float)a) / b;
	cout << endl << "Value of z is \n" << z << endl;
}
// Функция выбора заданий из лабораторной работы #1
void FirstChooseMenu()
{
	bool key = true;
	int choosedFunction;

	while (key)
	{
		system("cls");
		cout << endl
			<< "Введите 1 для выхода в меню выбора лабораторной работы или выберите задание от 2 до 13"
			<< endl
			<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
			<< endl;
		choosedFunction = CheckCin(true);
		switch (choosedFunction)
		{
		case 1:
			key = false;
			cout << endl << "Выход из программы." << endl;
			system("pause");
			break;
		case 2: GetSumm(); break;
		case 3: GetSumm(); break;
		case 4: GetDivision(); break;
		case 5: GetSummArbitrary(); break;
		case 6: PointerInstruments(); break;
		case 7: CheckEvenOdd(); break;
		case 8: MultiplicationCheck(); break;
		case 9: CycleWithPrecondition(); break;
		case 10: CycleWithPothcondition(); break;
		case 11: IterationCycle(); break;
		case 12: BreakingCycle(); break;
		case 13: IntegerFloatTransformation(); break;
		default: break;
		}
		if (choosedFunction>1)
			GetPause();

	}
}
