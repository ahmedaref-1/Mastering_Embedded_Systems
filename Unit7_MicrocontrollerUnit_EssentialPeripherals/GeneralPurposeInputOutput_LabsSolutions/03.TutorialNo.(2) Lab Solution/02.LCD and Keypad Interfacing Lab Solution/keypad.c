/*
 * keypad.c
 *
 * Created: 7/21/2023 5:56:52 AM
 *  Author: Ahmed Aref Omaira
 */ 
#include "Keypad.h"

char KEYPAD_R[] ={R0,R1,R2,R3};
char KEYPAD_C[] ={C0,C1,C2,C3};

void KEYPAD_init()
{
	KEYPAD_PORT_DATADIRECTION &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3)); // Input Pins
	KEYPAD_PORT_DATADIRECTION |= ((1<<C0)| (1<<C1) | (1<<C2) | (1<<C3));// Output Pins
	KEYPAD_DATA_PORT = 0xFF;
	
}

char KEYPAD_getChar()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		KEYPAD_DATA_PORT |= ((1<<KEYPAD_C[0])| (1<<KEYPAD_C[1]) | (1<<KEYPAD_C[2]) | (1<<KEYPAD_C[3]));
		KEYPAD_DATA_PORT &= ~(1<<KEYPAD_C[i]);
		
		for(j=0;j<4;j++)
		{
			if( !(KEYPAD_PORT_PIN& (1<<KEYPAD_R[j])) ) // check if key is pressed
			{
				while( !(KEYPAD_PORT_PIN & (1<<KEYPAD_R[j])) ); // For Single Press
				
				switch(i) // for columns
				{
					//column 0
					case 0 :
					if(j == 0) return '7'; // for row 0 , column 0
					else if(j == 1) return '4'; // for row 1 , column 0
					else if(j == 2) return '1'; // for row 2 , column 0
					else if(j == 3) return '!'; // for row 3 , column 0
					break;
					//column 1
					case 1 :
					if(j == 0) return '8'; // for row 0 , column 1
					else if(j == 1) return '5'; // for row 1 , column 1
					else if(j == 2) return '2'; // for row 2 , column 1
					else if(j == 3) return '0'; // for row 3 , column 1
					break;
					//column 2
					case 2 :
					if(j == 0) return '9'; // for row 0 , column 2
					else if(j == 1) return '6'; // for row 1 , column 2
					else if(j == 2) return '3'; // for row 2 , column 2
					else if(j == 3) return '='; // for row 3 , column 2
					break;
					//column 3
					case 3 :
					if(j == 0) return '/'; // for row 0 , column 3
					else if(j == 1) return '*'; // for row 1 , column 3
					else if(j == 2) return '-'; // for row 2 , column 3
					else if(j == 3) return '+'; // for row 3 , column 3
					break;
				}
			}
		}
	}
	return 'N'; // No Key is Pressed
}
