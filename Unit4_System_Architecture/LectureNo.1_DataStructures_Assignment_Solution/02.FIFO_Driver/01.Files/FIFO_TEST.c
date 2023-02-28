/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), FIFO Driver, FIFO_TEST.c file
@Copyright: Ahmed Aref Omaira
*/

#include"FIFO.h"

FIFO_BUFFER_DATATYPE gBufferArray[FIFO_BUFFER_LENGTH];
FIFO_BUFFER_t gFIFOBuffer;

void main(void)
{
	FIFO_BUFFER_init(&gFIFOBuffer, &gBufferArray, FIFO_BUFFER_LENGTH);
	for (int j = 0; j < FIFO_BUFFER_LENGTH; j++) {
		if (FIFO_BUFFER_enqueue(&gFIFOBuffer, (j + 1)) == FIFO_OK)
			printf(" The Value %d is inserted to FIFO Buffer at location:%d\n", (j + 1), j);
	}
	printf("---------------------------------------------------------------\n");
	FIFO_BUFFER_print(&gFIFOBuffer);
	printf("---------------------------------------------------------------\n");
	for (int j = FIFO_BUFFER_LENGTH; j > 2; j--) {
		uint32_t temp;
		if (FIFO_BUFFER_dequeue(&gFIFOBuffer, &temp) == FIFO_OK)
			printf(" The Value %d is removed from FIFO Buffer\n", temp );
	}
	printf("---------------------------------------------------------------\n");
	FIFO_BUFFER_print(&gFIFOBuffer);
}