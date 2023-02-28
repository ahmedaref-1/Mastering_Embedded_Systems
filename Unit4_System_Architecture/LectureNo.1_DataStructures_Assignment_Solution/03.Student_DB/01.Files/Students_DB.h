/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), Students_DB Driver, Students_DB.h file
@Copyright: Ahmed Aref Omaira
*/

#ifndef STUDENTS_DB_H__
#define STUDENTS_DB_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define NULL ((void *)0)

/********************************************************************************/
/*                         USER CONFIGURATION                                   */
/********************************************************************************/

#define STUDENT_NAME_LENGTH 30

/********************************************************************************/
/*                         TYPE DEFENITIONS                                     */
/********************************************************************************/

typedef struct {
	uint8_t studentName[STUDENT_NAME_LENGTH];
	uint8_t studentID;
	double   studentGPA;
}STUDENTDATA_t;

typedef struct {
	STUDENTDATA_t studentNodeData;
	uint32_t* studentNodeNextPtr;
}STUDENTNODE_t;

typedef enum {
	STUDENTS_DB_OK,
	STUDENTS_DB_FAIL
}STUDENTS_DB_STATE_EN;
/********************************************************************************/
/*                       FUNCTION PROTOTYPES                                    */
/********************************************************************************/

// Fill the student data
STUDENTS_DB_STATE_EN STUDENT_DB_fillRecord(STUDENTNODE_t* newStudentNode);

// Add a student to the list
STUDENTS_DB_STATE_EN STUDENT_DB_studentAdd();

// Delete a student from the list
STUDENTS_DB_STATE_EN STUDENT_DB_studentDelete();

// Print all students in the list
STUDENTS_DB_STATE_EN STUDENT_DB_studentsListPrint();

// Delete all students in the list
STUDENTS_DB_STATE_EN STUDENT_DB_studentsListDelete();

// Get a Student node form the list
STUDENTS_DB_STATE_EN STUDENT_DB_listGetNode();

// Get the list length using iteration (looping)
STUDENTS_DB_STATE_EN STUDENT_DB_studentsListCountIterative();

// Get the list length using recursion
uint32_t STUDENT_DB_studentsListCountRecursive(STUDENTNODE_t* ptr_list);

// Get a Student node form the end of list
STUDENTS_DB_STATE_EN STUDENT_DB_studentsListGetNodeFromTheEnd();

// Get the middle student even the number (odd or even)
STUDENTS_DB_STATE_EN STUDENT_DB_studentsListGetMiddle();

// Detect occurence of loops
STUDENTS_DB_STATE_EN STUDENT_DB_studentsListLoopDetect();

#endif // !STUDENTS_DB_H__
