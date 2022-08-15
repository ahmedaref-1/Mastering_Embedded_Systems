/*
 ============================================================================
 Name        : EX1_C_Program_to_Store_Information_of_a_Student_Using_Structure.c
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
	fflush(stdout);

	printf("Enter Student Name:");
	fflush(stdout);
	gets(s.m_Name);

	printf("Enter Student Roll Number:");
	fflush(stdout);
	scanf("%d",&s.m_RollNumber);

	printf("Enter Student Marks:");
	fflush(stdout);
	scanf("%f",&s.m_Marks);

	return s;
}

void printStudentStructInformation(struct SStudent s)
{
	printf ("\nDisplaying the student's Information: \n");

	printf ("Student name: %s", s.m_Name);

	printf ("\nStudent's roll number: %d",s.m_RollNumber);

	printf ("\nStudent's marks: %.2f", s.m_Marks);
}
void main()
{
	struct SStudent student = takeStudentStructInformation();
	printStudentStructInformation(student);
}
