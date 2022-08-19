/*
 ============================================================================
 Name        : EX2_C_Program_to_Print_All_Alphabets_Using_a_pointer.c
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
	char alphabet = 'A';
	char* ptr_alphabet = NULL;
	int i;
	//Number of alphabet letters is 26 Letter
	ptr_alphabet = alphabet;
	for(i=0;i<26;i++)
	{
		printf("%c ",(char*)ptr_alphabet);
		*ptr_alphabet++;
	}
}
