/*
 ============================================================================
 Name        : Q5_C_Function_to_Count_Number_of_Ones_in_Binary_Number.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int countNumberOfOnesInBinary(int num)
{
	int i;
	int count = 0;
	for(i=0;i<=31;i++)
	{
		if(num&(1<<i))
			count++;
	}
	return count;
}

void main()
{
	int intNumber;
	printf("Please enter the number you want to count "
			"ones in its binary representation:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&intNumber);
	printf("The number of ones in the binary representation "
			"of %d is %d",intNumber,countNumberOfOnesInBinary(intNumber));
}
