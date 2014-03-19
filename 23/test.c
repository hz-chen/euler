#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define SZ	28124

int ab_arr[SZ] = {[0 ... (SZ-1)] = 0};
int sums[SZ] = {[0 ... (SZ-1)] = 0} ;

/**
 *
 * This algorithm copied from question 22 is terrible.
 * I'll fix it later if possible.
 *
 */
int d(int const num) {
	int end = sqrt(num);
	int sum = 1, i=0;
	for (i = 2; i <= end; i++) {
		if (!(num%i)) {
			sum += num / i;
			sum += i;
		}
	}

	if (end * end == num)
		sum -= end;
	return sum;
}

void init()
{
	int i=0, j=0;
	for(i=12; i<SZ; i++)
		if(d(i) > i)
			ab_arr[i] = 1;

	for(i=0; i<SZ; i++){
		if(!ab_arr[i])	continue;
		for(j=0; j<SZ-i-1; j++){
			if(!ab_arr[j])	continue;
			sums[ i + j ] = 1;
		}
	}
}

long calculate()
{
	int i=0;
	long total=0;
	for( i = 1; i < SZ; i++)
		if(!sums[i])
			total += i;

	return total;
}

int main(int argc, char** argv)
{

	init();
	printf("result is %ld\n", calculate());

	return EXIT_SUCCESS;
}

