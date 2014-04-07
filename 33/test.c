/*******************************************
 *
 * Author: HzChen - hzchen_cs@gwmail.gwu.edu
 *
 *
 * Last modified:	04-06-2014 19:35
 *
 * Filename:		test.c
 *
 * Description: 
 *
 *
 *
 * The fraction 49/98 is a curious fraction, as an 
 * inexperienced mathematician in attempting to simplify 
 * it may incorrectly believe that 49/98 = 4/8, which 
 * is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be 
 * trivial examples.
 *
 * There are exactly four non-trivial examples of this type 
 * of fraction, less than one in value, and containing two 
 * digits in the numerator and denominator.
 *
 * If the product of these four fractions is given in its 
 * lowest common terms, find the value of the denominator.
 *
 *
 ******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * this fraction can only be either:
 * (10a+t)/(10t+b) == (a/b)
 * or
 * (10t+a)/(10b+t) == (a/b)
 */

int main(int argc, char** argv)
{

	float a, b, t, m, n;
	for( a = 1; a < 10; a ++)
		for( b = 1 ; b < 10 ; b ++)
			for( t = 1 ; t < 10 ; t ++)
			{
				if(a >= b)
					continue;

				m = (10 * a + t);
				n = (10 * t + b);
				if(m<n && ((m/n) == (a/b)))
					printf("%1.f / %1.f = %1.f/%1.f\n", m, n, a, b);

				m = (10 * t + a);
				n = (10 * b + t);
				if(m<n && ((m/n) == (a/b)))
					printf("%1.f / %1.f = %1.f/%1.f\n", m, n, a, b);
			}

	return EXIT_SUCCESS;
}

