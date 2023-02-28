/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), Students_DB Driver, Students_DB.c file
*/

#include"Students_DB.h"

extern STUDENTNODE_t* gp_firstStudent;

STUDENTS_DB_STATE_EN STUDENT_DB_fillRecord(STUDENTNODE_t* newStudentNode) {
	if (!newStudentNode)
		return STUDENTS_DB_FAIL;
	else {
		uint32_t tempArrayOfCharachters[20];

		printf("Enter the Student Name:\n");
		gets(newStudentNode->studentNodeData.studentName);

		printf("Enter the Student ID:\n");
		gets(tempArrayOfCharachters);
		newStudentNode->studentNodeData.studentID = atoi(tempArrayOfCharachters);

		printf("Enter the Student GPA:\n");
		gets(tempArrayOfCharachters);
		newStudentNode->studentNodeData.studentGPA = atof(tempArrayOfCharachters);

		return STUDENTS_DB_OK;
	}
}


STUDENTS_DB_STATE_EN STUDENT_DB_studentAdd() {
	STUDENTNODE_t* pNewStudent;
	STUDENTNODE_t* pLastStudent;

	/* 1. If the list is Empty */
	if (gp_firstStudent == NULL) {
		/* 1.1 Create the new Student struct in the list */
		pNewStudent = (STUDENTNODE_t*)malloc(sizeof(STUDENTNODE_t));
		/* 1.2 Check if the malloc returns NULL */
		if (pNewStudent)
			/* 1.3 Assign the gp_firstStudent to point to the firstStudent (new student) */
			gp_firstStudent = pNewStudent;
		else
			return STUDENTS_DB_FAIL;
	}
	/* 2. If the list contains Elements */
	else {
		/* 2.1 Navigate till reaching the last element in the list */
		pLastStudent = gp_firstStudent;
		while (pLastStudent->studentNodeNextPtr)
			pLastStudent = (STUDENTNODE_t*)(pLastStudent->studentNodeNextPtr);
		/* 2.2 Create the new Student struct in the list */
		pNewStudent = (STUDENTNODE_t*)malloc(sizeof(STUDENTNODE_t));
		/* 2.3 Check if the malloc returns NULL */
		if (pNewStudent)
			/* 2.3 Assign the next pointer of the last element in the list to point to the new added Student */
			pLastStudent->studentNodeNextPtr = (uint32_t*)pNewStudent;
		else return STUDENTS_DB_FAIL;
	}
	/*3. Fill The Record */
	STUDENT_DB_fillRecord(pNewStudent);
	/*4. Set the next pointer of the new added student to the list to point to null since its the last element in the list*/
	pNewStudent->studentNodeNextPtr = NULL;
	return STUDENTS_DB_OK;
}


STUDENTS_DB_STATE_EN STUDENT_DB_studentDelete() {

	uint8_t tempText[20];
	uint32_t IDToBeDeleted;
	
	printf("Enter The Student ID to be Deleted:\n");
	gets(tempText);
	IDToBeDeleted = (uint32_t)atoi(tempText);

	/* 1.Check if the list is empty */
	if (gp_firstStudent) {
		STUDENTNODE_t* pPreviousStudent = NULL;
		STUDENTNODE_t* pSelectedStudent = gp_firstStudent;
		/* 2.Loop on the elements of the list to find the selected ID to be deleted */
		while (pSelectedStudent) {
			/* 3.Compare the current ID with the selected ID to be deleted */
			if (pSelectedStudent->studentNodeData.studentID == IDToBeDeleted) {
				if (pPreviousStudent)
					pPreviousStudent->studentNodeNextPtr = (uint32_t*)pSelectedStudent->studentNodeNextPtr;
				else
					gp_firstStudent = (STUDENTNODE_t*)pSelectedStudent->studentNodeNextPtr;
				free(pSelectedStudent);
				return STUDENTS_DB_OK;
			}
			pPreviousStudent = (STUDENTNODE_t*) pSelectedStudent;
			pSelectedStudent = (STUDENTNODE_t*)(pSelectedStudent->studentNodeNextPtr);
		}
		printf("Can't find Student ID\n ");
	}
	else
	return STUDENTS_DB_FAIL;
}


STUDENTS_DB_STATE_EN STUDENT_DB_studentsListPrint() {
	uint8_t count = 0;
	STUDENTNODE_t* pCurrentStudent = gp_firstStudent;
	if (pCurrentStudent == NULL)
		printf("The List is Empty.\n");
	else {
		while (pCurrentStudent) {
			printf("Record Number %d\n", count + 1);
			printf("Name: %s\n", pCurrentStudent->studentNodeData.studentName);
			printf("ID: %d\n", pCurrentStudent->studentNodeData.studentID);
			printf("GPA: %0.2lf\n", pCurrentStudent->studentNodeData.studentGPA);
			printf("-----------------------------\n");
			pCurrentStudent = (STUDENTNODE_t*)(pCurrentStudent->studentNodeNextPtr);
			count++;
		}
		return STUDENTS_DB_OK;
	}
	return STUDENTS_DB_FAIL;
}

STUDENTS_DB_STATE_EN STUDENT_DB_studentsListDelete() {
	STUDENTNODE_t* pCurrentStudent = gp_firstStudent;
	if (pCurrentStudent == NULL)
		printf("The List is Empty.\n");
	else {
		while (pCurrentStudent) {
			STUDENTNODE_t* pTempStudent = pCurrentStudent;
			pCurrentStudent = (STUDENTNODE_t*)(pCurrentStudent->studentNodeNextPtr);
			free(pTempStudent);
		}
		gp_firstStudent = NULL;
		return STUDENTS_DB_OK;
	}
	return STUDENTS_DB_FAIL;
}

