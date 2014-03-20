#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

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


int main(int argc, char** argv)
{
	int range = 10000;
	int sum = 0, tmp=0;
	int i=2;
	for (i = 2; i < range; i++) {
		tmp = d(i);
		if (unlikely(tmp == i))
			continue;
		if (unlikely(i == d(tmp)))
		{
			sum += i;
		}
	}
	printf("the sum is %d\n", sum);

	return EXIT_SUCCESS;
}

