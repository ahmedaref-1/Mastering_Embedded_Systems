/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), Students_DB Driver, Students_DB.c test file
@Copyright: Ahmed Aref Omaira
*/

#include"Students_DB.h"


STUDENTNODE_t* gp_firstStudent = NULL;

int main(void) {
	uint8_t switchCaseKey[20];
	uint8_t tempText[20];
	while (1)
	{
		printf("Choose on of the following options \n");
		printf("1: Add Student\n");
		printf("2: Delete Student\n");
		printf("3: View Students\n");
		printf("4: Delete All\n");
		printf("5: Get Node\n");
		printf("6: Get Students counter by Iteration\n");
		printf("7: Get Students counter by Recursion\n");
		printf("8: Get Node from the end\n");
		printf("9: Get Middle student\n");
		printf("10: Detect if a Loop Occured\n");
		printf("11: Exit\n");
		printf("Enter option number:\n");

		gets(switchCaseKey);
		printf("-----------------------------\n");
		switch (atoi(switchCaseKey))
		{
		case 1:
			STUDENT_DB_studentAdd();
			printf("-----------------------------\n");
			break;

		case 2:
			STUDENT_DB_studentDelete();
			printf("-----------------------------\n");
			break;

		case 3:
			STUDENT_DB_studentsListPrint();
			printf("-----------------------------\n");
			break;

		case 4:
			STUDENT_DB_studentsListDelete();
			printf("-----------------------------\n");
			break;

		case 5:
			STUDENT_DB_listGetNode();
			printf("-----------------------------\n");
			break;

		case 6:
			STUDENT_DB_studentsListCountIterative();
			printf("-----------------------------\n");
			break;

		case 7:
			uint32_t num = STUDENT_DB_studentsListCountRecursive(gp_firstStudent);
			printf("The Number of Elements in the list using recursion is : %d\n", num);
			break;

		case 8:
			STUDENT_DB_studentsListGetNodeFromTheEnd();
			printf("-----------------------------\n");
			break;

		case 9:
			STUDENT_DB_studentsListGetMiddle();
			printf("-----------------------------\n");
			break;

		case 10:
			STUDENT_DB_studentsListLoopDetect();
			printf("-----------------------------\n");
			break;

		case 11:
			return 0;

		default:
			printf("\n Wrong Option: Try Again \n\n");
			break;
		}
	}
}