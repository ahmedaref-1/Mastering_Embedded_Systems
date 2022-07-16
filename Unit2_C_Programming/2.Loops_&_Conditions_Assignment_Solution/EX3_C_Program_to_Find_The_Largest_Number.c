/*
 ============================================================================
 Name        : EX3_C_Program_to_Find_The_Largest_Number.c
 Author      : Ahmed Aref Omaira
 Date        : July 15,2022
 ============================================================================
 */

#include <stdio.h>

int main()
{
	float a, b, c;

	printf("Please enter the three numbers:");
	fflush(stdout);fflush(stdin);
	scanf("%f %f %f",&a,&b,&c);

	if(a>b)
	{
		if(a>c)
			printf("%0.2f is the largest number",a);
		else
			printf("%0.2f is the largest number",c);
	}

	if(b>a)
	{
		if(b>c)
			printf("%0.2f is the largest number",b);
		else
			printf("%0.2f is the largest number",c);
	}
	return 0;
}
