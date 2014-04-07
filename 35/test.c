#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define RANGE	1000000
#define LEN(A)	((int)(ceil(log((A))/log(10))))

int is_prime(int num)
{
	if(unlikely(num < 2))
		return 0;
	if(unlikely(num == 2 || num == 3))
		return 1;
	if(unlikely(!(num%2)))
		return 0;

	int range = sqrt(num) + 1;
	int i=0;
	for(i=3; i <= range; i++)
		if(!(num%i))
			return 0;
	return 1;
}

int contains_bad_num(int num)
{
	//if i has any number more than 1, 3, 7, 9, returns 1
	int tmp = num;
	while(tmp)
	{
		int bit = tmp % 10;
		if(!(bit == 1 || bit == 3 || bit == 7 || bit == 9))
			return 1;
		tmp /= 10;
	}
	return 0;
}

int main(int argc, char** argv)
{


	int bit_len = LEN(RANGE);
	int (*big_arr)[RANGE] = (int (*)[RANGE])malloc(sizeof(int)*RANGE);
	int (*tmp_arr)[bit_len] = (int (*)[bit_len])malloc(sizeof(int) * bit_len);

	int i=0, bit = 0, tmp = 0, tmp_cnter = 0;
	int sum = 0;
	for(i=2; i < RANGE; i++)
	{ 
		if( i > 10 && contains_bad_num(i))
			continue;
		memset(tmp_arr, 0, bit_len);
		tmp_cnter = 0;
		tmp = i;
		int prime = 1;
		while(tmp_cnter < bit_len)
		{
			if(!is_prime(tmp))
			{
				prime = 0;
				break;
			}
			(*tmp_arr)[tmp_cnter++] = tmp;
			bit = tmp % 10;
			tmp /= 10;
			tmp += pow(10, LEN(i)-1) * bit;
		}
		if(prime)	//means is a circular prime
			while(tmp_cnter)
				(*big_arr)[ (*tmp_arr)[--tmp_cnter] ] = 1;
		tmp_cnter = 0;
	}

	for( i = 0; i < RANGE; i ++)
	{
		if((*big_arr)[i])
		{
			sum += (*big_arr)[i];
		//	printf("circular prime: %d\n", i);
		}
	}

	printf("sum is: %d\n", sum);


	free(tmp_arr);
	free(big_arr);
	return EXIT_SUCCESS;
}

