/*
 ============================================================================
 Name        : EX1_C_Program_to_Check_if_a_Number_Is_Even.c
 Author      : Ahmed Aref Omaira
 Date		 : July 15,2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	printf("Please enter the number you want to check:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num);

	if(num%2==0)
		printf("%d is an Even number",num);
	else
		printf("%d is an Odd number",num);

	return 0;
}
