/*
 ============================================================================
 Name        : EX4_C_Program_To_Insert_An_Element_in_a_Array.c
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

	printf("Enter the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &insertedElement);

Try_Again:
	printf("Enter the order of the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &insertedElementLocation);

	if( insertedElementLocation>numberOfElements || insertedElementLocation<0 )
		{
			printf("The location of element to be inserted must be a number between 0 and %d, Please try again\n",numberOfElements);
			goto Try_Again;
		}

	//inserting the new element to the array
	for(i=numberOfElements; i>0; i--)
	{
		array[i]=array[i-1];
		if(i==(insertedElementLocation-1))
				{
					array[i]= insertedElement;
				}
	}

	//Printing array after new element is inserted
	for (i = 0; i < numberOfElements+1; i++)
	{
		printf("%d ", array[i]);
	}

}
