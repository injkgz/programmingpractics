#include "stdafx.h"
#include <stdio.h>
int main()
{
	int a;
	int b;
	// Вывод текстового сообщения, поясняющего назначение программы
	// является правилом хорошего тона и помогает пользователю
	// разобраться в вашей программе
	printf("---Program for integer summation---");
	// Всегда поясняйте пользователю, какие данные ему нужно ввести
	printf("\n\n Enter first integer value: ");
	scanf_s("%d", &a); // Чтение значения переменной с клавиатуры
	printf(" Enter second integer value: ");
	scanf_s("%d", &b);
	printf(" \n Summ of %d and %d equals %d \n", a, b, a + b);
}