#include "stdafx.h"
#include <stdio.h>

int main()
{
	int a;
	printf("Enter value for check on even/odd: ");
	scanf_s("%d", &a);
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
}