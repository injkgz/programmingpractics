#include "stdafx.h"
#include <stdio.h>
int main()
{
	int value;
	int* pointer; // Объявление указателя на целочисленный тип данных
	int anotherValue;
	value = 5;
	pointer = &value; // Операция взятия адреса переменной
					  // pointer может хранить адрес только
					  // целочисленной переменной
	anotherValue = *pointer; // Операция разыменования
							 // Вывод значения, полученного при разыменовании указателя
	printf("Value, stored in pointer: %d \n", anotherValue);
	// Вывод адреса, который хранится в указателе
	printf("Address in pointer: %p \n", pointer);
	// Вывод результата разыменования указателя
	printf("Value in pointer: %d \n", *pointer);
}