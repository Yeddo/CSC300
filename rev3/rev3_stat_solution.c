/*
Complete all the functions:
⦁	Pay careful attention to how random numbers are begin generated. We are using the gen() function as written. No changes.
⦁	We are seeding the random generator inside many functions to get deterministic output – make sure you do that. 
⦁	The sample main below should provide some guidance to you
⦁	Function details are provided in comments in the starting code
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LOW = 2;
int HIGH = 9;
int SEED = 34;
int TT = 4;

// this is complete; don't change it
int gen( int low, int high)
{
	int x;
	x = rand() % (high - low + 1) + low
	return x;
}

// return rightmost digit
int pos(int x)
{
	return x % 10;
}

// return -1
int neg(int x)
{
	return -1;
}

// return 1
int zer(int x)
{
	return 1;
}

/*
for the next 4 functionsuse gen(LOW,HIGH) to produce the numbers
assume LOW & HIGH are set outside
*/

// seed the random number generator
// report how many number poruced until value t
int one( int seed, int t)
{
	int x, n = 0;
	srand(seed);
	do
	{
		x = gen(LOW,HIGH);
		n++;
		printf("%d: %d\n", n, x);
	} while (x != t);
	return n;
}

// seed the random number generator
// report how many number produced until value t appears twice in a row
int pair( int seed, int t )
{
	int x,y, n = 1;
	srand(seed);
	x = gen(LOW,HIGH);
	do
	{
		y = x;
		x = gen(LOW,HIGH);
		n++;
	} while (x != t || y != t);
	return n;
}

// seed the random number generator
// report how many number produced until the
// same value appears twice in a row
int dups( int seed )
{
	int x,y, n = 1;
	srand(seed);
	x = gen(LOW,HIGH);
	do
	{
		y = x;
		x = gen(LOW,HIGH);
		n++;
	} while (x != y);
	return n;
}

// Generate numbers until 3 negative values are produced
// If not possible send back 0 times and 0 sum
void until3neg(int seed, int *times, int *sum)
{
	srand(seed);
	if ( LOW >= 0 )
	{
		*times = 0;
		*sum = 0;
		return;
	}
	int k, x, t, r, n;
	k = 0;
	t = 0;
	n = 0;
	do
	{
		x = gen(LOW,HIGH);
		k++;
		if ( x > 0 ) r = pos(x);
		if ( x == 0 ) r = zer(x);
		if ( x < 0 ) r = neg(x);
		t += r;
		if ( x < 0 )
			n++;
	} while ( n < 3 );
	*sum = t;
	*times = k;
}

int main()
{
	int k, x, n, r;
	int t, s;
	k = one(SEED, TT);
	printf("	%d times to get a %d\n", k,TT);
	k = pair(SEED, TT);
	printf("	%d times to get a %d %d\n", k, TT,TT));
	k = dups(SEED);
	printf("	%d times to get same number twice \n", k);
	
	until3neg(SEED, &k, &t);
	printf("	To get 3 negatives: %d vals, sum %d\n", k, t);
}




















