/*
 ============================================================================
 Name        : EX5_C_Program_to_Find_Area_of_a_circle_by_Passing_Arguments_to_Macros.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#define PI 3.1415
#define area(r)((PI)*(r)*(r))

void main()
{
	float radius,area;
	printf("Please enter the circle radius:");
	fflush(stdout);
	scanf("%f",&radius);
	printf("The circle area is %0.2f",area(radius));
}
