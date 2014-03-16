/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	01-25-2014 06:44
*
* Filename:		test.c
*
* Description: 
*
* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
*
* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
* 
*
******************************************/
#include <stdlib.h>
#include <stdio.h>

int sln(int range)
{
	int done=0;
	int num=range;
	while(!done)
	{
		int i=0;
		for(i=2; i<range; i++)
			if(num%i) break;
		if(i==range) done=1;
		else num++;
	}
	return num;
}

int main(int argc, char** argv)
{

	printf("%d should be 2520.\n", sln(10));
	printf("result from 1 - 20 is %d\n", sln(20));

	return EXIT_SUCCESS;
}
