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
	void MultiplyMatr(double *array1, double *array2, int a1x, int a1y, int a2x, int a2y);
}

