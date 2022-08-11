/*
 ============================================================================
 Name        : Q6_C_Program_To_Check_The_Value_of_The_Fourth_Least_Siginificant_Bit.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int number;

	printf("Please enter the number:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&number);

	if(number&=(1<<3))
		printf("The 4th least siginificant bit is 1");
	else
		printf("The 4th least siginificant bit is 0");

}
