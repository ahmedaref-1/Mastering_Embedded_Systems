/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), LIFO Driver, LIFO.h file
@Copyright: Ahmed Aref Omaira
*/

#ifndef LIFO_H__
#define LIFO_H__
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdint.h"

/********************************************************************************/
/*                         USER CONFIGURATION                                   */
/********************************************************************************/

#define LIFO_BUFFER_LENGTH 5
#define LIFO_BUFFER_DATATYPE uint32_t

/********************************************************************************/
/*                           TYPE DEFENITIONS                                   */
/********************************************************************************/

typedef struct {
	uint32_t* lifoBase;
	uint32_t* lifoHead;
	uint32_t lifoCount;
	uint32_t lifoLength;
}LIFO_BUFFER_t;

typedef enum {
	LIFO_OK,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL
}LIFO_BUFFER_STATE_EN;

/********************************************************************************/
/*                           FUNCTIONS PROTOYPES                                */
/********************************************************************************/

LIFO_BUFFER_STATE_EN LIFO_BUFFER_init(LIFO_BUFFER_t* lifoBuffer, uint32_t* bufferArray, uint32_t bufferLength);
LIFO_BUFFER_STATE_EN LIFO_BUFFER_push(LIFO_BUFFER_t* lifoBuffer, uint32_t valueToBeStored);
LIFO_BUFFER_STATE_EN LIFO_BUFFER_pop(LIFO_BUFFER_t* lifoBuffer , uint32_t* ptrToStorePopedValue);
LIFO_BUFFER_STATE_EN LIFO_BUFFER_isValid(LIFO_BUFFER_t* lifoBuffer);
LIFO_BUFFER_STATE_EN LIFO_BUFFER_isFull(LIFO_BUFFER_t* lifoBuffer);
LIFO_BUFFER_STATE_EN LIFO_BUFFER_isEmpty(LIFO_BUFFER_t* lifoBuffer);
LIFO_BUFFER_STATE_EN LIFO_BUFFER_print(LIFO_BUFFER_t* lifoBuffer);

#endif
