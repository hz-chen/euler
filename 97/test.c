#include <stdio.h>
#include <stdlib.h>
#include "../euler.h"

#define LEN	11

int main(int argc, char** argv)
{
	int (*digits)[LEN] = (int (*)[LEN])malloc(sizeof(int) * (LEN));
	int const base[1] = {2};
	int const num[5] = {3, 3, 4, 8, 2};

	int i=0, j=0;
	for( i = 0 ; i < LEN; i++)
		(*digits)[i] = 0;
	(*digits)[LEN-1] = 2;
	for( i = 0; i < LEN; i++)
		printf("%d", (*digits)[i]);
	printf("\n");

	for( i = 0; i < 7830456; i++)
	{
		_euler_arr_multi(&digits, &base, LEN, 1, LEN);
		for( j = 0; j < LEN; j++)
			printf("%d", (*digits)[j]);
		printf("\n");
	}
	
	_euler_arr_multi(&digits, &num, LEN, 5, LEN);
	for( i = 0; i < LEN; i++)
		printf("%d", (*digits)[i]);
	printf("\n");
	free(digits);


	return EXIT_SUCCESS;
}

