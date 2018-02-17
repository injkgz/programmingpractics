#include "stdafx.h"
#include <stdio.h>
int main()
{
	int a = 5;
	int b = 3;
	float z;
	// Неявное приведение типов
	z = a;
	printf("Value of z is %f \n", z);
	// Ошибка - невозможное приведение типов!
	a = z;
	// Явное приведение типов
	a = (int)z;
	printf("Value of a is %d \n", a);
	// Неявное приведение результата деления
	// целочисленных переменных
	z = a / b;
	printf("Value of z is %f \n", z);
	// Явное приведение а к float и неявное b к float
	// для выполнения деления
	z = ((float)a) / b;
	printf("Value of z is %f \n", z);
}