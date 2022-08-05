/*
 ============================================================================
 Name        : EX4_C_Program_to_Calculate_the_Power_of_a_Number_Using_Recursion.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int findPower(int base, int degree);

void main()
{
	int baseNumber, degree, power;

	printf("Please enter the base number:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&baseNumber);

	printf("Please enter the base number's degree:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&degree);

	power = findPower(baseNumber,degree);
	printf("%d ^ %d = %d",baseNumber,degree,power);
}

int findPower(int base, int degree)
{
	if(degree!=0)
		return (base*findPower(base,degree-1));

	else
		return 1;
}
