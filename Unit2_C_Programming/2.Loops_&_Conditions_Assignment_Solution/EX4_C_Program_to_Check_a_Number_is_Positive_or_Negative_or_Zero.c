/*
 ============================================================================
 Name        : EX4_C_Program_to_Check_a_Number_is_Positive_or_Negative_or_Zero.c
 Author      : Ahmed Aref Omaira
 Date        : July 15,2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float num;

	printf("Please enter the number you want to check:");
	fflush(stdout); fflush(stdin);
	scanf("%f",&num);

	if(num==0)
		printf("You entered Zero");
	else if(num>=0)
		printf("%0.2f is a positive number",num);
	else
		printf("%0.2f is a negative number",num);
	return 0;
}
