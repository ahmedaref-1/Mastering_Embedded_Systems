/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), FIFO Driver, FIFO.h file
@Copyright: Ahmed Aref Omaira
*/

#ifndef FIFO_H__
#define FIFO_H__
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdint.h"

/********************************************************************************/
/*                         USER CONFIGURATION                                   */
/********************************************************************************/

#define FIFO_BUFFER_LENGTH 5
#define FIFO_BUFFER_DATATYPE uint32_t

/********************************************************************************/
/*                           TYPE DEFENITIONS                                   */
/********************************************************************************/

typedef struct {
	uint32_t* fifoBase;
	uint32_t* fifoHead;
	uint32_t* fifoTail;
	uint32_t fifoCount;
	uint32_t fifoLength;
}FIFO_BUFFER_t;

typedef enum {
	FIFO_OK,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}FIFO_BUFFER_STATE_EN;

/********************************************************************************/
/*                           FUNCTIONS PROTOYPES                                */
/********************************************************************************/

FIFO_BUFFER_STATE_EN FIFO_BUFFER_init(FIFO_BUFFER_t* fifoBuffer, uint32_t* bufferArray, uint32_t bufferLength);
FIFO_BUFFER_STATE_EN FIFO_BUFFER_enqueue(FIFO_BUFFER_t* fifoBuffer, uint32_t valueToBeStored);
FIFO_BUFFER_STATE_EN FIFO_BUFFER_dequeue(FIFO_BUFFER_t* fifoBuffer, uint32_t* ptrToStorePopedValue);
FIFO_BUFFER_STATE_EN FIFO_BUFFER_isValid(FIFO_BUFFER_t* fifoBuffer);
FIFO_BUFFER_STATE_EN FIFO_BUFFER_isFull(FIFO_BUFFER_t* fifoBuffer);
FIFO_BUFFER_STATE_EN FIFO_BUFFER_isEmpty(FIFO_BUFFER_t* fifoBuffer);
FIFO_BUFFER_STATE_EN FIFO_BUFFER_print(FIFO_BUFFER_t* fifoBuffer);

#endif