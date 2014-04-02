#include <stdio.h>
#include <stdlib.h>
#include "../euler.h"

#define LEN	101

//my stupid brute force algorithm, takes 2 seconds for last 10 digits.
//However, it can calculate unlimited bits, eg., it takes 15 secs to  
//calculate the last 100 bits.
void sln1(){

	int (*digits)[LEN] = (int (*)[LEN])malloc(sizeof(int) * (LEN));
	int const base[1] = {2};
	int const num[5] = {3, 3, 4, 8, 2};

	int i=0;
	for( i = LEN-1 ; i >=0 ; i--)
		(*digits)[i] = 0;
	(*digits)[0] = 2;
	printf("2^1: ");
	for( i = LEN-1; i >= 0; i--)
		printf("%d", (*digits)[i]);
	printf("\n");

	for( i = 0; i < 7830456; i++)
		_euler_arr_multi(&digits, &base, LEN, 1, 0);

	printf("last %d digits of 2^7830457: ", LEN);
	for( i = LEN-1; i >= 0; i--)
		printf("%d", (*digits)[i]);
	printf("\n");
	_euler_arr_multi(&digits, &num, LEN, 5, 0);

	printf("last %d digits of 28433 * 2 ^ 7830457: ", LEN);
	for( i = LEN-1; i >= 0; i--)
		printf("%d", (*digits)[i]);
	printf("\n");
	free(digits);


}

void sln2()
{
	long res = 1;
	int i=0;
	for(i=0; i < 7830457; i++)
	{
		res <<= 1;
		res %= 10000000000;
	}
	res *= 28433;
	res %= 10000000000;
	res += 1;
	printf("%ld\n", res);

}

int main(int argc, char** argv)
{
	sln1();
//	sln2();
	return EXIT_SUCCESS;
}

