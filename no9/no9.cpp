#include "stdafx.h"
#include <stdio.h>
int main()
{
	int a = 0;
	while (a < 5) // условный цикл с пред-условием
	{
		printf("Value is %d now \n", a);
		a++;
	}
}