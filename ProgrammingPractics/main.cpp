#include <stdio.h>
#include <iostream>
#include <clocale>
#include "lab1.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	laba1();
	return 0;
}

//TODO: Незачем оставлять в программном коде портянки с закоментированным кодом!
//void zad23()
//{
//	cout << "Hello, World!\n";
//
//	//3
//	int a; // Объявление целочисленной переменной
//	a = 5; // Инициализация переменной значением
//	int b = 3; // Допустимо одновременное объявление и инициализация
//	cout << "\n Variable a equals " << a;// Вывод значения переменной на экран
//	cout << "\n Variable b equals " << b;// Значение переменной подставится вместо %d
//	cout << "\n Summ of a and b equal = " << a + b; // Можно выводить сразу
//													// результат сложения
//}
//void zad4()
//{
//	int a = 5;
//	int b = 3;
//	float z = 5.0;
//	float y = 3.0;
//	cout << "Float variables division: \n" << z / y;
//	cout <<endl<< "Integer variables division:\n" << a / b;
//
//}
//void zad5()
//{
//	int a;
//	int b;
//	// Вывод текстового сообщения, поясняющего назначение программы
//	// является правилом хорошего тона и помогает пользователю
//	// разобраться в вашей программе
//	cout<<"-- - Program for integer summation-- - ";
//	// Всегда поясняйте пользователю, какие данные ему нужно ввести
//	cout << "\n\n Enter first integer value: ";
//	cin >> a;
//	cout << "\n\n Enter second integer value: ";
//	cin >> b;
//	cout << " \n Summ of and equals \n" << a <<" "<< b <<" "<< a + b;
//	
//}
//void zad6() {
//	int value;
//	int* pointer; // Объявление указателя на целочисленный тип данных
//	int anotherValue;
//	value = 5;
//	pointer = &value; // Операция взятия адреса переменной
//					  // pointer может хранить адрес только
//					  // целочисленной переменной
//	anotherValue = *pointer; // Операция разыменования
//							 // Вывод значения, полученного при разыменовании указателя
//	cout << "Value, stored in pointer: " << anotherValue << endl;
//	// Вывод адреса, который хранится в указателе
//	cout << "Address in pointer: " << pointer << endl;
//	// Вывод результата разыменования указателя
//	cout << "Value in pointer:" << *pointer << endl;
//
//}
//void zad7() {
//	int a;
//	cout<<"Enter value for check on even/odd: ";
//	cin >> a;
//	if (a % 2 == 0)
//	{
//		cout<<"\n Value is "<<a<<" even!";
//	}
//	else
//	{
//		cout << "\n Value is " << a << " odd!";
//	}
//}
//void zad8(){
//	int a;
//	cout<<"Enter value for check on even/odd: ";
//	cin >> a;
//	if (a % 5 == 0)
//	{
//		cout << "\n Value " <<a<<" multiples 5!" << endl;;
//	}
//	else if (a % 2 == 0)
//	{
//		cout << "\n Value "<<a<<" multiples 2!"<<endl;
//	}
//	else
//	{
//		cout << "\n Value "<<a<<" doesn`t multiply 5 or 2!"<<endl;
//	}
//}
//void zad9(){
//	int a = 0;
//	while (a < 5) // условный цикл с пред-условием
//	{
//		cout<<"Value is "<<a<<" now \n";
//		a++;
//	}
//}
//void zad10(){
//	int a = 0;
//	do // условный цикл с пост-условием
//	{
//		cout<<"Value is "<<a<<" now \n";
//		a++;
//	} while (a < 5);
//}
//void zad11() {
//	int a = 10;
//	for (int i = 0; i < 10; i++)
//	{
//		cout<<"Iteration ="<<i<<endl;
//	}
//	cout << endl << endl;
//	for (int i = 0; i < a; i++)
//	{
//		a--;
//		cout << "Iteration "<< i<<"   Value is " << a <<endl;;
//	}
//}
//void zad12() {
//	int a = 10;
//	for (int i = 0; i < 10; i++)
//	{
//		a--;
//		if (i >= a)
//		{
//			cout << endl << "I is more or equal A! Break of cycle";
//			break; // этот оператор досрочно завершает цикл
//		}
//	}
//	cout<<"\n A is "<<a;
//}
//void zad13() {
//	int a = 5;
//	int b = 3;
//	float z;
//	// Неявное приведение типов
//	z = a;
//	cout<<endl<<"Value of z is "<<z<<endl;
//	// Явное приведение типов
//	a = (int)z;
//	cout<<endl<<"Value of a is \n"<<a<<endl;
//	// Неявное приведение результата деления
//	// целочисленных переменных
//	z = a / b;
//	cout << endl <<"Value of z is \n"<<z << endl;
//	// Явное приведение а к float и неявное b к float
//	// для выполнения деления
//	z = ((float)a) / b;
//	cout << endl <<"Value of z is \n"<<z << endl;
//}
//void laba1() {
//	bool key=true;
//	int n;
//	while (key)
//	{
//		system("cls");
//		cout << "Выберите задание от 2 до 13" << endl;
//		cin >> n;
//		if (n >= 2 & n <= 13) { cout << "Отлично, поехали!"<<endl; }
//		else {
//			system("cls");
//			cout << "Вы ввели некорректное значение, попробуем ещё раз" << endl;
//			cin >> n;
//		}
//		switch (n)
//		{
//		case 2:
//			zad23();
//			cout << endl;
//			system("pause");
//			break;
//		case 3:
//			zad23();
//			cout << endl;
//			system("pause");
//			break;
//		case 4:
//			zad4();
//			cout << endl;
//			system("pause");
//			break;
//		case 5:
//			zad5();
//			cout << endl;
//			system("pause");
//			break;
//		case 6:
//			zad6();
//			cout << endl;
//			system("pause");
//			break; 
//		case 7:
//			zad7();
//			cout << endl;
//			system("pause");
//			break; 
//		case 8:
//			zad8();
//			cout << endl;
//			system("pause");
//			break; 
//		case 9:
//			zad9();
//			cout << endl;
//			system("pause");
//			break; 
//		case 10:
//			zad10();
//			cout << endl;
//			system("pause");
//			break; 
//		case 11:
//			zad11();
//			cout << endl;
//			system("pause");
//			break; 
//		case 12:
//			zad12();
//			cout << endl;
//			system("pause");
//			break; 
//		case 13:
//			zad13();
//			cout << endl;
//			system("pause");
//			break;
//		default:
//			key = false;
//			break;
//		}
//	}
//	zad23();
//	zad4();
//	zad5();
//	zad6();
//	zad7();
//	zad8();
//	zad9();
//	zad10();
//	zad11();
//	zad12();
//	zad13();
//}