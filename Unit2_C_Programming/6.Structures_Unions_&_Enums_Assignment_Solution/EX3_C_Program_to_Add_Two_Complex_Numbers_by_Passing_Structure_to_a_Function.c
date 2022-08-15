/*
 ============================================================================
 Name        : EX3_C_Program_to_Add_Two_Complex_Numbers_by_Passing_Structure_to_a_Function.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct SComplexNumber
{
	float m_Real;
	float m_Imaginary;
};

struct SComplexNumber takeComplexNumberStructInofrmation()
{
	struct SComplexNumber s;
	printf("Enter Real and Imaginary respectively:");
	fflush(stdout);
	scanf("%f %f",&s.m_Real,&s.m_Imaginary);
	return s;
}

struct SComplexNumber addTwoComplexNumbersStructs(struct SComplexNumber s1,struct SComplexNumber s2)
{
	struct SComplexNumber s3;
	s3.m_Real = s1.m_Real + s2.m_Real;
	s3.m_Imaginary = s1.m_Imaginary + s2.m_Imaginary;
	return s3;
}

void printComplexNumberStruct(struct SComplexNumber s)
{

	printf("Sum = %0.1f +%0.1fi ", s.m_Real, s.m_Imaginary);
}

void main()
{
	struct SComplexNumber s1,s2,sum;

	printf("Please enter the first complex number:\n");
	s1 = takeComplexNumberStructInofrmation();

	printf("Please enter the second complex number:\n");
	s2 = takeComplexNumberStructInofrmation();

	printComplexNumberStruct(addTwoComplexNumbersStructs(s1,s2));
}
