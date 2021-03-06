/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	03-14-2014 15:43
*
* Filename:		test.c
*
* Description: 
*
* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
* Find the sum of all the multiples of 3 or 5 below 1000.
*
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>

#define NUM1 3
#define NUM2 5


int main(int argc, char** argv)
{
	int sum = 0;
	int max = 1000;
	int i=0;

	for(i=0; i<max; i++)
	{
		if( !(i%NUM1) || !(i%NUM2))
			sum += i;
	}

	printf("sum is: %d\n", sum);
	return EXIT_SUCCESS;
}

