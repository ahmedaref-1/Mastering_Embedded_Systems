/*
 ============================================================================
 Name        : EX1_Prime_Numbers_between_two_Intervals_by_Making_User_Defiend_Function.c
 Author      : Ahmed Aref Omaira
 Date        : July 31,2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printPrimeNumbers(int first,int last);

void main()
{
	int start,end;

	printf("Please enter the start of the interval:\n");
	fflush(stdout); fflush(stdin);
	scanf("%d",&start);

	printf("Please enter the end of the interval:\n");
	fflush(stdout); fflush(stdin);
	scanf("%d",&end);

	printPrimeNumbers(start,end);

}

/*
 * 	-----------------------------------------------------------------------------------
 * 	Prime numbers are numbers in which the result from the remainder operation equals 0,
 * 	in two cases only which are at division by 1 and division by itself only, since case
 * 	of division by one is always valid so we will start to check from division by 2
 * 	-----------------------------------------------------------------------------------
 */


void printPrimeNumbers (int first, int last)
{
	int i, j, k, notPrimeFlag;

	printf("The prime numbers in the interval between %d and %d are:\n",first,last);


	/*
	 * For loop to run through the values of the interval
	 */

	for(i=first;i<=last;i++)
	{
		notPrimeFlag=0;

		/*
		 * For loop to check wither the number am iterating on now is prime or not
		 * this is done by checking the remainder of the division operation of this value
		 * by all integer numbers starting from 2 to value/2 , if the remainder equals zero
		 * at any time then a flag is set and this indicates that the number is not a prime number
		 */
		for(j=2;j<=(i/2);j++)
		{
			if((i%j)==0)
			{
				notPrimeFlag=1;
				break;
			}
		}
		if(notPrimeFlag==0)
			printf("%d ",i);
	}
}
