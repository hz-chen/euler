#include <stdio.h>
#include <stdlib.h>

#define RANGE	100000

int fact(int num)
{
	int tmp = num, prod = 1;
	while(tmp)
		prod*= tmp--;

	return prod;
}

int check_curious(int num)
{
	int tmp = num, sum = 0;
	while(tmp)
	{
		int bit = tmp % 10;
		sum += fact(bit);
		tmp /= 10;
	}
	if(sum == num)
		return 1;
	return 0;
}

int main(int argc, char** argv)
{
	int i = 3; 
	
	int sum = 0;

	while(i<RANGE)
	{
		if(check_curious(i))
		{
			sum+=i;
			printf("curious number: %d\n", i);
		}
		i++;
	}

	printf("%d\n", sum);

	return EXIT_SUCCESS;
}

