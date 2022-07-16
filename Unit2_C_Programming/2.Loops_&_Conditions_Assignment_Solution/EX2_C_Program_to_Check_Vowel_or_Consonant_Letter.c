/*
 ============================================================================
 Name        : EX2_C_Program_to_Check_Vowel_or_Consonant_Letter.c
 Author      : Ahmed Aref Omaira
 Date		 : July 15,2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char letter, lowerCaseVowel, upperCaseVowel;

	printf("Please enter the letter you want to check:");
	fflush(stdout);fflush(stdin);
	scanf("%c",&letter);

	lowerCaseVowel = (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
	upperCaseVowel = (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U');

	if(lowerCaseVowel || upperCaseVowel)
		printf("%c is Vowel",letter);
	else
		printf("%c is Consonant",letter);

	return 0;
}
