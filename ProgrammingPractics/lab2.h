#pragma once
#include "CheckCin.h"
namespace Laboratornaya2 
{
	void PrintHelloWorld();
	double MakeCalculation(int value1, int value2, char operationKey);
	char CheckMathSymbol();
	int GetRoots1(int a, int b, int c, double *x1, double *x2);
	int GetRoots2(double a, double b, double c, double &x1, double &x2);
	void TestGetRoots();
	void PrintRoots(double &value1, double &value2, int &value3);
	int GetPower(double base, int power);
	void GlobalPlusTwo();
	void GlobalMultiplyThree();
	void GlobalEqualsOne();
	void GameRandomNumbers();
	void SecondChooseMenu();
	void MultiplyMatrices(int** matrixA, int sizex1, int sizey1, int** matrixB, int sizex2, int sizey2, int** matrixResult);
	void PrintMatrix(int** matrix, int columns, int rows);
	void InsertionSort1(int integerArray[5]);
	void InsertionSort2(int integerArray[], int arraySize);
	void InsertionSort3(int* arrayPointer, int arraySize);
}

