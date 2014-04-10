/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	03-19-2014 16:51
*
* Filename:		test.c
*
* Description: 
*
*
* A permutation is an ordered arrangement of objects. 
* For example, 3124 is one possible permutation of the 
* digits 1, 2, 3 and 4. If all of the permutations are 
* listed numerically or alphabetically, we call it 
* lexicographic order. The lexicographic permutations 
* of 0, 1 and 2 are:
*
* 012   021   102   120   201   210
*
* What is the millionth lexicographic permutation of the 
* digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*
*
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../euler.h"

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define LIMIT	1000000
#define END		10

int arr[END+1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int total=0;

int main(int argc, char** argv)
{

	while(total <= LIMIT)
	{
		_euler_lexical_perm(&arr, END);
		total++;
	}

	_euler_print_arr(arr, END);

	return EXIT_SUCCESS;
}

