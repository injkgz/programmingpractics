// 23.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	printf("Hello, World!\n");

	//3
	int a; // Объявление целочисленной переменной
	a = 5; // Инициализация переменной значением
	int b = 3; // Допустимо одновременное объявление и инициализация
	printf("\n Variable a equals %d", a); // Вывод значения переменной на экран
	printf("\n Variable b equals %d", b); // Значение переменной подставится вместо %d
	printf("\n Summ of a and b equals %d", a + b); // Можно выводить сразу
												   // результат сложения

    return 0;
}

