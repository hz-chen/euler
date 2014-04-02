#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../euler.h"

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define SZ	9
int (arr)[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int total=0;

int main(int argc, char** argv)
{
	double limit = 1;
	int i=0;
	for(i=1; i <=9; i++)
		limit *= i;

	while( total <= limit)
	{
		_euler_lexical_perm(&arr, SZ);
		_euler_print_arr(arr, SZ);
		total++;
	}
	

	return EXIT_SUCCESS;
}
