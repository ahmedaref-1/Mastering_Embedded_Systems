/*
 ============================================================================
 Name        : EX3_C_Program_To_Find_Transpose_Of_A_Matrix.c
 Author      : Ahmed Aref Omaira
 Date  		 : July 23, 2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int matrix[100][100];
	int t_matrix[100][100];
	int row, column;
	int i, j;
Evaluate_Again:
	printf("Enter number of rows of the matrix : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &row);
	printf("Enter number of columns of the matrix : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &column);

	if(((row>100)||(row<=0))||((column>100)||(column<=0)))
	{
		printf("The number of both rows and columns must be in the range from 0 to 100, please try again\n");
		goto Evaluate_Again;
	}

	printf("Enter elements of the matrix : \n");
		for (i = 0; i < row; i++)
		{
			for(j = 0; j < column; j++)
			{
				printf("Enter element of row %d and column %d : ", i+1, j+1);
				fflush(stdin); fflush(stdout);
				scanf("%d", &matrix[i][j]);
			}
		}

	printf("Entered matrix:\n");
	for (i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("%d\t", matrix[i][j]);
		}

		printf("\n");
	}


	for (i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			t_matrix[j][i]= matrix[i][j];
		}
	}

	printf("Transposed matrix:\n");
		for (i = 0; i < column; i++)
		{
			for(j = 0; j < row; j++)
			{
				printf("%d\t", t_matrix[i][j]);
			}

			printf("\n");
		}
}
