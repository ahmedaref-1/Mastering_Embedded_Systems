/*
 ============================================================================
 Name        : EX2_C_Program_To_Print_a_Integer_Entered_by_a_User.c
 Author      : Ahmed Aref Omaira
 Date        : July 15,2022
 Description :  Mastering_Embedded_Systems\Unit_2_C_Programming\Assignments_Solution\1.C_Basics, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num;
	printf("Please enter an integer number:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&num);
	printf("Your entered intger is:%d",num);
}
