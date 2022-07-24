/*
 ============================================================================
 Name        : EX3_C_Program_to_Reverse_String_Without_Using_Library_Function.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char text[100], temp;
	int i=0, j=0;

	printf("Please enter the string you want to reverse: ");
	fflush(stdout); fflush(stdin);
	gets(text);

	j=strlen(text)-1;

	while(i<j)
	{
		temp=text[i];
		text[i]=text[j];
		text[j]=temp;
		i++;
		j--;
	}

	printf("The reversed string is: %s",text);


}
