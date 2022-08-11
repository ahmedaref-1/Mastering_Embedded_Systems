/*
 ============================================================================
 Name        : Q2_C_Program_To_Swap_Two_Arrays_With_Different_Lengths.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int firstArray[20], secondArray[20], tempArray[20];
	int i, j, numOfFirst, numOfSecond;

	printf("Please enter the number of elements of the first array:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&numOfFirst);

	printf("Please enter the number of elements of the second array:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&numOfSecond);

	printf("Please enter the elements of the first array:");
	fflush(stdout); fflush(stdin);
	for(i=0;i<numOfFirst;i++)
	{
		fflush(stdout);
		scanf("%d",&firstArray[i]);
	}

	printf("Please enter the elements of the second array:");
	fflush(stdout); fflush(stdin);
	for(j=0;j<numOfSecond;j++)
	{
		fflush(stdout);
		scanf("%d",&secondArray[j]);
	}

	printf("Arrays Before Swap->");
	fflush(stdout); fflush(stdin);
	printf("\nFirst Array->\t");
	for(i=0;i<numOfFirst;i++)
		{
			printf("%d ",firstArray[i]);
		}
	printf("\nSecond Array->\t");
	for(j=0;j<numOfSecond;j++)
	{
		printf("%d ",secondArray[j]);
	}

	if(numOfFirst>numOfSecond)
	{
		for(i=0;i<numOfFirst;i++)
		{
			tempArray[i]=secondArray[i];
			secondArray[i]=firstArray[i];
			firstArray[i]=tempArray[i];
		}
	}
	else
	{
		for(j=0;i<numOfSecond;j++)
				{
					tempArray[j]=secondArray[j];
					secondArray[j]=firstArray[j];
					firstArray[j]=tempArray[j];
				}
	}

	printf("\nArrays After Swap->");
		fflush(stdout); fflush(stdin);
		printf("\nFirst Array->\t");
		for(i=0;i<numOfSecond;i++)
			{
				printf("%d ",firstArray[i]);
			}
		printf("\nSecond Array->\t");
		for(j=0;j<numOfFirst;j++)
		{
			printf("%d ",secondArray[j]);
		}


}
