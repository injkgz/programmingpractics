#include "lab2.h"
namespace Laboratornaya2
{
	int globalVariable = 7;

	//������� ������ �� ����� "Hello, World!"
	void PrintHelloWorld()
	{
		cout << "Hello, World!";
	}

	//������� ��������� �������������� �������� � ����� ����������.
	double MakeCalculation(int value1, int value2, char operationKey)
	{
		switch (operationKey)
		{
		case '+': return value1 + value2; break;
		case '-': return value1 - value2; break;
		case '*': return value1 * value2; break;
		case '/': return value1 / value2; break;
		case '%': return value1 % value2; break;
		default: break;
		}
	}

	//��������� ������ �� ������������ ��� ������� MakeCalculation
	char CheckMathSymbol()
	{
		char key;

		cout << "Enter mathematic operation (+, -, *, /, %): ";
		cin >> key;
		while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
		{
			cout << endl << "INCORRECT SYMBOL!!!" << endl
				<< "Please, enter(+, -, *, / , %): ";
			cin >> key;		}
		return key;
	}

	//��������� ����� ����������� ���������(�������� ���������� �� ���������)
	int GetRoots1(int a, int b, int c, double *x1, double *x2)
	{
		if (a == 0)
		{
			if (b == 0)
				return 0;
			if (c == 0)
			{
				x1 = 0;
				x2 = NULL;
				return 1;
			}
			*x1 = -(c / b);
			x2 = NULL;
			return 1;
		}
		double discriminant;

		discriminant = b * b - 4 * a * c;

		if (discriminant < 0)
		{
			(*x1) = NULL;
			(*x2) = NULL;
			return 0;
		}
		else if (discriminant == 0)
		{
			(*x1) = -b / (2 * a);
			(*x2) = NULL;
			return 1;
		}
		else
		{
			(*x1) = (-b + sqrt(discriminant)) / 2 * a;
			(*x2) = (-b - sqrt(discriminant)) / 2 * a;
			return 2;
		}
	}

	//��������� ����� ����������� ���������(�������� ���������� �� ������)
	int GetRoots2(int a, int b, int c, double &x1, double &x2)
	{
		if (a == 0)
		{
			if (b == 0)
				return 0;
			if (c == 0)
			{
				x1 = 0;
				x2 = NULL;
				return 1;
			}
			x1 = x1 = -(c / b);
			x2 = NULL;
			return 1;
		}
		double discriminant = ((b * b) - (4 * a * c));

		if (discriminant < 0)
		{
			x1 = NULL;
			x2 = NULL;
			return 0;
		}
		else if ((int)discriminant == 0)
		{
			x1 = -(b / (2 * a));
			x2 = NULL;
			return 1;
		}

		double sqrtD = sqrt(discriminant);

		x1 = ((-b - sqrtD) / (2 * a));
		x2 = ((-b + sqrtD) / (2 * a));
		return 2;
	}

	//���� ������� GetRoots
	void TestGetRoots()
	{
		double root1 = NULL;
		double root2 = NULL;
		double* root1Pointer = &root1;
		double* root2Pointer = &root2;
		int quantityOfRoots;

		quantityOfRoots = GetRoots1(1, 3, 2, root1Pointer, root2Pointer);
		PrintRoots(root1, root2, quantityOfRoots);
		quantityOfRoots = GetRoots1(1, 4, 0, root1Pointer, root2Pointer);
		PrintRoots(root1, root2, quantityOfRoots);
		quantityOfRoots = GetRoots1(0, 1, 2, root1Pointer, root2Pointer);
		PrintRoots(root1, root2, quantityOfRoots);
		quantityOfRoots = GetRoots2(0, 0, 3, root1, root2);
		PrintRoots(root1, root2, quantityOfRoots);
		quantityOfRoots = GetRoots2(0, 1, 0, root1, root2);
		PrintRoots(root1, root2, quantityOfRoots);
		quantityOfRoots = GetRoots2(4, 1, 4, root1, root2);
		PrintRoots(root1, root2, quantityOfRoots);

	}

