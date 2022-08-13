/*
 ============================================================================
 Name        : Q1_C_Function_to_Take_a_Number_and_Sum_all_its_Digits.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int sumOfDigitsFunc(int num)
{
	static int sumOfDigits = 0;
	int remainder;
	if(num!=0)
	{
		remainder=num%10;
		sumOfDigits+=remainder;
		sumOfDigitsFunc(num/10);
	}
	else
		return 0;
	return sumOfDigits;

}
void main()
{
	int number;
	printf("Please enter the number you want to calculate the sum of its digits:");
	fflush(stdout); fflush(stdin);
	scanf("%d",&number);
	printf("The sum of digits of %d is %d .",number,sumOfDigitsFunc(number));
}
