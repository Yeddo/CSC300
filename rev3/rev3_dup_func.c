#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LOW = 1;
int HIGH = 10;

// this is complete; don't change it
int gen( int low, int high )
{
        int x;
        x = rand() % (high - low +  1) + low;
        //printf("gen x is %d\n", x);
        return x;
}

// seed the random number generator
// report how many number produced until the
// same value appears twice in a row
int dups( int seed )
{
	printf("seed is %d LOW is %d HIGH is %d\n\n", seed, LOW, HIGH);
	srand(seed);
	int c, k, w, a, b;
	
	while ( k < 1 ) // fill with rand() and send to inner loop for a to be filled and both tested. keep generating b rand() and counting until inner decision is made
	{
		b = gen(LOW,HIGH);
		c++; // total number counter
		printf("OUTER: a is %d b is %d c is %d\n", a, b, c);
		w = 1; // reset w
		if ( a == b )
		{
			break;
		}

		while ( w < 2 ) // fill a with rand() and see if = to b, if not change a and check again, if not break out of inner loop
		{
			a = gen(LOW,HIGH);
			c++; // total number counter
			w++; // inner loop counter
			printf("INNER: a is %d b is %d and c is %d\n\n", a, b, c);
			if ( a == b ) // check if a = b if so increment outer loop counter and break inner loop
			{
				k++; // outer loop counter
				printf("CONDITION(a=b): a is %d b is %d and c is %d\n\n", a, b, c);
				break;
			}
		}
	}
	return c; // return total numbers tried to caller
}

main()
{
	int k;
	k=dups(41);
	printf("%d times to get the same number twice\n\n", k);
}