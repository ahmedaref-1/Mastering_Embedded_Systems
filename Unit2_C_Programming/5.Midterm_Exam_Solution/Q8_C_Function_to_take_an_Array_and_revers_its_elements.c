/*
 ============================================================================
 Name        : Q8_C_Function_to_take_an_Array_and_revers_its_elements.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void printReversedArray (int array[],int size)
{
	int i;
	for(i=size-1;i>=0;i--)
		printf("%d ",array[i]);
}
void main()
{
	int arr[10];
	int size, i;

	printf("Please enter the size of the array: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &size);

	printf("you will be asked to enter the elements of the array: ");
	fflush(stdout); fflush(stdin);
	for(i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("The reversed array is ->\n");
	printReversedArray(arr,size);
}
