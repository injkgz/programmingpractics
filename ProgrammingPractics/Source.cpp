#include <stdio.h>
void Main()
{
	printf("Hello, World!\n");

	//3
	int a; // ���������� ������������� ����������
	a = 5; // ������������� ���������� ���������
	int b = 3; // ��������� ������������� ���������� � �������������
	printf("\n Variable a equals %d", a); // ����� �������� ���������� �� �����
	printf("\n Variable b equals %d", b); // �������� ���������� ����������� ������ %d
	printf("\n Summ of a and b equals %d", a + b); // ����� �������� �����
												   // ��������� ��������
	//4
	int a = 5;
	int b = 3;
	float z = 5.0;
	float y = 3.0;
	printf("Float variables division: %f \n", z / y);
	printf("Integer variables division: %d \n", a / b);
	//5
	int a;
	int b;
	// ����� ���������� ���������, ����������� ���������� ���������
	// �������� �������� �������� ���� � �������� ������������
	// ����������� � ����� ���������
	printf("---Program for integer summation---");
	// ������ ��������� ������������, ����� ������ ��� ����� ������
	printf("\n\n Enter first integer value: ");
	scanf("%d", &a); // ������ �������� ���������� � ����������
	printf(" Enter second integer value: ");
	scanf("%d", &b);
	printf(" \n Summ of %d and %d equals %d \n", a, b, a + b);

	//6
	int value;
	int* pointer; // ���������� ��������� �� ������������� ��� ������
	int anotherValue;
	value = 5;
	pointer = &value; // �������� ������ ������ ����������
					  // pointer ����� ������� ����� ������
					  // ������������� ����������
	anotherValue = *pointer; // �������� �������������
							 // ����� ��������, ����������� ��� ������������� ���������
	printf("Value, stored in pointer: %d \n", anotherValue);
	// ����� ������, ������� �������� � ���������
	printf("Address in pointer: %p \n", pointer);
	// ����� ���������� ������������� ���������
	printf("Value in pointer: %d \n", *pointer);

	//7
		int a;
		printf("Enter value for check on even/odd: ");
		scanf("%d", &a);
		if (a % 2 == 0)
		{
			printf("\n Value %d is even! \n", a);
		}
		else
		{
			printf("\n Value %d is odd! \n", a);
		}

		//8
		int a;
		printf("Enter value for check on even/odd: ");
		scanf("%d", &a);
		if (a % 5 == 0)
		{
			printf("\n Value %d multiples 5! \n", a);
		}
		else if (a % 2 == 0)
		{
			printf("\n Value %d multiples 2! \n", a);
		}
		else
		{
			printf("\n Value %d doesn`t multiply 5 or 2! \n", a);
		}

		//9

		int a = 0;
		while (a < 5) // �������� ���� � ����-��������
		{
			printf("Value is %d now \n", a);
			a++;
		}
		//10

		int a = 0;
		do // �������� ���� � ����-��������
		{
			printf("Value is %d now \n", a);
			a++;
		} while (a < 5);
		//11

		int a = 10;
		for (int i = 0; i < 10; i++)
		{
			printf("Iteration #%d \n", i);
		}
		printf("\n\n");
		for (int i = 0; i < a; i++)
		{
			a--;
			printf("Iteration #%d Value is %d \n", i, a);
		}
		//12

		int a = 10;
		for (int i = 0; i < 10; i++)
		{
			a--;
			if (i >= a)
			{
				printf("I is more or equal A! Break of cycle");
				break; // ���� �������� �������� ��������� ����
			}
		}
		printf("\n A is %d \n", a);
		//13

		int a = 5;
		int b = 3;
		float z;
		// ������� ���������� �����
		z = a;
		printf("Value of z is %f \n", z);
		// ������ - ����������� ���������� �����!
		a = z;
		// ����� ���������� �����
		a = (int)z;
		printf("Value of a is %d \n", a);
		// ������� ���������� ���������� �������
		// ������������� ����������
		z = a / b;
		printf("Value of z is %f \n", z);
		// ����� ���������� � � float � ������� b � float
		// ��� ���������� �������
		z = ((float)a) / b;
		printf("Value of z is %f \n", z);



}
