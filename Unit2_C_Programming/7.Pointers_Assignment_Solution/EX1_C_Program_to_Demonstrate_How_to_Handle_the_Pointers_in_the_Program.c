/*
 ============================================================================
 Name        : EX1_C_Program_to_Demonstrate_How_to_Handle_the_Pointers_in_the_Program.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>


void main()
{
	int m = 29;
	int* ptr_m = NULL;

	printf("The address of the variable m in memory is 0x%x\n",&m);
	printf("The value stored in variable m in memory is %d\n",m);

	ptr_m=&m;
	printf("Now pointer ptr_m is assigned with the address of the variable m.\n");
	printf("The value stored inside the pointer variable ptr_m (address of variable m) is: 0x%x\n",ptr_m);
	printf("The value pointed to by the pointer variable ptr_m (value of variable m) is %d\n",*ptr_m);

	m = 34;
	printf("The value of variable m is assigned to %d now\n",m);
	printf("The value stored inside the pointer variable ptr_m (address of variable m) is: 0x%x\n",ptr_m);
	printf("The value pointed to by the pointer variable ptr_m (value of variable m) is %d\n",*ptr_m);

	*ptr_m = 7;
	printf("The value of variable m is modified to 7 now using the pointer ptr_m\n");
	printf("The value stored inside the pointer variable ptr_m (address of variable m) is: 0x%x\n",ptr_m);
	printf("The value pointed to by the pointer variable ptr_m (value of variable m) is %d\n",*ptr_m);
}
