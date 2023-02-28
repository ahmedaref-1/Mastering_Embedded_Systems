/*
LearnInDepth, UnitNo.(4), System Archticutre, LessonNo.(1), Data Structures
Assignment No.(1), LIFO Driver, LIFO_TEST.c file
@Copyright: Ahmed Aref Omaira
*/

#include"LIFO.h"

LIFO_BUFFER_DATATYPE gBufferArray[LIFO_BUFFER_LENGTH];
LIFO_BUFFER_t gLIFOBuffer;

void main(void)
{
	LIFO_BUFFER_init(&gLIFOBuffer, &gBufferArray, LIFO_BUFFER_LENGTH);
	for (int j = 0; j < LIFO_BUFFER_LENGTH; j++) {
		if(LIFO_BUFFER_push(&gLIFOBuffer, (j + 1))== LIFO_OK)
		printf(" The Value %d is Pushed to LIFO Buffer at location:%d\n",(j + 1), j);
	}
	printf("---------------------------------------------------------------\n");
	LIFO_BUFFER_print(&gLIFOBuffer);
	printf("---------------------------------------------------------------\n");
	for (int j = LIFO_BUFFER_LENGTH; j > 2; j--) {
		uint32_t temp;
		if(LIFO_BUFFER_pop(&gLIFOBuffer, &temp) == LIFO_OK)
		printf(" The Value %d is Poped from LIFO Buffer at location:%d\n",temp, (j-1));
	}
	printf("---------------------------------------------------------------\n");
	LIFO_BUFFER_print(&gLIFOBuffer);
}