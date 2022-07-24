/*
 ============================================================================
 Name        : EX2_C_Program_To_Calculate_Average.c
 Author      : Ahmed Aref Omaira
 Date 		 : July 23,2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n,i;
	float sum=0;
	float array[10000];

start:

	printf("Please enter the number of the elements of the array:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);

	if(n>10000 || n<=0)
	{
		printf("Plese enter a number between 1 and 10000 and try again \n");
		goto start;
	}

	for(i=0;i<n;i++)
	{
		printf("Please enter the number:");
		fflush(stdout); fflush(stdin);
		scanf("%f",&array[i]);
		sum+=array[i];
	}

	printf("The average = %0.2f",(sum/n));
}
