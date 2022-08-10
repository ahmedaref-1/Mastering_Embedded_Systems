/*
 ============================================================================
 Name        : EX2_C_Program_To_Find_The_Length_of_a_String.c
 Author      : Ahmed Aref Omaira
 Date		 : July 23, 2022.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char text[100];
	int i=0;

	printf("Please enter the string you want:\n");
	fflush(stdout); fflush(stdin);
	gets(text);

	while(text[i]!='\0')
	{
		i++;
	}

	printf("The length of the entered string is: %d",i);
}
