/*
 ============================================================================
 Name        : Q7_C_Function_to_Sum_Numbers_From_1_To_100_Without_Loop.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int i;
int sum;

int sumOfNumbers()
{
	if(i<=100)
	{	sum+=i;
		i++;
		sumOfNumbers();
		return sum;
	}
	return 0;
}
void main()
{
	printf("The sum of numbers from 1 to 100 equals %d ",sumOfNumbers());
}
