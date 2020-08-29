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

LOW = -15;
HIGH = 30;
	
// this is complete; don't change it
int gen( int low, int high )
{
        int x;
        x = rand() % (high - low +  1) + low;
        return x;
}

// return rightmost digit
int pos(int x)
{
	if ( x >= 10 )
	{
		return (x % 10);
	}
	else if ( x < 10 )
	{
		return x;
	}
}

// return -1
int neg(int x)
{
	if( x < 0 )
	{
		return -1;
	}
}

// return 1
int zer(int x)
{
	if( x == 0 )
	{
		return 1;
	}
}

/*
        For the next 4 functions
        use gen(LOW,HIGH) to produce the numbers
        Assume LOW & HIGH are set outside
*/

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

// seed the random number generator
// report how many number produced until the
//    same value appears twice in a row
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

// Generate numbers until 3 negative values are produced
// If not possible send back 0 times and 0 sum
void until3neg(int seed, int *times, int *sum) 	// *times and * sum are reference parameters. You cannot use a return value with 2 things 
												//	so reference parameters are needed. 
        // Note:: for sum do not add the actual values.
        // call the correct pos, zer, neg function for each
		//    generated value and use the value returned to
        //    accumulate the sum
        //  * for instance if random number is 0, call the zer function
        //       and add that value to the sum
{
	int c, k, x, temp;
	printf("seed is %d LOW is %d HIGH is %d\n", seed, LOW, HIGH);
	srand(seed);

	if(LOW >= 0)
	{
		printf("Not possile\n\n");
		*times = 0;
		*sum = 0;
		return;
	}

	while( k < 3 )
	{
		c++;
		x = gen(LOW,HIGH);
		if ( x < 0 )
		{
			temp = neg(x);
			*sum += temp;
			k++;
			printf("NEG: x is %d temp is %d sum is %d c is %d\n", x, temp, *sum, c);
		}
		else if ( x > 0 )
		{
			temp = pos(x);
			*sum += temp;
			printf("POS: x is %d temp is %d sum is %d c is %d\n", x, temp, *sum, c);
		}
		else if ( x == 0 )
		{
			temp = neg(x);
			*sum += temp;
			printf("ZER: x is %d temp is %d sum is %d c is %d\n", x, temp, *sum, c);
		}
	*times = c;
	}
}
int main()
{
    int k,x,t;

	int LOW = 1;
	int HIGH = 6;
	
	k = one(41, 2);
	printf("%d times to get a 2\n", k);
	
	k = pair(41, 2);
	printf("%d times to get a 2 2 \n", k);
	
	k = dups(41);
	printf("%d times to get same number twice \n", k);
	
	until13neg(26, &k, &t);
	printf("To get 3 negatives: %d vals, sum %\n", k, t);
}