	//�������� � ����� ������ �� ������� GetRoots
	void PrintRoots(double& value1, double& value2, int& value3)
	{
		if (value3 == 1)
			cout << "����� 1 ������ = " << value1 << endl;
		else if (value3 == 2)
			cout << "������� 2 �����: " << value1 << " � " << value2 << endl;
		else cout << "������ �� �������!" << endl;
	}

	//������� ������ � ���������� ����������
	void GlobalPlusTwo()
	{
		globalVariable += 2;
	}
	void GlobalMultiplyThree()
	{
		globalVariable *= 3;
	}
	void GlobalEqualsOne()
	{
		globalVariable = 1;
	}
	//���������� ����� ������� ������ �����(� �������� int)
	int GetPower(double base, int power)
	{
		if (power == 0)
			return 1;
		else if (power < 0)
			return 1 / GetPower(base, -power);
		else
			return base * GetPower(base, power - 1);

	}

	//���� "������ �����".
	void GameRandomNumbers()
	{
		srand(time(NULL)); 
		int guessNumber = rand() % 10; 
		int enteredNumber = -1; 
		int shots = 3; 

		cout << "���� \"������ �����\" " << endl
			<< "������� �����, �������, ��� �� �������, ������� ���������: ";
		enteredNumber = CheckCin(true);
		while (guessNumber != enteredNumber)
		{
			shots = shots - 1;
			cout << endl << "�������! ���������� ��� ���! �������� ������� :" << shots << endl;
			if (shots == 0)
			{
				cout << endl << "!!!�� ���������!!!";
				break;
			}
			enteredNumber = CheckCin(true);
		}
		cout << endl << "�� ��������!";
	}

	//���������� ����� ���� ������������� ����������
	void SummNumbers(int value1, int value2)
	{
		cout << endl << "����� int-�� = " << value1 + value2;
	}

	//���������� ����� ���� ������������� ����������
	void SummNumbers(double value1, double value2)
	{
		cout << endl << "����� double-�� = " << value1 + value2;
	}

	//���������� ����� ���� ������������� ����������
	void SummNumbers(int value1, double value2)
	{
		cout << endl << "����� int'� � double'a = " << value1 + value2;
	}	//���������� �������. ������ ���������� �������� ������� � �������	void InsertionSort1(int integerArray[5])
	{
		for (int i = 1; i < 5; i++)
			for (int j = i; j > 0 && integerArray[j - 1] > integerArray[j]; j--)
				swap(integerArray[j - 1], integerArray[j]);
	}
	void InsertionSort2(int integerArray[], int arraySize)
	{
		for (int i = 1; i < arraySize; i++)
			for (int j = i; j > 0 && integerArray[j - 1] > integerArray[j]; j--)
				swap(integerArray[j - 1], integerArray[j]);
	}
	void InsertionSort3(int* arrayPointer, int arraySize)
	{
		for (int i = 1; i < arraySize; i++)
			for (int j = i; j > 0 && arrayPointer[j - 1] > arrayPointer[j]; j--)
			{
				swap(arrayPointer[j - 1], arrayPointer[j]);
			}
	}
	//��������� ������
	void MultiplyMatrices(int** matrixA, int sizex1, int sizey1, int** matrixB, int sizex2, int sizey2, int** matrixResult)
	{
		for (int i = 0; i < sizex1; i++)
		{
			for (int j = 0; j < sizey2; j++)
			{
				matrixResult[i][j] = 0;
				for (int k = 0; k < sizey1; k++)
				{
					matrixResult[i][j] += (matrixA[i][k] * matrixB[k][j]);
				}
			}
		}
	}

	//����� �������
	void PrintMatrix(int** matrix, int columns, int rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout.width(8);
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}

