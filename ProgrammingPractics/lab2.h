#pragma once
#include "CheckCin.h"
namespace Laboratornaya2 
{
	void PrintHelloWorld();
	double MakeCalculation(int value1, int value2, char operationKey);
	char CheckMathSymbol();
	int GetRootsPointer(int a, int b, int c, double *x1, double *x2);
	int GetRootsReference(int a, int b, int c, double &x1, double &x2);
	void TestGetRoots();
	void PrintRoots(int value3, int x1, int x2);
	void PrintRootsPointer(int a, int b, int c, double *x1, double * x2, 
		int(*getRoots1Pointer)(int, int, int, double *, double *));
	void PrintRootsReference(int a, int b, int c, double &x1, double &x2, 
		int(*getRoots1Pointer)(int, int, int, double &, double &));
	int GetPower(double base, int power);
	void GlobalPlusTwo();
	void GlobalMultiplyThree();
	void GlobalEqualsOne();
	void GameRandomNumbers();
	void SecondChooseMenu();
	void MultiplyMatrices(int** matrixA, int sizex1, int sizey1, int** matrixB, int sizex2, int sizey2, int** matrixResult);
	void PrintMatrix(int** matrix, int columns, int rows);
	void InsertionSortValue(int integerArray[5]);
	void InsertionSortReference(int integerArray[], int arraySize);
	void InsertionSortPointer(int* arrayPointer, int arraySize);
	void DeleteMatrix(int size, int** matrix);
	void FillMatrix(int sizex, int sizey, int** matrix);
	void MakeMatrix(int sizex, int sizey, int** matrix);
	void SecondChooseMenu();
}

