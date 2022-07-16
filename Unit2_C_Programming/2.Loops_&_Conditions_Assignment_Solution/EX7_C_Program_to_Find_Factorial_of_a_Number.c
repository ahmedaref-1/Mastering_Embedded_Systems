/*
 ============================================================================
 Name        : EX7_C_Program_to_Find_Factorial_of_a_Number.c
 Author      : Ahmed Aref Omaira
 Date        : July 15,2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, factorial;
	factorial = 1;

	printf("Please enter the number you want to find its factorial:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);

	if(n<0)
		printf("Error! Factorial of negative numbers doesn't exist");
	else if(n==0)
		printf("Factorial of 0 is 1");
	else
	{
		for(i=1;i<=n;i++)
		{
			factorial*=i;
		}
		printf("Factorial of %d is %d",n,factorial);
	}


	return 0;
}
