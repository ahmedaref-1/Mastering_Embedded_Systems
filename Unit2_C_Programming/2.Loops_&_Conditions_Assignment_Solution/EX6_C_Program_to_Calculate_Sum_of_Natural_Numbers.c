/*
 ============================================================================
 Name        : EX6_C_Program_to_Calculate_Sum_of_Natural_Numbers.c
 Author      : Ahmed Aref Omaira
 Date        : July 30,2022
 ============================================================================
 */

#include <stdio.h>


int main()
{
	int n, sum, i;
	sum=0;

	printf("Please enter the number:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		sum+=i;
	}

	printf("The sum of the numbers from 0 to %d is %d",n,sum);
	return 0;
}
