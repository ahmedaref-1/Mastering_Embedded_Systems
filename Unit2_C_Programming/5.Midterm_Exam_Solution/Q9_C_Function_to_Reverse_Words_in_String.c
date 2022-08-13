/*
 ============================================================================
 Name        : Q9_C_Function_to_Reverse_Words_in_String.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void printReversedString(char string[],int size)
{
	char firstWord[20], secondWord[20], reversedstring[20];
	int i, j, spaceindex;
	for(i=0;i<size;i++)
	{
		if (string[i]==' ')
			spaceindex = i;
	}

	for(i=0;i<spaceindex;i++)
	{
		if(string[i]!=' ')
			firstWord[i]=string[i];
		else
			spaceindex=i;
	}
	firstWord[i]='\0';

	for(i=spaceindex+1,j=0;i<size;i++,j++)
	{
		if(string[i]!= '\0')
		secondWord[j]=string[i];
	}
	secondWord[j]='\0';

	strcpy(reversedstring,secondWord);
	strcat(reversedstring," ");
	strcat(reversedstring,firstWord);

	printf("The string after reverse is:\n%s",reversedstring);
}



void main()
{
	char str[100];
	int i, len, spaceIndex;

	printf("Please enter the string: ");
	fflush(stdout); fflush(stdin);
	gets(str);

	len = strlen(str);

	printReversedString(str,len);

}
