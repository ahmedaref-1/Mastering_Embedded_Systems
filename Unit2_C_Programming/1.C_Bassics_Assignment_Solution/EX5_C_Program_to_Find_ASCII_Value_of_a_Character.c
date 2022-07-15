/*
 ============================================================================
 Name        : EX5_C_Program_to_Find_ASCII_Value_of_a_Character.c
 Author      : Ahmed Aref Omaira
 Version     :
 Date        : July 15,2022
 Description : Mastering_Embedded_Systems\Unit_2_C_Programming\Assignments_Solution\1.C_Basics, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	char c;
	printf("Please enter a character:");
	fflush(stdout); fflush(stdin);
	scanf("%c",&c);
	printf("The ASCI code of %c is %d",c,c);


}

