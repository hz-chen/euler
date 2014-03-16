#include <stdlib.h>
#include <stdio.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

int main(int argc, char** argv)
{

	return EXIT_SUCCESS;
}

