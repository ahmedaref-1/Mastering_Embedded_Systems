/*
 ============================================================================
 Name        : Q3_C_Function_That_Reverse_An_Input_Array.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void reverseArray(int size, int a[], int b[])
{
	int i, j;
	for(j=size-1,i=0;j>=0;j--,i++)
		{
			a[j]=b[i];
		}
}

void main()
{
	int inputArray[20], reversedArray[20], numOfElements, i, j;

	printf("Please enter the number of elements of the array:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&numOfElements);

	printf("Please enter the elements of the array:");
	fflush(stdout); fflush(stdin);
	for(i=0;i<numOfElements;i++)
	{
		fflush(stdout);
		scanf("%d",&inputArray[i]);
	}

	printf("The input array before reverse->\n");
	for(i=0;i<numOfElements;i++)
	{
		printf("%d ",inputArray[i]);
	}

	reverseArray(numOfElements, reversedArray, inputArray );

	printf("\nThe input array after reverse->\n");
		for(i=0;i<numOfElements;i++)
		{
			printf("%d ",reversedArray[i]);
		}

}


