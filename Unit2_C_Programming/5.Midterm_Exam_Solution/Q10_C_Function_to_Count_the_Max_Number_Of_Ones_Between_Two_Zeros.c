/*
 ============================================================================
 Name        : Q10_C_Function_to_Count_the_Max_Number_Of_Ones_Between_Two_Zeros.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int maxNumberOfOnes(int num)
{
	int counter=0;
	int max=0;
	int i;
	for(i=0;i<32;i++)
	{
		if(num&(1<<i))
			{
				counter++;
				if(counter>max)
					max=counter;
			}
		else
			counter=0;

	}
	return max;
}


void main()
{
	int number;
	printf("Please enter the number you want to calculate the max no. of"
			"consecutive ones in its binary representation:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&number);
	printf("The maximum number of ones between two zeros is %d",maxNumberOfOnes(number));
}
