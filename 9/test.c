/*******************************************
*
* Author: HzChen - hzchen_cs@gwmail.gwu.edu
*
*
* Last modified:	01-28-2014 23:50
*
* Filename:		test.c
*
* Description: 
*
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
* a2 + b2 = c2
*
* For example, 32 + 42 = 9 + 16 = 25 = 52.
*
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc.
*
*
*
******************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/**
 *	b/c 		a^2 + b^2	= c^2
 *  => a^2	=   c^2 - b^2 	= (c+b)(c-b)
 *  assume a=2mn,
 *  => (2mn)^2			= 2*m^2 * 2*n^2
 *  => (2m)^2 * (2n)^2 	= (m^2 + n^2 + m^2 - n^2) * (m^2 + n^2 - m^2 + n^2)
 *  					= ((m^2 + n^2) + (m^2 - n^2)) * ((m^2 + n^2) - (m^2 - n^2))
 *  b/c: c > b	
 *  so:	=> c = m^2 + n^2, b = m^2 - n^2;
 *	
 *	so:   a + 		b 		+ 		c 		= 1000
 *		2mn +	(m^2 + n^2) + (m^2 - n^2)	= 1000
 *							2mn + 2 * m^2 	= 1000
 *								m ( m + n )	= 500
 *
 * 	b/c: b > 0, m^2 - n^2 > 0 
 * 	so:	=>	m > n
 * 	so:	=> 			500	= m ( m + n ) 	< m ( m + m ) 
 * 									500	< 2 m ^ 2
 * 									250 < m ^ 2
 *							  sqrt(250) < m
 *
 * 	b/c: a > 0, 
 * 	so:	=>	n > 0
 * 	so: =>			500 = m ( m + n )	> m ( m + 0 )
 * 									500	> m^2
 * 							  sqrt(500)	> m
 *
 *  so:	=>  sqrt(250)	<	m	<	sqrt(500)
 *  and:=>	n = 500 / m - m;
 *
 *
 * 	more generally, if	a + b + c = K, we have:
 * 		=> sqrt(K/4)	<	m	<	sqrt(K/2)
 * 	and:=>	n = K / (2*m) - m^2;
 */
int sln()
{
	double K = 1000;
	double tmp_n=0, frac=0;
	int m=0, n=0;
	int start = sqrt(K/4), end = sqrt(K/2);
	for(m=start; m<end; m++)
	{
		tmp_n = K / (2*m) - m;
		//since we're asking for natual number, tmp_n need to be integer
		if(!modf(tmp_n, &frac))
		{
			n = tmp_n;
			printf("m: %d\tn:%d\n", m, n);
			printf("a: %d\tb:%d\tc:%d\n", 2*m*n, m*m - n*n, m*m + n*n);
			//return 1;
		}
	}
	return 0;

}

int main(int argc, char** argv)
{
	sln();
	return EXIT_SUCCESS;
}

