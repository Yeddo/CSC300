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
// report how many number produced until value t
//    appears twice in a row
int pair( int seed, int t )
{
	printf("seed is %d LOW is %d HIGH is %d\n\n", seed, LOW, HIGH);
	srand(seed);
	int c, k, a = 0, b = 0;

	while ( k != 1 )
	{
		c++;
		if ( (a = gen(LOW,HIGH)) == t )
		{
			c++;
			printf("#2 t is %d and a is %d b is %d and c is %d\n", t, a, b, c);
			if ( (b = gen(LOW,HIGH)) == t )
			{
				printf("#3 t is %d a is %d b is %d and c is %d\n\n", t, a, b, c);
				k++;
			}
		}
		printf("#1 t is %d and a is %d b is %d and c is %d\n", t, a, b, c);
	}
	return c;
}

int main()
{
	int k = pair(41, 2);
	printf("%d times to get a 2 2 \n", k);
}