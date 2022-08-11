/*
 ============================================================================
 Name        : Q7_C_Program_To_Check_if_a_Given_Number_is_a_Power_of_3.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int isPowerOfThree(int n)
{
	    if (n <= 0)
	        return 0;
	    if (n % 3 == 0)
	        return isPowerOfThree(n / 3);
	    if (n == 1)
	        return 1;
	    return 0;
}

void main()
{
	int number;

	printf("Please enter the number:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&number);

	if(isPowerOfThree(number))
		printf("The number is power of three");
	else
		printf("The number is not a power of three");

}
