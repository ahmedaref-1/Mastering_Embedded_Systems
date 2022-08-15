/*
 ============================================================================
 Name        : EX2_C_Program_to_Add_Two_Distances_Systems_Using_Structure.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct SDistance
{
	int m_Feet;
	float m_Inch;
};

struct SDistance takeDistanceStructInformation()
{
	struct SDistance Distance;

	printf ("\nEnter the distance in feet: " );
	fflush (stdin); fflush(stdout);
	scanf ("%d", &Distance.m_Feet );

	printf ("Enter the distance in inches: " );
	fflush (stdin); fflush(stdout);
	scanf ("%f", &Distance.m_Inch );

	return Distance ;
}

struct SDistance addDistances (struct SDistance First_Distance, struct SDistance Second_Distance)
{
	struct SDistance Result;

	Result.m_Feet = First_Distance.m_Feet + Second_Distance.m_Feet ;
	Result.m_Inch = First_Distance.m_Inch + Second_Distance.m_Inch;

	while(Result.m_Inch >= 12)
	{
		Result.m_Inch = Result.m_Inch - 12.0;
		++Result.m_Feet;
	}

	return Result ;
}

void printDistanceStruct(struct SDistance s)
{
	printf ("\nThe SUM of the distances is: %d',-%.1f\".", s.m_Feet, s.m_Inch);
}

void main()
{
	struct SDistance distance1,distance2,sum;

	printf("Please enter the information of the 1st distance:");
	fflush(stdout);
	distance1=takeDistanceStructInformation();

	printf("Please enter the information of the 2nd distance:");
	fflush(stdout);
	distance2=takeDistanceStructInformation();

	sum = addDistances(distance1,distance2);
	printDistanceStruct(sum);


}
