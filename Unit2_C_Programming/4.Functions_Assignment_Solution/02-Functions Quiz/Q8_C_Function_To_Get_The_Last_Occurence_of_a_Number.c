/*
 ============================================================================
 Name        : Q8_C_Function_To_Get_The_Last_Occurence_of_a_Number.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int lastOccurrence (int array[],int size, int numbertofind);
void main()
{
	int numbersArray[20], numberToFind, numberOfElements, i;

	printf("Please enter the number of elements of the array:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&numberOfElements);

	printf("Please enter the elements of the array:");
	fflush(stdout); fflush(stdin);
	for(i=0;i<numberOfElements;i++)
	{
		fflush(stdout);
		scanf("%d",&numbersArray[i]);
	}

	printf("Please enter the number you want to get its last occurrence:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&numberToFind);

	printf("The last occurrence of %d in the entered array is at index %d .",numberToFind,lastOccurrence(numbersArray,numberOfElements,numberToFind));
}

int lastOccurrence (int array[],int size, int numbertofind)
{
	int i;
	for(i=size-1; i>=0;i--)
	{
		if(numbertofind==array[i])
			return i+1;
	}
	return -1;
}
