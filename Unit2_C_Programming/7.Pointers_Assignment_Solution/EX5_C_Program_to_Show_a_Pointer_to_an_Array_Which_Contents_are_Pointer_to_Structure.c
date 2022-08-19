/*
 ============================================================================
 Name        : EX5_C_Program_to_Show_a_Pointer_to_an_Array_Which_Contents_are_Pointer_to_Structure.c
 Author      : Ahmed Aref Omaira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct SEmployee
{
	char* name;
	int id;
};

void main()
{

	struct SEmployee E1={"Ahmed",1}, E2={"Aref",2}, E3={"Omaira",3};
	int i;
	//Creating an array of pointers to structs-->
	struct SEmployee *arr_Ptr_SEmployee[] = {&E1,&E2,&E3};
	//Creating a pointer to an array of pointers to structs-->
	struct SEmployee* (*ptr_arr_ptrs_SEmployee)[3] = &arr_Ptr_SEmployee;

	for(i=0;i<3;i++)
		{
			printf("Employee Name: %s\n",(*(*(ptr_arr_ptrs_SEmployee)+i))->name);
			printf("Employee ID : %d\n", (*(*(ptr_arr_ptrs_SEmployee)+i))->id);
			printf("----------------------\n");
		}

}
