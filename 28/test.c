/*******************************************
 *
 * Author: HzChen - hzchen_cs@gwmail.gwu.edu
 *
 *
 * Last modified:	03-25-2014 21:05
 *
 * Filename:		test.c
 *
 * Description: 
 *
 *
 *
 *
 * Starting with the number 1 and moving to 
 * the right in a clockwise direction a 5 by 
 * 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers 
 * on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals 
 * in a 1001 by 1001 spiral formed in the same way?
 *
 *
 ******************************************/
#include <stdlib.h>
#include <stdio.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define SZ	1001

int main(int argc, char** argv)
{

	int finalDiff = 2 * ((SZ-1) / 2 );
	long sum=1;
	int start=1, prev=1, diff=2;
	for(diff = 2; diff <= finalDiff; diff+= 2)
	{
		start = prev + diff;
		sum += start * 4 + diff * 6;
		prev = start + 3 * diff;
	}

	printf("sum is %ld\n", sum);

	return EXIT_SUCCESS;
}

