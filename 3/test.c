/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	01-24-2014 00:59
*
* Filename:		test.c
*
* Description: 
* The prime factors of 13195 are 5, 7, 13 and 29.
*
* What is the largest prime factor of the number 600851475143 ?
*
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>

#define NUM		600851475143


int sln(unsigned long int num)
{
	int tmp = 2;

	while(tmp < num)
	{
		if(!(num%tmp))
			num /= tmp;
		else
			tmp++;
	}
	return tmp;
}
int main(int argc, char** argv)
{
	printf("price factor of %ld: %d\n", NUM, sln(NUM));

	return EXIT_SUCCESS;
}