	//���� ������ �������
	void SecondChooseMenu()
	{
		bool key = true;
		int n;

		while (key)
		{
			system("cls");
			cout << endl
				<< "������� 0 ��� ������ � ���� ������ ������������ ��� �������� ������� �� 2 �� 13"
				<< endl
				<< "��������� ����� ����������� ���� �� ��� ���, ���� �� �� ������ ���������� ��������!"
				<< endl;
			n = CheckCin(true);
			switch (n)
			{
			case 0:
				key = false;
				cout << endl << "����� �� ���������." << endl;
				system("pause");
				break;
			case 1: PrintHelloWorld(); break;
			case 2:
			{
				char operationKey = CheckMathSymbol();
				cout << endl << MakeCalculation(10, 10, operationKey);
				break;
			}
			case 3: TestGetRoots(); break;
			case 4:
				cout << "���������� ����������: " << globalVariable << endl;
				GlobalPlusTwo();
				cout << "���������� ����������: " << globalVariable << endl;
				GlobalMultiplyThree();
				cout << "���������� ����������: " << globalVariable << endl;
				GlobalEqualsOne();
				cout << "���������� ����������: " << globalVariable << endl;
				globalVariable = 5;
				cout << "���������� ����������: " << globalVariable << endl;				break;			case 5:			{				cout << endl << "������� �����: ";				int number = CheckCin(true);				cout << endl << "������� �������, � ������� ����� ��������� �����: ";				int power = CheckCin(true);				cout << endl << "��������� = " << GetPower(number, power) << endl;				break;			}			case 6: GameRandomNumbers(); break;
			case 7:
			{
				int a = 1;
				int b = 2;
				SummNumbers(a, b);
				double x = 3.0;
				double y = 4.0;
				SummNumbers(x, y);
				SummNumbers(a, y);
				float m = 5.0;
				float n = 6.0;
				SummNumbers(m, n);
				break;
			}
			case 8:
			{
				cout << "������� ���������� ����� � ������� �: ";
				int sizex1 = CheckCin(true);
				cout << "������� ���������� �������� � ������� �: ";
				int sizey1 = CheckCin(true);
				cout << "������� ���������� ����� � ������� �: ";
				int sizex2 = CheckCin(true);
				cout << "������� ���������� �������� � ������� �: ";
				int sizey2 = CheckCin(true);

				if (sizey1 == sizex2)
				{
					int sizexResult = sizex1;
					int sizeyResult = sizey2;

					int** matrixA = new int*[sizex1];
					for (int i = 0; i < sizex1; i++)
						matrixA[i] = new int[sizey1];

					int** matrixB = new int*[sizex2];
					for (int i = 0; i < sizex2; i++)
						matrixB[i] = new int[sizey2];

					int** matrixResult = new int*[sizexResult];
					for (int i = 0; i < sizexResult; i++)
						matrixResult[i] = new int[sizeyResult];

					for (int i = 0; i < sizex1; i++)
						for (int j = 0; j < sizey1; j++)
							matrixA[i][j] = rand() % 100;

					for (int i = 0; i < sizex2; i++)
						for (int j = 0; j < sizey2; j++)
							matrixB[i][j] = rand() % 100;

					MultiplyMatrices(matrixA, sizex1, sizey1, matrixB, sizex2, sizey2, matrixResult);

					cout << "������� �:" << endl;
					PrintMatrix(matrixA, sizey1, sizex1);
					cout << "-----------------------------------" << endl;
					cout << "������� �:" << endl;
					PrintMatrix(matrixB, sizey2, sizex2);
					cout << "-----------------------------------" << endl;
					cout << "���������:" << endl;
					PrintMatrix(matrixResult, sizeyResult, sizexResult);

					for (int i = 0; i < sizex1; i++)
						delete[] matrixA[i];
					for (int i = 0; i < sizex2; i++)
						delete[] matrixB[i];
					for (int i = 0; i < sizexResult; i++)
						delete[] matrixResult[i];
					delete[] matrixA, matrixB, matrixResult;
				}
				else
					cout << endl << "������� � ������ �������� �� ������� �" << endl;
				break;
			}
			case 9:
			{
				const int arraySize = 5;
				int integerArray[arraySize];

				cout << "������ �� ����������:" << endl;
				for (int i = 0; i < arraySize; i++)
				{
					integerArray[i] = rand() % 100;
					cout << integerArray[i] << " ";
				}
				InsertionSort1(integerArray);
				//InsertionSort2(integerArray, arraySize);
				//InsertionSort3(integerArray, arraySize);
				cout << endl << "������ ����� ����������" << endl;
				for (int i = 0; i < arraySize; i++)
				{
					cout << integerArray[i] << " ";
				}
				cout << endl;
				break;
			}
			default: break;
			}
			if (n >= 1)
				GetPause();
		}
	}
}