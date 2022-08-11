/*
 ============================================================================
 Name        : Q1_C_Program_Takes_String_From_The_User_and_Checks_if_it's_Same_Username_or_Not.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void main()
{
	char username[100],stringFromUser[100];
	int result;

	printf("Please enter the username:");
	fflush(stdout); fflush(stdin);
	scanf("%s",username);

	printf("Please enter the string you want to compare with preentered username:");
	fflush(stdout); fflush(stdin);
	gets(stringFromUser);

	result = stricmp(username,stringFromUser);

	if(result==0)
		printf("Identical");
	else
		printf("Different");

}
