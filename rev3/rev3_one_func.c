#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LOW = 2;
int HIGH = 9;

// this is complete; don't change it
int gen( int low, int high )
{
        int x;
        x = rand() % (high - low +  1) + low;
        return x;
}

// seed the random number generator
// report how many number produced until value t
int one( int seed, int t )
{
	srand(seed);
	int x = gen(LOW,HIGH), c = 1;
	
	while ( x != t ) // count until t found
	{
		x = gen(LOW,HIGH);
		c++;
		printf("x is %d c is %d t is %d\n", x, c, t);
	}
	return c;	// return count
}

int main()
{
    int k,x,t;

	k = one(34, 4);
	printf("%d times to get a 2\n", k);
}