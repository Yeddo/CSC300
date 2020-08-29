#include <stdio.h>
#include <stdlib.h>

// return biggest number from array. there are n items
int maxA( int arr[], int n )
{
	int k;
	int big = arr[0]; // initialize to 0 as good practice.
	for ( k = 0; k < n; k++ )
	{
		if ( arr[k] > big )
			big = arr[k];
	}
	return big;
}

// return sum of values in array. there are n items.
int sumA( int arr[], int n )
{
	int k;
	int tot = 0;
	for ( k = 0; k < n; k++ )
		tot = tot + arr[k];
	return tot;
}

// item by item sum; z = x + y
// **you don't need to return an array it get changed by reference **
void addA(int z[], int x[], int y[], int n)
{
	int k;
	for ( k = 0; k < n; k++ )
		z[k] = x[k] + y[k];
}

// check for item t in array. return 1 for yes, 0 for no
int searchval( int arr[], int n, int t )
{
	int k, res = 0;
	for ( k = 0; k < n; k++ )
	{
		if ( arr[k] == t )
			res = 1; // don't add an else. bad programming practice.
	}
	return res;
}

// is pair (p,q) in the arrays
int searchpair( int a[], int b[], int n, int p, int q )
{
	int k, res = 0;
	for ( k = 0; k < n; k++ )
	{
		if ( a[k] == p && b[k] == q )
			res = 1; // don't add an else. bad programming practice.
	}
	return res;
}

// play war, largest value in each contest wins
// return value for overall cummulative result
// 0 for tie, 1 for first array, 2 for second array
int war( int x[], int y[], int n )
{
	int k, wx=0, wy=0;
	for ( k = 0; k < n; k++ )
	{
		if ( x[k] > y[k] )
			wx++
		else if ( x[k] < y[k] )
			wy++;
	}
	if ( wx > wy )
		return 1;
	if ( wy > wx )
		return 2;
	if ( wx == wy )
		return 0;
}
		
int main( int argc, char *argv[] )
{
	FILE *fp;
	int xnum[100],ynum[100], tots[100];
	int max, sum, N, k,a,b;
	
	if ( argc < 2 )
	{
		printf("Must supply file name\n");
		exit ( 1 );
	}
	
	fp = fopen( argv[1], "r");
	if ( fp == NULL )
	{
		printf("Unable to open file %s\n", argv[1]);
		exit ( 1 );
	}
	
	fscanf(fp,"%d", &N);
	for ( k = 0; k < N; k++ )
	{
		fscanf(fp, "%d %d, &a, &b);
		xnum[k] = a;
		ynum[k] = b;
	}
	
	for ( k = 0; k < N; k++ )
		printf("%d: %d %d\n", k, xnum[k],ynum[k]);
	max = maxA(xnum,N);
	printf("xmax: %dn", max);
	
	sum = sumA(xnum,N);
	printf("xnum: %d\n", sum);
