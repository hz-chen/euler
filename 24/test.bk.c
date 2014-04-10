/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	03-19-2014 16:51
*
* Filename:		test.c
*
* Description: 
*
*
* A permutation is an ordered arrangement of objects. 
* For example, 3124 is one possible permutation of the 
* digits 1, 2, 3 and 4. If all of the permutations are 
* listed numerically or alphabetically, we call it 
* lexicographic order. The lexicographic permutations 
* of 0, 1 and 2 are:
*
* 012   021   102   120   201   210
*
* What is the millionth lexicographic permutation of the 
* digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*
*
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

#define LIMIT	1000000
#define END		9

int arr[END+1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int total=0;

//find the next number in the range from index to END,
//which is the smallest one that bigger than arr[index]
int find_next_bigger(int index)
{
	assert(index != END);
	int smallest = END, smallest_i = 0;
	int i=0;
	for(i=index; i <= END; i++)
	{
		if(arr[i] > arr[index] && arr[i] <= smallest)
		{
			smallest = arr[i];
			smallest_i = i;
		}
	}

	assert(smallest_i);
	return smallest_i;
}

void swap(int i, int j)
{
	arr[i] ^= arr[j];
	arr[j] ^= arr[i];
	arr[i] ^= arr[j];
}

//sort array from index to END
void sort(int index)
{
	assert(index >= 0);
				int i=0, j=0;
	switch(index){
		case 9:	return;
		case 8:	if(arr[8] > arr[9])
				 swap(8, 9);
				return;
		default:
				for(i=index; i<END; i++)
					for(j=i+1; j<=END; j++)
						if(arr[i] > arr[j])
							swap(i, j);
	}
	return;
}



void print()
{
	int i=0;
	for(i=0; i <= END; i++)
		printf("%d", arr[i]);
	printf("\n");
}


/**
 * key function of permutation, I spent an hour
 * to work it out. really can't explain too much,
 * basically follows how we manually calcualte
 * the permutation.
 */
void perm()
{
	int i = END;
	while( i >= 0 && arr[i] < arr[--i]);

	if( i < 0 ){
		printf("perm finished\n");
		exit(0);
	}
	
	int target = find_next_bigger(i);
	swap(i, target);
	sort(i+1);
	total++;
}

int main(int argc, char** argv)
{

	while(total <= LIMIT)
		perm();

	print();

	return EXIT_SUCCESS;
}

