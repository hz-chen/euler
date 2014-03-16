/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	01-27-2014 00:40
*
* Filename:		test.c
*
* Description: 
*
*
*
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
*
* What is the 10 001st prime number?
*
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>

int is_prime(int num)
{
	if(num <= 3)
		return 1;
	if(!(num%2))
		return 0;

	int i=1;
	for(i=4; i < num; i++)
	{
		if(!(num%i))
			return 0;
	}

	return 1;
}

int main(int argc, char** argv)
{
	long int i = 3;
	int cnt = 1;	//we already have 2 counted
	while(cnt <= 10001)
	{
		if(is_prime(i))
			cnt++;
		i+=2;
	}
	cnt--;
	i-=2;
	printf("%d st prime is %ld\n", cnt, i);

	return EXIT_SUCCESS;
}

