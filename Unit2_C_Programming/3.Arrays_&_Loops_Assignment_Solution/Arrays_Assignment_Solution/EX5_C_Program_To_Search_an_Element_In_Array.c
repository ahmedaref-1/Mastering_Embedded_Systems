/*
 ============================================================================
 Name        : EX5_C_Program_To_Search_an_Element_In_Array.c
 Author      : Ahmed Aref Omaira
 Date        : July 23, 2022.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int array[100];
	int numberOfElements, insertedElement, insertedElementLocation, i;
Evaluate_Again:
	printf("Please enter the number of elements of the array:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&numberOfElements);

	if( numberOfElements>100 || numberOfElements<=0 )
	{
		printf("The number of elements of the array must be a number between 0 and 100, Please try again\n");
		goto Evaluate_Again;
	}

	printf("You will be asked to enter the array elements\n");
	fflush(stdout);fflush(stdin);

	for(i=0;i<numberOfElements;i++)
	{
		scanf("%d",&array[i]);
	}

	printf("Enter the element to be searched for : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &insertedElement);

	for(i=0;i<numberOfElements;i++)
	{
		if(array[i]==insertedElement)
		{
			printf("The inserted element is found on location %d",i+1);
			break;
		}
	}
}
