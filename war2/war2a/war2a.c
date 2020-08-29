/* Program war2a: multi-dimension arrays

Program war2a:
 - 2d array

All the rules apply, except for these enhancements:
 - 2d array stores the 2 columns of numbers
    - adjust declarations & parameters to accept
 - function changes: maxA, sumA, searchval
    - add another parameter ( last )
          1 or 2 to denote which column is to be used
    - you do not need to validate the parameter value
 - function changes: searchpair, adda, war
    - 2d array replaces parameters for individual lists
          but you knew that

*/

// --------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// return biggest number from array. there are n items
int maxA( int arr[][2], int last, int n )
{
	// last--; can use this instead of below ... subtract 1.
	if ( last == 1 ) last = 0;
	else ( last = 1 );

	int max = arr[0][last];

	// loop through array and compare every element with max
	for ( int i = 0; i < n; i++) 
	{
		if ( arr[i][last] > max )
		{
			max = arr[i][last];
		}
	}
	return max;
}

// return sum of values in array. there are n items
int sumA( int arr[][2], int last, int n )
{	
	// last--; can use this instead of below ... subtract 1.
	if ( last == 1 ) last = 0;
	else ( last = 1 );

	int sum = 0;	
	
	for ( int i = 0; i < n; i++ )
	{
		sum = sum + arr[i][last];
	}
	return sum;
 }

// item by item sum;  z = x + y
void addA( int z[], int x[][2], int n )
{
	for ( int i = 0; i < n; i++ ) 
	{
		z[i] = x[i][0] + x[i][1];
	}
}

// check for item t in array. return 1 for yes, 0 for no
int searchval( int arr[][2], int last, int n, int t )
{
	// last--; can use this instead of below ... subtract 1.
	if ( last == 1 ) last = 0;
	else ( last = 1 );

	int ret = 0;

    for( int i = 0; i < n; i++ ) 
    {
        if( arr[i][last] == t ) 
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

// is pair (p,q) in the arrays
int searchpair( int a[][2], int n, int p, int q )
{
	int ret = 0;

	for( int i = 0; i < n; i++ ) 
	{
		if ( a[i][0] == p && a[i][1] == q )
		{
			ret = 1;
			break;
		}
	}
	return ret;
}

// play war, largest value in each contest wind
// return value for overall cummulative result
// 0 for tie, 1 for first array, 2 for second array
int war( int x[][2], int n )
{
	int i = 0; // loop counter var
	int xPoint = 0; // var for x points
	int yPoint = 0; // var for y points
	int ret = 0; // return value
	
	for ( i = 0 ; i < n; i++)  
	{ 
		if ( x[i][0] > x[i][1] ) // if x wins increment x
		{ 
			xPoint++; 
		} 
		else // if x doesn't win increment y
		{
			yPoint++; 
		}
	}	

	if ( xPoint > yPoint)  // if x wins
	{ 
		ret = 1;
	} 
	else if ( xPoint == yPoint ) // if tie
	{ 
		ret = 0;
	} 
	else // if x doesn't win and it isn't a tie, y wins
	{ 
		ret = 2;	
	}
	return ret;
}

// the main program
int main(int argc, char *argv[]) 
{

    // declare 3 2d arrays to store first number, second number, and total
    int x[100][2] = {0}; // initialize array and pad w/0s
    int tot[100] = {0}; // used for addA and ___ functions
   	int last = 1; // which column to perform action on (1 is 0 and 2 is 1 in the x array)

    // get the filename as a command line argument
    if ( argc < 2 )
	{
		printf("\nMust supply a file name as an argument\n\n");
		exit(1);
	}
		
    // open & read the file into the 2 arrays
	int i = 0; // counter
	int n = 0; // var for number of items in the array retrieved from file below.
	
	FILE *filename = fopen(argv[1], "r"); // declare file pointer and opens the file that's passed as arg. 
	if (filename == NULL)  // make sure there is a filename passed.
	{
		printf("\nPlease enter a valid file name as an argument: i.e., ./war1 xy.dat\n\n");
		exit(1); // error if no file.
	}
	fscanf(filename, "%d", &n); // grab first line in file and store as n.
	
	while( EOF != fscanf( filename, "%d %d\n", &x[i][0], &x[i][1] )) // loop through until EOF and store the numbers into the arrays.
	{
		i++;
	}

// use function to solve the following

    //max of array & print
    printf("\nLargest number in column 1 of x array is %d\n", maxA(x, last, n));
    
    //sum of first array & print
	printf("Sum of numbers in column 1 of x array is %d\n\n", sumA(x, last, n));   

	// search for value "t"
	printf("Is value 45 there? %d\n\n", searchval(x, last, n, 45));
        
    // populate 3rd array as sum of first two
    addA( tot, x, n );
                
    // print out the totals as series of lines    x + y = tot
    for ( int i = 0; i < n; i++ ) 
    {
    	printf( "%d + %d = %d\n", x[i][0], x[i][1], tot[i] );
    }
	
	// search pair
	printf("A match? %d", searchpair( x, n, 45, 6 ));

    // play war; print out tie, or P1 wins, or P2 wins
    int res = war( x, n ); 
  
    if ( res == 1 ) 
    {
    	printf("\nP1 Wins\n\n");
    } else if ( res == 2 ) 
    {
    	printf("\nP2 Wins\n\n");
    } else 
    {
    	printf("\nTie\n\n");
    }

fclose(filename); // close file

}
