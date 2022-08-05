/*
 ============================================================================
 Name        : EX3_C_Program_to_Reverse_a_Sentence_Using_Recursion.c
 Author      : Ahmed Aref Omaira
 Date        : August 8, 2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printReversedSentence(char sentence[],char reversedSentence[],int i,int j);

void main()
{
	char sentence[100];
	char reversedSentence[100];
	int i, j;
	printf("Please enter the sentence you want to reverse:");
	fflush(stdout); fflush(stdin);
	gets(sentence);
	i=0;
	j=strlen(sentence)-1;
	printf("The reversed sentence is:");
	printReversedSentence(sentence,reversedSentence,i,j);
}

void printReversedSentence(char sentence[], char reversedSentence[],int i,int j)
{
	reversedSentence[j]=sentence[i];
	i++;
	j--;

	if(j>=0)
		printReversedSentence(sentence,reversedSentence,i,j);
	else
	{
		reversedSentence[i]='\0';
		printf("%s",reversedSentence);
	}

}
