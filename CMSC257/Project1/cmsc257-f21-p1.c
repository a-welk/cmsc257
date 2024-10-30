////////////////////////////////////////////////////////////////////////
//
// File          : cmsc257-f21-p1.c
// Description   : This is a part of the starter code for CMSC 257 
//	               Plese see the course page for more details	
//
// Author        : Alex Welk
// Last Modified : Enter last modification date here
//

// Include Files
#include <stdio.h>
#include <stdlib.h>

// Project Includes
#include "p1-support.h"

// Functions
///////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 project #1
// 
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful

int main(int argc, char *argv[]) {

	// Local variables
	int int_array1[10];
	unsigned int uint_array1[10], uint_array2[10];
	int i;
	//Add more local variables here as needed
	int input = 0;
	char binary[35];
	char even_odd[4];
	//Checking if there are less than 10 inputs 
	if (argc < 11)
	{   
		//Exit if there are less than 10 inputs
		printf("Exiting the program, missing input");
		return 0;	
	}


	// Step a - Read in the integer numbers input at 
	// the time of exeution and save them into int_array1
	for (i=1; i<11; i++) {
		int_array1[i-1] = atoi(argv[i]);//converting input to integer

	}

	// Step b - Reverse the order of array elements in int_array1 
	//          using swap_ints function. 
	for(i = 0; i < 5; i++) {
		int *p = &int_array1[i];
		int *b = &int_array1[9-i];
		swap_ints(p, b);
		int_array1[i] = *p;
		int_array1[9-i] = *b;		
	}
	// Step c - Get an integer user input and add that number to all elements
	//          of the int_array1 using bitwise_add function
	printf("Enter an integer offset\n");
	scanf("%d", &input);
	for(i =0; i < 10; i++) {
		int_array1[i] = bitwise_add(int_array1[i], input);
	}	
	// Step d - Get the absolute values of the elements in the int_array using
	//	        bitwise_abs function and save them in uint_array1. 
	//        - Print all numbers in a single line using display_array function
	for(i = 0; i < 10; i++) {
 		uint_array1[i] = bitwise_abs(int_array1[i]);
	}
	display_array(uint_array1, 10);
	// Step e - Get the mod 32 of numbers in the uint_array1
	//          (in the range 0,…,31) using bitwise_mod32 function
	//          then save them into uint_array2. 
	//        - Print all elements of uint_array2 using display_array function
	for(i = 0; i < 10; i++) {
		uint_array2[i] = bitwise_mod_32(uint_array1[i]);
	}
	display_array(uint_array2, 10);
	// Step f - Get user input (an integer in the range of 0 - 31)
	//          and shift left each element of uint_array2 with that number
	//		    - Print all elements of uint_array2 using display_array function
	printf("Enter an integer shift value\n");
	scanf("%d", &input);

	for(i = 0; i < 10; i++) {
		uint_array2[i] = bitwise_shift_left(uint_array2[i], input);
	}
	display_array(uint_array2, 10);
	// Step g - for each integer in uint_array2 print: 
	//          number, number of set bits, even or odd
	//          using respective functions and in the format specified within 
	//          the project manual
	for(i = 0; i < 10; i++) {
		if(odd_or_even(uint_array2[i]) == 1) {
			even_odd[0] = 'o';
			even_odd[1] = 'd';
			even_odd[2] = 'd';
			even_odd[3] = '\0';
}
		else {
			even_odd[0] = 'e';
			even_odd[1] = 'v';
			even_odd[2] = 'e';
			even_odd[3] = 'n';
			even_odd[4] = '\0';
}
		printf("[number: %5d, # of 1 bits: %5d, %5s]\n", uint_array2[i], count_set_bits(uint_array2[i]), even_odd);
	
	}
	// Step h - Print each element of uint_array2 in a separate line along with 
	// 		      the binary representation of each of the numbers using 
	// 		      binary_string function. 
	char *s = binary;
	for(i = 0; i < 10; i++) {
		binary_string(s, uint_array2[i]);
		printf("[number: %5d, binary: %5s]\n", uint_array2[i], s);
	}
	// Return successfully
	return(0);
}
