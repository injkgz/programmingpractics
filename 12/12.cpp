#include "stdafx.h"
#include <stdio.h>
void Main()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			printf("I is more or equal A! Break of cycle");
			break; // этот оператор досрочно завершает цикл
		}
	}
	printf("\n A is %d \n", a);
}