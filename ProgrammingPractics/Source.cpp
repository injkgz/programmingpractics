#include <stdio.h>
#include <iostream>
using namespace std;

void laba1();
int main()
{
	setlocale(LC_ALL, "russian");
	laba1();
	return 0;
}

void zad23()
{
	cout << "Hello, World!\n";

	//3
	int a; // ���������� ������������� ����������
	a = 5; // ������������� ���������� ���������
	int b = 3; // ��������� ������������� ���������� � �������������
	cout << "\n Variable a equals " << a;// ����� �������� ���������� �� �����
	cout << "\n Variable b equals " << b;// �������� ���������� ����������� ������ %d
	cout << "\n Summ of a and b equal = " << a + b; // ����� �������� �����
													// ��������� ��������
}
void zad4()
{
	int a = 5;
	int b = 3;
	float z = 5.0;
	float y = 3.0;
	cout << "Float variables division: \n" << z / y;
	cout <<endl<< "Integer variables division:\n" << a / b;

}
void zad5()
{
	int a;
	int b;
	// ����� ���������� ���������, ����������� ���������� ���������
	// �������� �������� �������� ���� � �������� ������������
	// ����������� � ����� ���������
	cout<<"-- - Program for integer summation-- - ";
	// ������ ��������� ������������, ����� ������ ��� ����� ������
	cout << "\n\n Enter first integer value: ";
	cin >> a;
	cout << "\n\n Enter second integer value: ";
	cin >> b;
	cout << " \n Summ of and equals \n" << a <<" "<< b <<" "<< a + b;
	
}
void zad6() {
	int value;
	int* pointer; // ���������� ��������� �� ������������� ��� ������
	int anotherValue;
	value = 5;
	pointer = &value; // �������� ������ ������ ����������
					  // pointer ����� ������� ����� ������
					  // ������������� ����������
	anotherValue = *pointer; // �������� �������������
							 // ����� ��������, ����������� ��� ������������� ���������
	cout << "Value, stored in pointer: " << anotherValue << endl;
	// ����� ������, ������� �������� � ���������
	cout << "Address in pointer: " << pointer << endl;
	// ����� ���������� ������������� ���������
	cout << "Value in pointer:" << *pointer << endl;

}
void zad7() {
	int a;
	cout<<"Enter value for check on even/odd: ";
	cin >> a;
	if (a % 2 == 0)
	{
		cout<<"\n Value is "<<a<<" even!";
	}
	else
	{
		cout << "\n Value is " << a << " odd!";
	}
}
void zad8(){
	int a;
	cout<<"Enter value for check on even/odd: ";
	cin >> a;
	if (a % 5 == 0)
	{
		cout << "\n Value " <<a<<" multiples 5!" << endl;;
	}
	else if (a % 2 == 0)
	{
		cout << "\n Value "<<a<<" multiples 2!"<<endl;
	}
	else
	{
		cout << "\n Value "<<a<<" doesn`t multiply 5 or 2!"<<endl;
	}
}
void zad9(){
	int a = 0;
	while (a < 5) // �������� ���� � ����-��������
	{
		cout<<"Value is "<<a<<" now \n";
		a++;
	}
}
void zad10(){
	int a = 0;
	do // �������� ���� � ����-��������
	{
		cout<<"Value is "<<a<<" now \n";
		a++;
	} while (a < 5);
}
void zad11() {
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		cout<<"Iteration ="<<i<<endl;
	}
	cout << endl << endl;
	for (int i = 0; i < a; i++)
	{
		a--;
		cout << "Iteration "<< i<<"   Value is " << a <<endl;;
	}
}
void zad12() {
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			cout << endl << "I is more or equal A! Break of cycle";
			break; // ���� �������� �������� ��������� ����
		}
	}
	cout<<"\n A is "<<a;
}
void zad13() {
	int a = 5;
	int b = 3;
	float z;
	// ������� ���������� �����
	z = a;
	cout<<endl<<"Value of z is "<<z<<endl;
	// ����� ���������� �����
	a = (int)z;
	cout<<endl<<"Value of a is \n"<<a<<endl;
	// ������� ���������� ���������� �������
	// ������������� ����������
	z = a / b;
	cout << endl <<"Value of z is \n"<<z << endl;
	// ����� ���������� � � float � ������� b � float
	// ��� ���������� �������
	z = ((float)a) / b;
	cout << endl <<"Value of z is \n"<<z << endl;
}
void laba1() {
	bool key=true;
	int n;
	while (key)
	{
		system("cls");
		cout << "�������� ������� �� 2 �� 13" << endl;
		cin >> n;
		if (n >= 2 & n <= 13) { cout << "�������, �������!"<<endl; }
		else {
			system("cls");
			cout << "�� ����� ������������ ��������, ��������� ��� ���" << endl;
			cin >> n;
		}
		switch (n)
		{
		case 2:
			zad23();
			cout << endl;
			system("pause");
			break;
		case 3:
			zad23();
			cout << endl;
			system("pause");
			break;
		case 4:
			zad4();
			cout << endl;
			system("pause");
			break;
		case 5:
			zad5();
			cout << endl;
			system("pause");
			break;
		case 6:
			zad6();
			cout << endl;
			system("pause");
			break; 
		case 7:
			zad7();
			cout << endl;
			system("pause");
			break; 
		case 8:
			zad8();
			cout << endl;
			system("pause");
			break; 
		case 9:
			zad9();
			cout << endl;
			system("pause");
			break; 
		case 10:
			zad10();
			cout << endl;
			system("pause");
			break; 
		case 11:
			zad11();
			cout << endl;
			system("pause");
			break; 
		case 12:
			zad12();
			cout << endl;
			system("pause");
			break; 
		case 13:
			zad13();
			cout << endl;
			system("pause");
			break;
		default:
			key = false;
			break;
		}
	}
	zad23();
	zad4();
	zad5();
	zad6();
	zad7();
	zad8();
	zad9();
	zad10();
	zad11();
	zad12();
	zad13();
}