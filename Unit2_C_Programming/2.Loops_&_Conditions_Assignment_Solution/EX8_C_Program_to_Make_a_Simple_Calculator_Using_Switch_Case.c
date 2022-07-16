/*
 ============================================================================
 Name        : EX8_C_Program_to_Make_a_Simple_Calculator_Using_Switch_Case.c
 Author      : Ahmed Aref Omaira
 Date        : July 15,2022
 ============================================================================
 */

#include <stdio.h>

int main()
{
	char op;
	float first, second;

	printf("Please choose the corresponding operator to the required operation to be done (*,/,+,-):");
	fflush(stdout); fflush(stdin);
	scanf("%c",&op);
	fflush(stdout); fflush(stdin);
	printf("Please enter two numbers as follow first/second:");
	fflush(stdout); fflush(stdin);
	scanf("%f/%f",&first,&second);

	switch (op)
	  {
	    case '+':
	      printf("%.1f + %.1f = %.1f", first, second, (first + second));
	      break;
	    case '-':
	      printf("%.1f - %.1f = %.1f", first, second, (first - second));
	      break;
	    case '*':
	      printf("%.1f * %.1f = %.1f", first, second, (first * second));
	      break;
	    case '/':
	      printf("%.1f / %.1f = %.1f", first, second, (first / second));
	      break;

	    default:
	      printf("Error! operator is not correct");
	  }

	return 0;
}
