#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../euler.h"

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define SZ	9
int (arr)[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int total=0;

int check_pan(int (*arr)[SZ], int first, int second, int* prod)
{
	int a=0, b=0;
	int tmp = 0;
	switch(first){
		case 1:
			assert(second == 4);
			a = (*arr)[0];
			b = (*arr)[1] * 1000 +
				(*arr)[2] * 100 +
				(*arr)[3] * 10 +
				(*arr)[4];
			break;
		case 2:
			assert(second = 3);
			a = (*arr)[0] * 10 +
				(*arr)[1];
			b = (*arr)[2] * 100 +
				(*arr)[3] * 10 +
				(*arr)[4];
			break;
		default:
			return 0;

	}
	tmp = 	(*arr)[5] * 1000 +
		(*arr)[6] * 100 +
		(*arr)[7] * 10 +
		(*arr)[8];

	if( tmp == a * b)
	{
		*prod = tmp;
		return 1;
	}
	else
		return 0;
}

int main(int argc, char** argv)
{
	double limit = 1;
	int i=0;
	for(i=1; i <=9; i++)
		limit *= i;
	int counter= 0;

	int cnt[10000] = { [ 0 ... 9999] = 0};

	while( total <= limit)
	{
		_euler_lexical_perm(&arr, SZ);
		int product = 0;
		if(check_pan(&arr, 1, 4, &product))
			cnt[product]++;
		if(check_pan(&arr, 2, 3, &product))
			cnt[product]++;
		total++;
	}
	for(i = 1000; i < 10000; i ++)
	{
		if(cnt[i])
			counter += i;
	}
	printf("sum of diff pandigits products: %d\n", counter);
	

	return EXIT_SUCCESS;
}

