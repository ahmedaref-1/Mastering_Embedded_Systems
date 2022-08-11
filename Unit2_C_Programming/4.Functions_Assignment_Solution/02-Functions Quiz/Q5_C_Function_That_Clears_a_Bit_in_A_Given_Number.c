/*
 ============================================================================
 Name        : Q5_C_Function_That_Clears_a_Bit_in_A_Given_Number.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int clearSpecfiedBit(int num, int bitnum);

void main(void)
{
	int number,index;

	printf("Please enter the number:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&number);

	printf("Please enter the bit to be cleared index:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&index);

	printf("Result = %d ",clearSpecfiedBit(number,index));

}

int clearSpecfiedBit(int num, int bitnum)
{
	return num &= ~(1<<bitnum);
}
