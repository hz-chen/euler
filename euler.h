#ifndef EULER_H
#define EULER_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

/**
 *   return 1 if num is prime, 0 otherwise.
 */
int _euler_is_prime(int num)
{
	if(unlikely(num < 2))
		return 0;
	if(unlikely(num == 2 || num == 3))
		return 1;
	if(!(num%2))
		return 0;
	if(!(num%3))
		return 0;
	if((num+1)%6 && (num-1)%6)
		return 0;

	int range = sqrt(num);
	int i=0;
	for(i=3; i <= range; i+=2)
		if(!(num%i))
			return 0;
	return 1;
}

/**
 *	swap two integers
 */
void _euler_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/**
 *	return the index of a number, that is after pos
 *	and before end (not including arr[end], and is 
 *	the smallest one bigger than (*arr)[pos].
 *	returns -1 if current number is the biggest one.
 */
static int
_euler_find_next_bigger( int (*arr)[], int const pos, int const end)
{
	int curr = (*arr)[pos], i = pos;
	int smallest_bigger = -1, smallest_bigger_pos = -1;
	while( (++i) < end )
	{
		if(((*arr)[i] > curr) &&	//find a bigger one and 
				(smallest_bigger_pos == -1 ||		//nothing has been found yet 
				 (*arr)[i] < smallest_bigger)){		//this one is smaller
			smallest_bigger_pos = i;
			smallest_bigger = (*arr)[i];
		}
	}
	return smallest_bigger_pos;
}

/**
 *	sort arr from arr[start] to arr[end]
 */
void _euler_sort_acending( int (*arr)[], int const start, int const end)
{
	if(start >= end)	return;
	if((start == end-1) && ((*arr)[start] > (*arr)[end]))
		_euler_swap(&((*arr)[start]), &((*arr)[end]));
	else{
		int i = start, j = start + 1;
		for( i = start; i <= end-1; i++)
			for( j = i + 1; j <= end; j ++)
			{
				if((*arr)[i] > (*arr)[j])
					_euler_swap(&((*arr)[i]), &((*arr)[j]));

			}
	}

	return;
}

/**
 *	sort arr from arr[start] to arr[end]
 */
void _euler_sort_decending( int (*arr)[], int const start, int const end)
{
	if(start >= end)	return;
	if((start == end-1) && ((*arr)[start] < (*arr)[end]))
		_euler_swap(&((*arr)[start]), &((*arr)[end]));
	else{
		int i = start, j = start + 1;
		for( i = start; i <= end-1; i++)
			for( j = i + 1; j <= end; j ++)
			{
				if((*arr)[i] < (*arr)[j])
					_euler_swap(&((*arr)[i]), &((*arr)[j]));

			}
	}

	return;
}


/**
 *	this function takes an array and it's arr length as input,
 *	change to input array into the next lexical permutation.
 *	All elements in the array must be different.
 *	The function will returns 1 if a perm has been successfully 
 *	performed, 0 if the input is already the last permutation and
 *	nothing has been changed to the original array.
 *
 */
int
_euler_lexical_perm( int (*arr)[], int const arr_sz)
{
	int i = arr_sz - 1, target = -1;
	while( (*arr)[i] < (*arr)[i-1]) i--;
	if( i == 0) return 0;
	i--;
	target = _euler_find_next_bigger(arr, i, arr_sz);
	_euler_swap(&((*arr)[i]), &((*arr)[target]));
	_euler_sort_acending(arr, i+1, arr_sz-1);
	return 1;
}

void _euler_print_arr(int const arr[], int const arr_sz)
{
	int i=0;
	for(i=0; i < arr_sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/**
 * arr *= num in first arr_len bit, numbers are stored reversed.
 * like: 98765 in arr is: 
 * arr		:	9	8	7	6	5	
 * index	:	0	1	2	3	4
 * where arr_len = 5.
 * arr_len is the valid arr length, 
 * num_len is the length of number,
 * max_len is the maximum length of valid number can be stored in arr.
 */
void _euler_arr_multi( int (*(*mul))[], int const (*num)[], int arr_len, int num_len, int max_len)
{
	int i=0, j=0; 
	int carry_over = 0, tmp_prod = 0;
	int (*tmp)[num_len][arr_len+1] = (int (*)[num_len][arr_len+1])malloc(sizeof(int) * (num_len * (arr_len+1)));
	
	for( i=0; i < num_len; i++)
	{
		tmp_prod = 0;
		carry_over = 0;
		for( j=0; j < arr_len ; j++)
		{
			tmp_prod = (*(*mul))[j] * (*num)[i] + carry_over;
			(*tmp)[i][j] = tmp_prod % 10;
			carry_over = tmp_prod / 10;
			//assert(carry_over < 10);
		}
		(*tmp)[i][j] = carry_over;
		
	}
	
	/*
	for( i=0; i < num_len; i++)
	{
		for( j =arr_len-1 ; j >= 0; j --)
			printf("%d ", (*tmp)[i][j]);
		printf("\n");
	}
	*/


	int new_len = (arr_len + num_len > max_len && max_len != 0 ? max_len + 1: arr_len + num_len + 1);
	int (*res)[new_len] = (int (*)[new_len])malloc((new_len ) * sizeof(int));

	for( i=0; i < new_len; i++)
		(*res)[i] = 0;

	carry_over = 0;

	for(i=0; i < num_len; i++)
	{
		carry_over = 0;

		for (j = 0; j < arr_len && (i + j < new_len); j++) {
			int tmp_sum= (*res)[i + j] + (*tmp)[i][j] + carry_over;
			(*res)[i + j] = tmp_sum % 10;
			carry_over = tmp_sum / 10;
		}
		if (carry_over != 0) {
			(*res)[i + j] = carry_over;
			carry_over = 0;
		}
	}
	free(*mul);
	*mul = NULL;
	*mul = res;
	free(tmp);
}

#endif
