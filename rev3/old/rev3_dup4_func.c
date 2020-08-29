#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LOW = 1;
int HIGH = 6;

// this is complete; don't change it
int gen( int low, int high )
{
        int x;
        x = rand() % (high - low +  1) + low;
        return x;
}

// seed the random number generator
// report how many number produced until the
// same value appears twice in a row
int dups( int seed )
{
	printf("seed is %d\n\n", seed);
	srand(seed);
	int c, k, a = 0, b = 0;

	while ( k != 1 )
	{
		a = gen(LOW,HIGH);
		b = gen(LOW,HIGH);
		c++;
		printf("a is %d b is %d and c is %d\n\n", a, b, c);

		if ( a == b )
		{
			c++;
			k++;
			printf("a is %d b is %d and c is %d\n\n", a, b, c);

		}
	}
	return c;
}

main()
{
	int k;
	k=dups(41);
	printf("%d times to get the same number twice\n\n", k);
}