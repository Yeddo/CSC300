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
	int c, k, temp, w, a = 0, b = 0;
	
	a = gen(LOW,HIGH);

	while ( k != 1 )
	{
		b = gen(LOW,HIGH);
		c++;

		while ( w != 1 )
		{
			printf("a is %d b is %d and c is %d\n\n", a, b, c);
			if ( a == b )
			{
				k++;
				break;
			}
			if ( a != b )
			{
				a = gen(LOW,HIGH);
				c++;
				temp = a;
			}
			if ( a == temp )
			{
				break;
			}
			else
			{
				w++;
			}
		printf("a is %d b is %d c is %d temp is %d\n\n", a, b, c, temp);
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