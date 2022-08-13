/*
 ============================================================================
 Name        : Q4_C_Function_to_Revers_Digits_in_Number.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void printReversedNumber (int number)
{
	int digit, temp;
	if (number!=0)
	{	digit = number%10;
		printf("%d",digit);
		printReversedNumber(number/10);
	}
}

void main()
{
	int number;

	printf("Please enter the number you want to reverse:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&number);
	printf("The reversed number is:");
	printReversedNumber (number);
}
