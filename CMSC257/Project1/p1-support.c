#include <stdio.h>
#include <string.h>
#include "p1-support.h"
////////////////////////////////////////////////////////////////////////
//
// File          	: p1support.c
// Description    : This is a set of general-purpose utility functions 
//									we use for the 257 project #1.
// Author					: Alex Welk
// Date						:10/13/21
// Notes					:


////////////////////////////////////////////////////////////////////////
// Function Definitions
////////////////////////////////////////////////////////////////////////

//Function definitions as decribed in the project manual 

//this function prints every element of the array passed to it

int i;
void display_array(unsigned int* arr, int size){
	printf("{");
	for(i =0; i < size; i++) {
	
	if(i < size - 1) {	
		printf("%5d,", arr[i]);
}
	else {
		printf("%5d", arr[i]);
}
}

	printf("}\n");	
}

int bitwise_add(int x, int y) {
	while(y != 0) {
		unsigned carry = x&y;
		x = x^y;
		y = carry<<1;
	
}
return x;
}

int bitwise_shift_left(int num1, int num2) {
	return num1 << num2;
}

unsigned int count_set_bits(unsigned int num) {
	unsigned int count = 0;
	while(num > 0) {
		count += num & 1;
		num >>= 1;
}
	return count;
}	
//checked
int bit_get(int x, int y) {
	return (x >> y) & 1;
}

//FINISH
void binary_string(char *str, unsigned int num) {
	unsigned int mask = 0x80000000;
	i = 0;
	str[i++] = '0';
	str[i++] = 'b';
	while(mask > 0) {
		if((num & mask) == 0)
			str[i++] = '0';
		else
			str[i++] = '1';
	mask = mask >> 1;
}
	
	str[i++] = '\0';	
}


void swap_ints(int* num1, int* num2) {
	*num1 = *num1^*num2;
	*num2 = *num1^*num2;
	*num1 = *num1^*num2;
}

int odd_or_even(unsigned int num) {
	if((num & 1) == 1){
		return 1;
}	
else
	return 0;
}

int bitwise_abs(int num) {
	int x = (num >> 31);
	return ((num+x) ^ x);	
}

int bitwise_mod_32(int num) {
	return num & 31;
}
//Additional function definitions for helper functions




