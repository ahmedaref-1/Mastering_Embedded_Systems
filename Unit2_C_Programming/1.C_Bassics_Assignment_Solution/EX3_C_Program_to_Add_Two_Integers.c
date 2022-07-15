/*
 ============================================================================
 Name        : EX3_C_Program_to_Add_Two_Integers.c
 Author      : Ahmed Aref Omaira
 Date        : July 15,2022
 Description : Mastering_Embedded_Systems\Unit_2_C_Programming\Assignments_Solution\1.C_Basics, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a , b ;
	printf("Enter two integers seperated by / :");
	fflush(stdout); fflush(stdin);
	scanf("%d/%d",&a,&b);
	printf("The sum of the two entred numbers is %d",(a+b));
}