STUDENTS_DB_STATE_EN STUDENT_DB_listGetNode() {
	uint8_t tempText[20];
	uint32_t IDToBeRead;
	
	printf("Enter The Node ID to be Read:\n");
	gets(tempText);
	IDToBeRead = (uint32_t)atoi(tempText);
	
	uint32_t count = 0;
	STUDENTNODE_t* pCurrentStudent;
	pCurrentStudent = gp_firstStudent;
	
	if (pCurrentStudent == NULL)
		printf("The List is Empty\n");
	else {
		while (pCurrentStudent) {
			if (count == IDToBeRead) {
				printf("The data of the node at index %d is:\n", IDToBeRead);
				printf("Record Number %d\n", count + 1);
				printf("Name: %s\n", pCurrentStudent->studentNodeData.studentName);
				printf("ID: %d\n", pCurrentStudent->studentNodeData.studentID);
				printf("GPA: %0.2lf\n", pCurrentStudent->studentNodeData.studentGPA);
				printf("-----------------------------\n");
				return STUDENTS_DB_OK;
			}
			pCurrentStudent = (STUDENTNODE_t*)(pCurrentStudent->studentNodeNextPtr);
			count++;
		}
		return STUDENTS_DB_FAIL;
	}
	
}

STUDENT_DB_studentsListCountIterative() {
	uint8_t count = 0;
	STUDENTNODE_t* pCurrentStudent;
	pCurrentStudent = gp_firstStudent;
	if (pCurrentStudent == NULL)
		printf("The List is Empty\n");
	else {
		while (pCurrentStudent) {
				pCurrentStudent = (STUDENTNODE_t*)(pCurrentStudent->studentNodeNextPtr);
				count++;
			}
		printf("The Number of Elements in The List using Iteration is:%d\n", count);
		return STUDENTS_DB_OK;
		}
		return STUDENTS_DB_FAIL;
}


STUDENT_DB_studentsListCountRecursive(STUDENTNODE_t* ptr_list) {
	if (gp_firstStudent == NULL)
		printf("The List is Empty");
	if (ptr_list == NULL)
		return 0;
	else {
		return (1 + STUDENT_DB_studentsListCountRecursive(ptr_list->studentNodeNextPtr));
	}
}

STUDENTS_DB_STATE_EN STUDENT_DB_studentsListGetNodeFromTheEnd() {
	uint8_t tempText[20];
	uint32_t IndexToBeRead;

	printf("Enter The Node ID from the end to be Read:\n");
	gets(tempText);
	IndexToBeRead = (uint32_t)atoi(tempText);
	uint32_t count = 0;

	if (gp_firstStudent == NULL)
		printf("The List is Empty\n");
	else {
		STUDENTNODE_t* pMain = gp_firstStudent;
		STUDENTNODE_t* pRefrence = gp_firstStudent;
		for (int i = 0; i <= IndexToBeRead; i++)
		{
			pRefrence = pRefrence->studentNodeNextPtr;
		}
		while (pRefrence) {
			pRefrence = pRefrence->studentNodeNextPtr;
			pMain = pMain->studentNodeNextPtr;
			count++;
		}
		printf("The data of the node at index %d from the end is:\n", IndexToBeRead);
		printf("Record Number %d\n", count + 1);
		printf("Name: %s\n", pMain->studentNodeData.studentName);
		printf("ID: %d\n", pMain->studentNodeData.studentID);
		printf("GPA: %0.2lf\n", pMain->studentNodeData.studentGPA);
		printf("-----------------------------\n");
		return STUDENTS_DB_OK;
	}
	return STUDENTS_DB_FAIL;
}

STUDENT_DB_studentsListGetMiddle() {
	if (gp_firstStudent == NULL)
		printf("The List is Empty\n");
	else {
		uint32_t count = 0;
		STUDENTNODE_t* pFast = gp_firstStudent;
		STUDENTNODE_t* pSlow = gp_firstStudent;
		while (pFast) {
			pFast = pFast->studentNodeNextPtr;
			pFast = pFast->studentNodeNextPtr;
			pSlow = pSlow->studentNodeNextPtr;
			count++;
		}
		printf("The node in the middle of the list is of index:%d\n",count);
		printf("Record Number %d\n", count + 1);
		printf("Name: %s\n", pSlow ->studentNodeData.studentName);
		printf("ID: %d\n", pSlow->studentNodeData.studentID);
		printf("GPA: %0.2lf\n", pSlow->studentNodeData.studentGPA);
		printf("-----------------------------\n");
		return STUDENTS_DB_OK;
	}
	return STUDENTS_DB_FAIL;
}

STUDENT_DB_studentsListLoopDetect() {
	if (gp_firstStudent == NULL)
		printf("The List is Empty\n");
	else {
		STUDENTNODE_t* pFast = gp_firstStudent;
		STUDENTNODE_t* pSlow = gp_firstStudent;
		while (pFast->studentNodeNextPtr) {

			pFast = pFast->studentNodeNextPtr;
			pFast = pFast->studentNodeNextPtr;
			pSlow = pSlow->studentNodeNextPtr;
			if (pFast == pSlow) {
				printf("Loop Occured\n");
				return STUDENTS_DB_FAIL;
			}
		}
		printf("No Loop Occured\n");
		return STUDENTS_DB_OK;
	}
}
