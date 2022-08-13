/*
 ============================================================================
 Name        : C_Function_to_take_an_Integer_Number_and_Calculate_its_Square_Root.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>

int myCeil(float num)
{
	return (int)num+1;
}

float squareRoot(int number)
{
	float i, sqrroot;
	for(i=(number/2);i>=0;i--)
	{
		if((i*i)==number)
			{
				sqrroot =i;
				break;
			}
		for(;i>=0;(i-=0.001))
		{
			if(myCeil(i*i)==number)
			{
				sqrroot =i;
				break;
			}
		}
	}
	return sqrroot;
}

void main()
{
	int num;
	printf("Please enter the number you want to calculate its square root:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num);
	printf("The Square Root of %d is approximately equal to %0.4f ", num, squareRoot(num));

}
