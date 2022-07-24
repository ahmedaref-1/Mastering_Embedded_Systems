/*
 ============================================================================
 Name        : EX1_C_Program_To_Find_Sum_Of_Two_Matrix_Of_Order_2x2.c
 Author      : Ahmed Aref Omaira
 Date        : July 23, 2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float matrix_A [2][2];
	float matrix_B [2][2];
	float matrix_Sum [2][2];
	int i,j;

	printf("Please enter the elements of the first matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Please enter the element in row %d and column %d:",i+1,j+1);
			fflush(stdout);fflush(stdin);
			scanf("%f",&matrix_A[i][j]);
		}

	}


	printf("\nPlease enter the elements of the second matrix:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Please enter the element in row %d and column %d:",i+1,j+1);
			fflush(stdout);fflush(stdin);
			scanf("%f",&matrix_B[i][j]);
		}

	}


	printf("\nThe sum matrix of the two matrices is:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			matrix_Sum[i][j]= matrix_A[i][j] += matrix_B[i][j];
			printf("%0.2f \t",matrix_Sum[i][j]);
		}
	printf("\n");
	}

}
