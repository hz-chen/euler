#include <stdlib.h>
#include "euler.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define SZ	10

int main(int argc, char** argv)
{
	int i=0;

	/*
	printf("testing _euler_swap\n");
	int a = 2, b = 3;
	_euler_swap(&a, &b);
	assert( a == 3 && b == 2);
	printf("testing _euler_swap done\n");

	printf("testing _euler_find_next_bigger\n");
	int arr[5] = {1, 2, 3, 4, 5};
	int result = _euler_find_next_bigger(&arr, 5, 5);
	printf("next bigger: %d at arr[%d]\n", result, arr[result]);
	printf("testing _euler_find_next_bigger done\n");
	*/

	/*
	printf("testing _euler_sort_acending\n");
	for(i=0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	_euler_sort_acending(&arr, 1, 4);
	for(i=0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("testing _euler_sort_acending done\n");
	*/

	/*
	printf("testing _euler_lexical_perm\n");
	for(i=0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	j=0;
	while((j++)< 121)
	{
		_euler_lexical_perm(&arr, 5);
		for(i=0; i < 5; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	printf("testing _euler_lexical_perm done\n");
	*/

	printf("testing _euler_arr_multi\n");

	int (*(*mul))[SZ] = (int (*(*))[SZ])malloc(sizeof(int*));
	*mul = (int ((*))[SZ])malloc(sizeof(int) * (SZ+1));
	for(i=0; i < SZ; i++)
		(*(*mul))[i] = 0;
	(*(*mul))[0] = 2;
	int const num[5] = {1, 2, 3, 4, 5};

	_euler_arr_multi(mul, &num, SZ, 5, SZ);
	for(i=SZ-1; i >=0; i--)
		printf("%d", (*(*mul))[i]);
	printf("\n");
	free(*mul);
	*mul = NULL;
	free(mul);
	mul = NULL;

	printf("testing _euler_arr_multi done\n");


	return EXIT_SUCCESS;
}

