/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	01-25-2014 06:35
*
* Filename:		test.c
*
* Description: 
*
* The sum of the squares of the first ten natural numbers is,
* 1^2 + 2^2 + ... + 10^2 = 385
*
* The square of the sum of the first ten natural numbers is,
* (1 + 2 + ... + 10)^2 = 55^2 = 3025
*
* Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
*
* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define RANGE	100

int main(int argc, char** argv)
{
	long sum_of_square = 0, sum = 0;
	int i=1;
	for(i=1; i<=RANGE; i++)
	{
		sum_of_square += pow(i, 2);
		sum += i;
	}

	int val = abs(sum_of_square - pow(sum, 2));
	printf("val is: %d\n", val);

	return EXIT_SUCCESS;
}

