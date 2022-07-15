/*
 ============================================================================
 Name        : EX6_C_Program_to_Swap_Two_Numbers.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float a, b, temp;
	printf("Enter value of a:");
	fflush(stdout); fflush(stdin);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdout); fflush(stdin);
	scanf("%f",&b);
	temp = a;
	a = b;
	b = temp;
	printf("The value of a after swap is:%0.2f",a);
	printf("\n");
	printf("The Value of a after swap is:%0.2f",b);
}
