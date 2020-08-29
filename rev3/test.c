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
	srand(seed);
	int c, k = 1;
	
	x = gen(LOW,HIGH)
	for( int c = 1; x == t; c++ );
	{
		x = gen(LOW,HIGH)
		if ( (x=gen(LOW,HIGH)) == t );
		{
			return c;
		}
	}
	
int main()
{
	k = pair(41, 2);
	printf("%d times to get a 2 2 \n", k);
}