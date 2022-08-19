/*
 ============================================================================
 Name        : EX4_C_Program_to_Print_the_Elements_of_an_Array_in_reverse_order.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int numbersArray[15], numberOfElements, i;
	int* ptr_numbersArray = NULL;
	ptr_numbersArray = numbersArray;

	printf("Please enter the number of elements of the array:\n");
	fflush(stdout); fflush(stdin);
	scanf("%d",&numberOfElements);

	for(i=0;i<numberOfElements;i++)
	{
		printf("Please enter the array element number %d:\n",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%d",(ptr_numbersArray+i));
	}

	printf("--------------------------------------------------------------\n");
	printf("The elements of the array in reversed order:\n");

	for(i=numberOfElements;i>0;i--)
	{
		printf("element number %d:%d\n",i,((int*)*(ptr_numbersArray+i-1)));
	}


}
