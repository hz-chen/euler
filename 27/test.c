/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	03-27-2014 23:07
*
* Filename:		test.c
*
* Description: 
*
*
*
* Euler discovered the remarkable quadratic formula:
*
* n² + n + 41
*
* It turns out that the formula will produce 40 
* primes for the consecutive values n = 0 to 39. 
* However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 
* is divisible by 41, and certainly when n = 41, 
* 41² + 41 + 41 is clearly divisible by 41.
*
* The incredible formula  n² − 79n + 1601 was discovered, 
* which produces 80 primes for the consecutive values 
* n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
*
* Considering quadratics of the form:
*
*     n² + an + b, where |a| < 1000 and |b| < 1000
*
* where |n| is the modulus/absolute value of n
* e.g. |11| = 11 and |−4| = 4
*
* Find the product of the coefficients, a and b, 
* for the quadratic expression that produces the 
* maximum number of primes for consecutive values 
* of n, starting with n = 0.
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)


int is_prime(int num)
{
	if(num == 2)
		return 1;

	if(!(num%2))
		return 0;

	if(num <= 1)
		return 0;

	int i=0, limit = sqrt(num);
	for(i=3; i <= limit; i++)
		if(!(num%i))
			return 0;

	//printf("prime: %d\n", num);
	return 1;
}

int get_max(int a, int b)
{
	int n=0;
	int cnt=0;
	for(n=0;;n++)
		if(!is_prime( n*n + a*n + b))
			break;
		else
			cnt++;

	return cnt;
}


int main(int argc, char** argv)
{

	int a=0, b=0;
	int tmp = 0;
	int max = 0, max_prod = 0;
	

	for(a = -999; a < 1000; a ++)
		for(b = -999; b < 1000; b ++)
		{
			tmp = get_max(a, b);
			if(tmp > max)
			{
				max = tmp;
				max_prod = a * b;
//				printf("result n^2 + %d * n + %d has %d consecutive primes\n", a, b, max);
			}
		}

	printf("max prod is %d\n", max_prod);

	return EXIT_SUCCESS;
}

