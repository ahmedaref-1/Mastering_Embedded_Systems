/*
 ============================================================================
 Name        : EX7_C_Program_To_Swap_Two_Numbers_Without_Temp_Variable.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x = 20, y = 10;

    // Code to swap 'x' and 'y'
    x = x + y; // x now becomes 30
    y = x - y; // y becomes 20
    x = x - y; // x becomes 10

    printf("After Swapping: x = %d, y = %d", x, y);

}
