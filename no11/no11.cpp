#include "stdafx.h"
#include <stdio.h>
int main()
{
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
}