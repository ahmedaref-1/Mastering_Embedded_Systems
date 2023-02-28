/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), FIFO Driver, FIFO.c file
@Copyright: Ahmed Aref Omaira
*/

#include "FIFO.h"

FIFO_BUFFER_STATE_EN FIFO_BUFFER_init(FIFO_BUFFER_t* fifoBuffer, uint32_t* bufferArray, uint32_t bufferLength) {
	if (!bufferArray || !fifoBuffer)
		return FIFO_NULL;
	else {
		fifoBuffer->fifoBase = bufferArray;
		fifoBuffer->fifoHead = bufferArray;
		fifoBuffer->fifoTail = bufferArray;
		fifoBuffer->fifoLength = bufferLength;
		fifoBuffer->fifoCount = 0;
		return FIFO_OK;
	}
}

FIFO_BUFFER_STATE_EN FIFO_BUFFER_isValid(FIFO_BUFFER_t* fifoBuffer) {
	if (!(fifoBuffer->fifoBase) || !(fifoBuffer->fifoHead) || !(fifoBuffer))
		return FIFO_NULL;
	else
		return FIFO_OK;
}

FIFO_BUFFER_STATE_EN FIFO_BUFFER_enqueue(FIFO_BUFFER_t* fifoBuffer, uint32_t valueToBeStored) {
	if (FIFO_BUFFER_isValid(fifoBuffer) == FIFO_NULL)
		return FIFO_NULL;
	else {
		if (FIFO_BUFFER_isFull(fifoBuffer) == FIFO_FULL)
			return FIFO_FULL;
		else {
			*(fifoBuffer->fifoHead) = valueToBeStored;
			fifoBuffer->fifoCount++;

			if (fifoBuffer->fifoHead == (fifoBuffer->fifoBase + fifoBuffer->fifoLength * sizeof(FIFO_BUFFER_DATATYPE)))
				fifoBuffer->fifoHead == fifoBuffer->fifoBase;
			else
				fifoBuffer->fifoHead++;
			return FIFO_OK;
		}
	}
}

FIFO_BUFFER_STATE_EN FIFO_BUFFER_dequeue(FIFO_BUFFER_t* fifoBuffer, uint32_t* ptrToStorePopedValue) {
	if (FIFO_BUFFER_isValid(fifoBuffer) == FIFO_NULL)
		return FIFO_NULL;
	else {
		if (FIFO_BUFFER_isEmpty(fifoBuffer) == FIFO_EMPTY)
			return FIFO_EMPTY;
		else {
			*(ptrToStorePopedValue) = *(fifoBuffer->fifoTail);
			fifoBuffer->fifoCount--;
			if (fifoBuffer->fifoTail == (fifoBuffer->fifoBase + fifoBuffer->fifoLength * sizeof(FIFO_BUFFER_DATATYPE)))
				fifoBuffer->fifoTail = fifoBuffer->fifoBase;
			else
				fifoBuffer->fifoTail++;
			return FIFO_OK;
		}
	}
}

FIFO_BUFFER_STATE_EN FIFO_BUFFER_isFull(FIFO_BUFFER_t* fifoBuffer) {
	if (FIFO_BUFFER_isValid(fifoBuffer) == FIFO_NULL)
		return FIFO_NULL;
	else {
		if (fifoBuffer->fifoCount == fifoBuffer->fifoLength)
			return FIFO_FULL;
		else
			return FIFO_NOT_FULL;
	}
}

FIFO_BUFFER_STATE_EN FIFO_BUFFER_isEmpty(FIFO_BUFFER_t* fifoBuffer) {
	if (FIFO_BUFFER_isValid(fifoBuffer) == FIFO_NULL)
		return FIFO_NULL;
	else {
		if (fifoBuffer->fifoCount == 0)
			return FIFO_EMPTY;
		else
			return FIFO_NOT_EMPTY;
	}
}

FIFO_BUFFER_STATE_EN FIFO_BUFFER_print(FIFO_BUFFER_t* fifoBuffer) {
	if (FIFO_BUFFER_isValid(fifoBuffer) == FIFO_NULL)
		return FIFO_NULL;
	else {
		uint32_t* ptrToPrintFIFOElements = fifoBuffer->fifoTail;
		if (FIFO_BUFFER_isEmpty(fifoBuffer) == FIFO_EMPTY)
			return FIFO_EMPTY;
		else {
			printf(" FIFO Buffer Elemnts are being printed in order\n");
			for (int i = 0; i < fifoBuffer->fifoCount; i++)
			{
					printf("\t %d\n",*(ptrToPrintFIFOElements));
					ptrToPrintFIFOElements++;
			}
			return FIFO_OK;
		}
	}

}


