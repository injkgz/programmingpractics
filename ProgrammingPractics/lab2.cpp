#include "lab2.h"
namespace Laboratornaya2
{
	int globalVariable = 7;

	//Функция вывода на экран "Hello, World!"
	void PrintHelloWorld()
	{
		cout << "Hello, World!";
	}

	//Функция различных математических операций с двумя значениями.
	double MakeCalculation(int value1, int value2, char operationKey)
	{
		switch (operationKey)
		{
			case '+': return value1 + value2;
			case '-': return value1 - value2;
			case '*': return value1 * value2;
			case '/': return value1 / value2;
			case '%': return value1 % value2;
			default: break;
		}
	}

	//Проверяет символ на корректность для функции MakeCalculation
	char CheckMathSymbol()
	{
		char key;

		cout << "Есть два значения: 10 и 10" << endl;
		cout << "Выберите арифметическую операцию (+, -, *, /, %): ";
		cin >> key;
		while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
		{
			cout << endl << "Некорректный символ!!!" << endl
				<< "Please, enter(+, -, *, / , %): ";
			cin >> key;
		}
		return key;
	}

	//Вычисляет корни квадратного уравнения(передача переменной по указателю)
	int GetRootsPointer(int a, int b, int c, double *x1, double *x2)
	{
		if (a == 0)
		{
			if (b == 0)
			{
				return 0;
			}
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

	//Вычисляет корни квадратного уравнения(передача переменной по ссылке)
	int GetRootsReference(int a, int b, int c, double &x1, double &x2)
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

	//Тест функций GetRoots
	void TestGetRoots()
	{
		double root1 = NULL;
		double root2 = NULL;
		double* root1Pointer = &root1;
		double* root2Pointer = &root2;
		int(*getRoots1Pointer)(int, int, int, double *, double *) = NULL;
		getRoots1Pointer = &GetRootsPointer;
		int(*getRoots2Pointer)(int, int, int, double &, double &) = NULL;
		getRoots2Pointer = &GetRootsReference;

		PrintRootsPointer(1, 3, 2, root1Pointer, root2Pointer, getRoots1Pointer);
		PrintRootsPointer(1, 4, 0, root1Pointer, root2Pointer, getRoots1Pointer);
		PrintRootsPointer(0, 1, 2, root1Pointer, root2Pointer, getRoots1Pointer);
		PrintRootsReference(0, 0, 3, root1, root2, getRoots2Pointer);
		PrintRootsReference(0, 1, 0, root1, root2, getRoots2Pointer);
		PrintRootsReference(4, 1, 4, root1, root2, getRoots2Pointer);
	}
	//Функция вывода корней
	void PrintRoots(int value3, int x1, int x2) 
	{
		switch (value3)
		{
			case 1: cout << "Всего 1 корень = " << x1 << endl; break;
			case 2: cout << "Найдено 2 корня: " << x1 << " и " << x2 << endl; break;
			default: cout << "Корней не найдено!" << endl; break;
		}
	}
	//Проверка и вывод корней из функции GetRoots(различные варианты передачи параметров)
	void PrintRootsPointer(int a, int b, int c, double *x1, double * x2, 
		int(*functionPointer)(int, int, int, double *, double *))
	{
		int value3 = (*functionPointer)(a, b, c, x1, x2);
		int x1Pointer = (*x1);
		int x2Pointer = (*x2);
		//TODO: Код ниже можно было не дублировать.
		//сделано
		PrintRoots(value3, x1Pointer, x2Pointer);
	}
	void PrintRootsReference(int a, int b, int c, double &x1, double &x2, 
		int(*functionPointer)(int, int, int, double &, double &))
	{
		int value3 = (*functionPointer)(a, b, c, x1, x2);
		PrintRoots(value3, x1, x2);
	}

	//Функции работы с глобальной переменной
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

	//Вычисление любой степени любого числа(в пределах int)
	int GetPower(double base, int power)
	{
		if (power == 0)
		{
			return 1;
		}
		else if (power < 0)
		{
			return 1 / GetPower(base, -power);
		}
		else
		{
			return base * GetPower(base, power - 1);
		}
	}

	//Игра "Угадай число".
	void GameRandomNumbers()
	{
		srand(time(NULL));
		int guessNumber = rand() % 10;
		int enteredNumber = -1;
		int shots = 3;

		cout << "Игра \"Угадай число\" " << endl
			<< "Введите число, которое, как вы думаете, загадал компьютер: ";
		enteredNumber = CheckCin(true);
		while (guessNumber != enteredNumber)
		{
			shots = shots - 1;
			cout << endl << "Неверно! Попробуйте ещё раз! Осталось попыток :" << shots << endl;
			if (shots == 0)
			{
				cout << endl << "!!!Вы проиграли!!!";
				break;
			}
			enteredNumber = CheckCin(true);
		}
		if (guessNumber == enteredNumber)
		{
			cout << endl << "Вы победили!";
		}
	}

	//Рассчитать сумму двух целочисленных переменных
	void SummNumbers(int value1, int value2)
	{
		cout << endl << "Сумма int-ов: " << value1 << " + " << value2 << " = " << value1 + value2;
	}

	//Рассчитать сумму двух целочисленных переменных
	void SummNumbers(double value1, double value2)
	{
		cout << endl << "Сумма double-ов: " << value1 << " + " << value2 << " = " << value1 + value2;
	}

	//Рассчитать сумму двух целочисленных переменных
	void SummNumbers(int value1, double value2)
	{
		cout << endl << "Сумма int'а и double'a: " << value1 << " + " << value2 << " = " << value1 + value2;
	}

	//Сортировка массива. Разные реализации передачи массива в функцию
	void InsertionSortValue(int integerArray[5])
	{
		InsertionSortReference(integerArray, 5);
	}
	void InsertionSortReference(int integerArray[], int arraySize)
	{
		for (int i = 1; i < arraySize; i++)
		{
			for (int j = i; j > 0 && integerArray[j - 1] > integerArray[j]; j--)
			{
				swap(integerArray[j - 1], integerArray[j]);
			}
		}
	}
	void InsertionSortPointer(int* arrayPointer, int arraySize)
	{
		InsertionSortReference(arrayPointer, arraySize);
	}

	void MultiplyMatrices(int** matrixA, int sizex1, int sizey1, 
	int** matrixB, int sizex2, int sizey2, int** matrixResult)
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

	//Вывод матрицы
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

	//Удаление матрицы
	void DeleteMatrix(int size, int** matrix)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] matrix[i];
		}
	}

	//Создание матрицы
	void MakeMatrix(int sizex, int sizey, int** matrix)
	{
		for (int i = 0; i < sizex; i++)
		{
			matrix[i] = new int[sizey];
		}
	}
	
	//Заполнение матрицы
	void FillMatrix(int sizex, int sizey, int** matrix)
	{
		for (int i = 0; i < sizex; i++)
		{
			for (int j = 0; j < sizey; j++)
			{
				matrix[i][j] = rand() % 100;
			}
		}
	}

	//Меню выбора заданий
	void SecondChooseMenu()
	{
		bool key = true;
		int choosedFunction;

		while (key)
		{
			system("cls");
			cout << endl
				<< "Введите 0 для выхода в меню выбора лабораторной или выберите задание от 1 до 9"
				<< endl
				<< "1. PrintHelloWorld()" << endl
				<< "2. MakeCalculation()" << endl
				<< "3. Вычисление корней уравнения()" << endl
				<< "4. Работа с глобальной переменной()" << endl
				<< "5. Возведение числа в степень()" << endl
				<< "6. Игра угадай число!" << endl
				<< "7. Сложение int и double()" << endl
				<< "8. Перемножение произвольных матриц()" << endl
				<< "9. Сортировка массива()" << endl
				<< "Программа будет запрашивать ввод до тех пор, пока вы не введёте корректное значение!"
				<< endl;
			choosedFunction = CheckCin(true);
			switch (choosedFunction)
			{
				//TODO: Поправьте форматирование в соответствии с RSDN.
				//сделано
				//TODO: Где-то стоят скобки, где-то нет, сделайте единообразно.
				//сделано
				case 0:
				{
					key = false;

					cout << endl << "Выход из программы." << endl;
					system("pause");
					break;
				}
				case 1: 
				{ 
					PrintHelloWorld(); 
					break; 
				}
				case 2:
				{
					char operationKey = CheckMathSymbol();

					cout << endl << MakeCalculation(10, 10, operationKey);
					break;
				}
				case 3:	
				{ 
					TestGetRoots(); 
					break; 
				}
				case 4:
				{
					cout << "Глобальная переменная: " << globalVariable << endl;
					GlobalPlusTwo();
					cout << "Глобальная переменная: " << globalVariable << endl;
					GlobalMultiplyThree();
					cout << "Глобальная переменная: " << globalVariable << endl;
					GlobalEqualsOne();
					cout << "Глобальная переменная: " << globalVariable << endl;
					globalVariable = 5;
					cout << "Глобальная переменная: " << globalVariable << endl;
					break;
				}
				case 5:
				{
					cout << endl << "Введите число: ";
					int number = CheckCin(true);

					cout << endl << "Введите степень, в которую будем возводить число: ";
					int power = CheckCin(true);

					cout << endl << "Результат = " << GetPower(number, power) << endl;
					break;
				}
				case 6: 
				{ 
					GameRandomNumbers(); 
					break; 
				}
				case 7:
				{
					int a = 1;
					int b = 2;
					double x = 3.0;
					double y = 4.0;
					float m = 5.0;
					float n = 6.0;

					SummNumbers(a, b);
					SummNumbers(x, y);
					SummNumbers(a, y);
					SummNumbers(m, n);
					break;
				}
				case 8:
				{
					cout << "Введите количество строк в матрице А: ";
					int sizex1 = CheckCin(true);
					cout << "Введите количество столбцов в матрице А: ";
					int sizey1 = CheckCin(true);
					cout << "Введите количество строк в матрице В: ";
					int sizex2 = CheckCin(true);
					cout << "Введите количество столбцов в матрице В: ";
					int sizey2 = CheckCin(true);

					if (sizey1 == sizex2)
					{
						int sizexResult = sizex1;
						int sizeyResult = sizey2;
						
						int** matrixA = new int*[sizex1];
						int** matrixResult = new int*[sizexResult];
						int** matrixB = new int*[sizex2];

						MakeMatrix(sizex1, sizey1, matrixA);
						MakeMatrix(sizex2, sizey2, matrixB);
						MakeMatrix(sizexResult, sizeyResult, matrixResult);
						FillMatrix(sizex1, sizey1, matrixA);
						FillMatrix(sizex2, sizey2, matrixB);
						MultiplyMatrices(matrixA, sizex1, sizey1, matrixB, sizex2, sizey2, matrixResult);
						cout << "Матрица А:" << endl;
						PrintMatrix(matrixA, sizey1, sizex1);
						cout << "-----------------------------------" << endl;
						cout << "Матрица В:" << endl;
						PrintMatrix(matrixB, sizey2, sizex2);
						cout << "-----------------------------------" << endl;
						cout << "Результат:" << endl;
						PrintMatrix(matrixResult, sizeyResult, sizexResult);
						DeleteMatrix(sizex1, matrixA);
						DeleteMatrix(sizex2, matrixB);
						DeleteMatrix(sizexResult, matrixResult);
						delete[] matrixA, matrixB, matrixResult;
					}
					else
					{
						cout << endl << "Матрицу А нельзя умножить на матрицу В" << endl;
					}
					break;
				}
				case 9:
				{
					const int arraySize = 5;
					int integerArray[arraySize];

					cout << "Массив до сортировки:" << endl;

					for (int i = 0; i < arraySize; i++)
					{
						integerArray[i] = rand() % 100;
						cout << integerArray[i] << " ";
					}
					//InsertionSortValue(integerArray);
					//InsertionSortReference(integerArray, arraySize);
					InsertionSortPointer(integerArray, arraySize);
					cout << endl << "Массив после сортировки" << endl;

					for (int i = 0; i < arraySize; i++)
					{
						cout << integerArray[i] << " ";
					}
					cout << endl;
					break;
				}
				default: { break; }
			}
			if (choosedFunction >= 1)
			{
				GetPause();
			}
		}
	}
}