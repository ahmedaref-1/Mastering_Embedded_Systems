/*
 ============================================================================
 Name        : EX4_C_Program_to_Multiply_Two_Floating_Point_Numbers.c
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
	float a , b ;
	printf("Enter two float numbers seperated by / :");
	fflush(stdout); fflush(stdin);
	scanf("%f/%f",&a,&b);
	printf("The product of the two entered numbers is %f",(a*b));
}
