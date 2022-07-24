/*
 ============================================================================
 Name        : EX1_C_Program_To_Find_The_Frequency_Of_Characters.c
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
	char text [1000];
	char charToFind;
	int i, counter=0;

	printf("Please enter the string you want:\n");
	fflush(stdout); fflush(stdin);
	gets(text);

	printf("Please enter the character you want to know its frequency:\n");
	fflush(stdout); fflush(stdin);
	scanf("%c",&charToFind);

	for(i=0;i<strlen(text);i++)
	{
		if(text[i]==charToFind)
			counter++;
	}

	printf("The char %c is repeated %d times in the entered string",charToFind,counter);
}
