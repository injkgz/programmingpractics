#include "stdafx.h"
#include <stdio.h>
int main()
{
	int a;
	printf("Enter value for check on even/odd: ");
	scanf_s("%d", &a);
	if (a % 2 == 0)
	{
		printf("\n Value %d is even! \n", a);
	}
	else
	{
		printf("\n Value %d is odd! \n", a);
	}
	return 0;
}