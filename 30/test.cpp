#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define LIMIT	354294

using namespace std;

int meet_requirement(int const num)
{
	int tmp = num, sum = 0;
	while(tmp){
		sum += pow((tmp%10), 5);
		tmp /= 10;
	}

	return (num == sum) ? 1 : 0;

}

int main(int argc, char** argv)
{
	int sum = 0, i = 0;
	for(i = 2; i <= LIMIT; i++)
		if(meet_requirement(i))
		{
			//printf("%d meets requirement\n", i);
			sum += i;
		}

	cout << sum << endl;

	return EXIT_SUCCESS;
}

