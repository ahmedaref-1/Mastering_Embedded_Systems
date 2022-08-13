/*
 ============================================================================
 Name        : C_Function_To_Return_Unique_Number_in_array_With_One_Loop.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
int count;
int uniqueNumberInArray(int numbersArray[], int numSize, int value)
{
	int i;
	int flag =0;
	for(i=0;i<numSize;i++)
	{
		if(value==numbersArray[i])
			flag++;
	}
	count++;
	if(flag!=1)
		return uniqueNumberInArray(numbersArray,numSize,numbersArray[count]);
	else
		return value;

}
void main()
{
	int arr[10];
	int size, i;
	printf("Please enter the size of the array: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &size);
	printf("you will be asked to enter elements of the array: ");
	fflush(stdout); fflush(stdin);
	for(i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("The unique number in the pre-entered array is %d",uniqueNumberInArray(arr,size,arr[count]));
}
