/*
 ============================================================================
 Name        : EX4_C_Program_to_Store_Information_of_Students_Using_Structure.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>

struct SStudent
{
	char m_Name[50];
	int m_RollNumber;
	float m_Marks;
};

struct SStudent takeStudentStructInformation()
{
	struct SStudent s;
	printf("Please enter the information of the student:\n");
	fflush(stdout);fflush(stdin);

	printf("Enter Student Name:\n");
	fflush(stdout); fflush(stdin);
	gets(s.m_Name);

	printf("Enter Student Roll Number:\n");
	fflush(stdout); fflush(stdin);
	scanf("%d",&s.m_RollNumber);

	printf("Enter Student Marks:\n");
	fflush(stdout); fflush(stdin);
	scanf("%f",&s.m_Marks);

	return s;
}

void printStudentStructInformation(struct SStudent s)
{

	printf ("\nStudent name: %s", s.m_Name);

	printf ("\nStudent's roll number: %d",s.m_RollNumber);

	printf ("\nStudent's marks: %.2f", s.m_Marks);
}
void main()
{
	struct SStudent studentStructArray[5];
	int i;
	for(i=0;i<(sizeof(studentStructArray)/sizeof(struct SStudent));i++)
	{
		studentStructArray[i]= takeStudentStructInformation();
	}

	printf ("\nDisplaying the student's Information:");

	for(i=0;i<(sizeof(studentStructArray)/sizeof(struct SStudent));i++)
		{
			printStudentStructInformation(studentStructArray[i]);
		}
}
