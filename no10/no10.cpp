#include "stdafx.h"
#include <stdio.h>

int main()
{
	int a = 0;
	do // условный цикл с пост-условием
	{
		printf("Value is %d now \n", a);
		a++;
	} 
	while (a < 5);
}