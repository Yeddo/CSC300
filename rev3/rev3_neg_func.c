#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LOW = -15;
int HIGH = 84;

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
	int k, t;

	until3neg(26, &k, &t);
	printf("To get 3 negatives: %d vals, sum %d\n", k, t);
}