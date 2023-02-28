/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), LIFO Driver, LIFO.c file
@Copyright: Ahmed Aref Omaira
*/

#include "LIFO.h"

LIFO_BUFFER_STATE_EN LIFO_BUFFER_init(LIFO_BUFFER_t* lifoBuffer, uint32_t* bufferArray, uint32_t bufferLength) {
	if (!bufferArray || !lifoBuffer)
		return LIFO_NULL;
	else {
		lifoBuffer->lifoBase = bufferArray;
		lifoBuffer->lifoHead = bufferArray;
		lifoBuffer->lifoLength = bufferLength;
		lifoBuffer->lifoCount = 0;
		return LIFO_OK;
	}
}

LIFO_BUFFER_STATE_EN LIFO_BUFFER_isValid(LIFO_BUFFER_t* lifoBuffer) {
	if (!(lifoBuffer->lifoBase) || !(lifoBuffer->lifoHead) || !(lifoBuffer))
		return LIFO_NULL;
	else
		return LIFO_OK;
}

LIFO_BUFFER_STATE_EN LIFO_BUFFER_push(LIFO_BUFFER_t* lifoBuffer, uint32_t valueToBeStored) {
	if (LIFO_BUFFER_isValid(lifoBuffer) == LIFO_NULL)
		return LIFO_NULL;
	else {
		if (LIFO_BUFFER_isFull(lifoBuffer) == LIFO_FULL)
			return LIFO_FULL;
		else  {
			*(lifoBuffer->lifoHead) = valueToBeStored;
			lifoBuffer->lifoHead++;
			lifoBuffer->lifoCount++;
			return LIFO_OK;
		}
	}

}

LIFO_BUFFER_STATE_EN LIFO_BUFFER_pop(LIFO_BUFFER_t* lifoBuffer, uint32_t* ptrToStorePopedValue) {
	if (LIFO_BUFFER_isValid(lifoBuffer) == LIFO_NULL)
		return LIFO_NULL;
	else {
		if (LIFO_BUFFER_isEmpty(lifoBuffer) == LIFO_EMPTY)
			return LIFO_EMPTY;
		else {
			lifoBuffer->lifoHead--;
			*(ptrToStorePopedValue) = *(lifoBuffer->lifoHead);
			lifoBuffer->lifoCount--;
			return LIFO_OK;
		}
	}
}

LIFO_BUFFER_STATE_EN LIFO_BUFFER_isFull(LIFO_BUFFER_t* lifoBuffer) {
	if (LIFO_BUFFER_isValid(lifoBuffer) == LIFO_NULL)
		return LIFO_NULL;
	else {
		if (lifoBuffer->lifoCount == lifoBuffer->lifoLength)
			return LIFO_FULL;
		else
			return LIFO_NOT_FULL;
	}
}

LIFO_BUFFER_STATE_EN LIFO_BUFFER_isEmpty(LIFO_BUFFER_t* lifoBuffer) {
	if (LIFO_BUFFER_isValid(lifoBuffer) == LIFO_NULL)
		return LIFO_NULL;
	else {
		if (lifoBuffer->lifoCount == 0)
			return LIFO_EMPTY;
		else
			return LIFO_NOT_EMPTY;
	}
}

LIFO_BUFFER_STATE_EN LIFO_BUFFER_print(LIFO_BUFFER_t* lifoBuffer) {
	if (LIFO_BUFFER_isValid == LIFO_OK)
		return LIFO_NULL;
	else {
		uint32_t* ptrToPrintLIFOElements = lifoBuffer->lifoBase;
		if (LIFO_BUFFER_isEmpty(lifoBuffer) == LIFO_EMPTY)
			return LIFO_EMPTY;
		else {
			printf(" LIFO Buffer Elemnts are being printed in order\n");
			for (int i = 0; i < lifoBuffer->lifoCount; i++)
			{
				if (LIFO_BUFFER_isEmpty(lifoBuffer) == LIFO_NOT_EMPTY)
				{
					printf("\t Element at location %d is : %d\n", (i), *(ptrToPrintLIFOElements));
					ptrToPrintLIFOElements++;
				}

			}
			return LIFO_OK;
		}
	}

}


