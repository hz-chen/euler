/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	01-27-2014 00:16
*
* Filename:		test.c
*
* Description: 
*
* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
*
* Find the largest palindrome made from the product of two 3-digit numbers.
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_palidromic(int num)
{
	char str[7];
	sprintf(str, "%d", num);
	int len = strlen(str);

	int dest = len;
	int ret_val = 1;
	int pos = 0;
	while(dest > 1)
	{
		if(str[pos] != str[pos+dest-1])
		{
			ret_val = 0;
		}
		pos++;
		dest-=2;
	};
	return ret_val;
}

int main(int argc, char** argv)
{

	int largest = 0;
	int i=0, j=0;
	int li=0, lj=0;
	for(i=100; i<1000; i++)
		for(j=100; j<1000; j++)
		{
			int prod = i * j;
			if(is_palidromic(prod) && prod>largest)
			{
					largest = prod;
					li = i;
					lj = j;
			}
		}

	printf("largest result is %d x %d = %d\n", li, lj, largest);

	return EXIT_SUCCESS;

}

