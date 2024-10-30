#ifndef CMSC257_P1SUPPORT_INCLUDED
#define CMSC257_P1SUPPORT_INCLUDED
////////////////////////////////////////////////////////////////////////
//
// File          	: p1support.h
// Description    : Headers of general-purpose utility functions 
//					          we use for the 257 project #1.
// Author					:
// Date						:
// Notes					:
////////////////////////////////////////////////////////////////////////
// Add comments for each function below in the following format
///////////////////////////////////////////////////////////////////////
//
// Function       : display_array
// Description    : ..........
// 
// Inputs         : an array of 10 integers
// Outputs        : void
////////////////////////////////////////////////////////////////////////
//
// Function       : 
// Description    : ..........
// 
// Inputs         : 
// Outputs        : 


////////////////////////////////////////////////////////////////////////
// Functional Prototypes
////////////////////////////////////////////////////////////////////////

// This function prints out the array of integer values
void display_array(unsigned int*, int);
//Function	: display_array
//Description	: prints the values of a passed in array
//
//Input		: pointer to an unsigned int array, int length of array
//Output	: void

// Add other function prototypes
int bitwise_add(int x, int y);
//Function	: bitwise_add
//Description	: this function adds two ints and returns the sum using bitwise operators
//
//Input		: 2 integers
//output	: 1 int sum

int bitwise_shift_left(int num1, int num2);
// Function	: bitwise_shift_left
//Description	: shifts an integers bits by a specified amount of bits
//
//Input		: 2 integers
//Ouput		: the shifted int

unsigned int count_set_bits(unsigned int num);
//Function	: count_set_bits
//Description	: counts the number of 1's in a integer's binary respresentation
//
//Input		: unsigned int
//Output	: number of bits in the passed int

int bitwise_mod_32(int num);
//Function	: bitwise_mod_32
//Description	: shifts an int 32 bits
//
//Input		: 1 int
//Output	: int

int bitwise_abs(int num);
//Function	: bitwise_abs
//Description	: returns the absolute value of a passed in int
//
//Input		: 1 int
//Output	: 1 absolute value int

int bit_get(int x, int y);
//Function	: bit_get
//Desciption	: gets a specified bit from an int
//
//Input		: two ints
//Ouput		: int of the specified bit

int odd_or_even(unsigned int num);
//Function	: odd_or_even
//Description	: determines of the passed int is odd or even
//
//Input		: 1 int
//Output	: 1 if the int is odd, 0 if the int is even

void swap_ints(int* num1, int* num2);
//Function	: swap_ints
//Description	: swaps the two int values without using a temporary variable
//
//Input		: 2 ints
//Output	: 2 ints swapped

void binary_string(char *str, unsigned int num);
//Function	: binary_string
//Description	: stores the binary representation of the specified int into the passed array
//
//Input		: a pointer to a string, unsigned int
//Output	: void 
      

#endif // CMSC257_P1SUPPORT_INCLUDED
