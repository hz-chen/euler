/*******************************************
 *
 * Author: HzChen - hzchen_cs@gwmail.gwu.edu
 *
 *
 * Last modified:	04-11-2014 17:52
 *
 * Filename:		test.c
 *
 * Description: 
 *
 * The decimal number, 585 = 1001001001 (binary), 
 * is palindromic in both bases.
 *
 * Find the sum of all numbers, less than one 
 * million, which are palindromic in base 10 and base 2.
 *
 * (Please note that the palindromic number, in 
 * either base, may not include leading zeros.)
 *
 *
 ******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT	1000000

int
is_palindromic(int num, int base)
{
	if(num < 0)
		return 0;

	int rev = 0, 
		 tmp = num;
	while(tmp > 0)
	{
		rev = rev * base + ( tmp % base );
		tmp /= base;
	}
	//printf("rev %d to %d\n",num, rev);
	if(rev == num)
		return 1;
	return 0;
}

int main(int argc, char** argv)
{
	int i=0, sum = 0;
	while(i++ < LIMIT)
		if(is_palindromic(i, 2) && is_palindromic(i, 10))
			sum += i;

	printf("sum is %d\n", sum);


	return EXIT_SUCCESS;
}

