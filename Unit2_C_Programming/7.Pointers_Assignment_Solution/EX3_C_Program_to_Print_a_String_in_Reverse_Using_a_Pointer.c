/*
 ============================================================================
 Name        : EX3_C_Program_to_Print_a_String_in_Reverse_Using_a_Pointer.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>


void main()
{
	char string[20];
	char* ptr_string = NULL;
	int i;

	printf("Please enter the string you want to get it reversed:\n");
	fflush(stdout);fflush(stdin);
	gets(string);

	ptr_string=string;
	ptr_string += (strlen(string)-1);

	for(i=0;i<strlen(string);i++,ptr_string--)
	{
		printf("%c",(char*)*ptr_string);
	}
}
