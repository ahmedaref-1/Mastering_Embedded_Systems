/*
 ============================================================================
 Name        : EX2_C_Program_to_Calculate_Factorial_of_a_Number_Using_Recursion.c
 Author      : Ahmed Aref Omaira
 Date		 : August 8, 2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calcFactorial(int num);
void main()
{
	int num, factorial;

	printf("Please enter the number you want to calculate its factorial:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num);
	factorial = calcFactorial(num);
	printf("The factorial of %d is %d ",num,factorial);
}

int calcFactorial(int num)
{
	if(num==1)
		return 1;
	else
		return num*= calcFactorial(num-1);
}
