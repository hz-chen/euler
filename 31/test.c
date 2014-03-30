/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	03-29-2014 22:30
*
* Filename:		test.c
*
* Description: 
*
*
*
* In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
*
*     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
*
*     It is possible to make £2 in the following way:
*
*         1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
*
*    How many different ways can £2 be made using any number of coins?
*
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>

#define unlikely(x)     __builtin_expect(!!(x), 0)
#define likely(x)     	__builtin_expect(!!(x), 1)

int value[8] = {200, 100, 50, 20, 10, 5, 2, 1};


/**
 *	The problem can be turns into the following problem:
 *	Assume we're holding 200 galons of water, and we have 8 tables
 *	in front of us, and there are unlimit number of bows on the table.
 *	Each bow on the first table has 200 galons capacity, bows on the
 *	second table has 100 galons capacity, etc, and we need to either 
 *	fill a bow or left it empty.
 *	The task for us is to pour out our water into those bows, find out
 *	how many different ways we can fill them.
 *
 * 	The reason we reverse the capacity is to make sure when we go to the
 * 	last table, we can always finish all the water.
 *
 *	Now comes the logic. Initially, I'm standing in front of the first 
 *	table. I can choose either to pour my water onto the bows on the table
 *	or not. But if my water is not enough to fill the bow in front of me,
 *	then this way will fail. The recursion is:
 *
 *	at some point, I have some amount of water, and standing in a pos.
 *	If I don't have water ( !amount) or I'm in the last position (pos == 7),
 *	I'll return 1. Because all my water is poured out completely or can
 *	be pour out completely.
 *
 *	Then, if my water is enough to fill current bow, I fill it, call the next
 *	recursion: count ( amount - values[pos], pos). At this point, I'm still
 *	stand in same pos.
 *	Another way is to not pour, but directly go to next table, means to
 *	call count( amount, pos+1).
 *
 */
int count(int amount, int pos)
{
	int num = 0;
	if(!amount || pos == 7)	return 1;
	num += ( amount >= value[pos] ) ? count( amount - value[pos], pos) : 0;
	num += count( amount, pos+1);
	return num;
}

int main(int argc, char** argv)
{

	printf("%d\n", count(200, 0));

	return EXIT_SUCCESS;
}

