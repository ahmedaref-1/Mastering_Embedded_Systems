/*
 ============================================================================
 Name        : Q3_C_Function_to_Print_All_Prime_Numbers_Between_Two_Numbers.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>

void printPrimeNumbers(int start,int end)
{
	int i, j, notPrimeFlag;
	for(i=start;i<=end;i++)
	{
		notPrimeFlag =0;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
				notPrimeFlag =1;
		}
		if(notPrimeFlag==0)
			printf("%d ",i);
	}
}
void main()
{
	int arrayOfNumbers[100];
	int i,j,firstNumber,lastNumber;

	printf("Please enter the first number in the interval:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&firstNumber);

	printf("Please enter the last number in the interval:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&lastNumber);

	printf("The prime numbers in the interval between %d and %d are ->\n",firstNumber,lastNumber);
	printPrimeNumbers(firstNumber,lastNumber);

}
