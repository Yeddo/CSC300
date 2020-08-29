/* Program war2b: structures

Program war2b:
 - structures

All the rules apply, except for these enhancements:
 - array of structures stores the 2 columns of numbers
    - adjust declarations & parameters to accept
 - function changes: maxA, sumA, searchval
    - add another parameter ( last )
          1 or 2 to denote which column is to be used
    - you do not need to validate the parameter value
 - function changes: searchpair, adda, war
    - array of structures  replaces parameters for individual lists
          but you knew that

*/

// --------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// struct is a data point not storage
struct point // defines data type
{
	int x;
	int y;
}; // dont' forget semi-colon

// return biggest number from struct array. there are n items
int maxA( struct point arr[], int last, int n )
{
	int max = 0;
	int i = 0;
	
	if (last == 1 ) 
	{
		max = arr[0].x;
		for ( i = 0; i < n; i++ )
		{
			if ( arr[i].x > max )
			{
				max = arr[i].x;
			}
		}
	}
	if ( last == 2 )
	{
		max = arr[0].y;
		for ( i = 0; i < n; i++ )
		{
			if ( arr[i].y > max )
			{
				max = arr[i].y;
			}
		}
	}
	return max;
}

// return sum of values in struct array. there are n items
int sumA( struct point arr[], int last, int n )
{	
	int i = 0;
	int sum = 0;

	if ( last == 1 )
	{
		for ( int i = 0; i < n; i++ )
		{
		sum = sum + arr[i].x;
		}
	}
	if ( last == 2 )
	{
		for ( int i = 0; i < n; i++ )
		{
		sum = sum + arr[i].y;
		}
	}
	return sum;
 }

// item by item sum;  z = x + y
void addA( int z[], struct point x[], int n )
{
	for ( int i = 0; i < n; i++ ) 
	{
		z[i] = x[i].x + x[i].y;
	}
}

// check for item t in array. return 1 for yes, 0 for no
int searchval( struct point arr[], int last, int n, int t )
{
	int i = 0;
	int ret = 0;

	if ( last == 1 )
	{
		for( i = 0; i < n; i++ )
		{
			if( arr[i].x == t )
			{
				ret = 1;
				break; 
			}
		}
    }
    else if ( last == 2 )
    {
		for( i = 0; i < n; i++ )
		{
			if ( arr[i].y == t )
			{
				ret = 1;
				break;
			}
		}
    }
 	return ret;
 }


// is pair (p,q) in the arrays
int searchpair( struct point a[], int n, int p, int q )
{
	int ret = 0;

	for( int i = 0; i < n; i++ ) 
	{
		if ( a[i].x == p && a[i].y == q )
		{
			ret = 1;
		}
	}
	return ret;
}

//// play war, largest value in each contest wind
//// return value for overall cummulative result
//// 0 for tie, 1 for first array, 2 for second array
int war( struct point x[], int n )
{
	int i = 0; // loop counter var
	int xPoint = 0; // var for x points
	int yPoint = 0; // var for y points
	int ret = 0; // return value
	
	for ( i = 0 ; i < n; i++)  
	{ 
		if ( x[i].x > x[i].y ) // if x wins increment x
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

    // declare 3 arrays to store first number, second number, and total
	struct point x[100]= {0};

    // declare 3 2d arrays to store first number, second number, and total
    int tot[100] = {0}; // used for addA and ___ functions
   	int last = 2; // which column to perform action on (1 is 0 and 2 is 1 in the x array)

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
	
	while( EOF != fscanf( filename, "%d %d\n", &x[i].x, &x[i].y )) // loop through until EOF and store the numbers into the arrays.
	{
		i++;
	}
	for ( int i = 0; i < n; i++ )
	{
		printf("%2d: %2d %2d\n", i, x[i].x, x[i].y );
	}

// use function to solve the following

	// max of array & print
	printf("\nLargest number in column %d of x array is %d\n\n", last, maxA(x, last, n));
   
    //sum of first array & print
	printf("Sum of numbers in column %d of x array is %d\n\n", last, sumA(x, last, n));   

	// search for value "t"
	printf("Is value 45 there? %d\n\n", searchval(x, last, n, 45));
       
   // populate 3rd array as sum of first two
   addA( tot, x, n );
               
   // print out the totals as series of lines    x + y = tot
   for ( int i = 0; i < n; i++ ) 
   {
   	printf( "%d + %d = %d\n", x[i].x, x[i].y, tot[i] );
   }
	
	// search pair
	printf("\nA match? %d\n\n", searchpair( x, n, 6, 45 ));

   // play war; print out tie, or P1 wins, or P2 wins
   int res = war( x, n ); 
 
   if ( res == 1 ) 
   {
   	printf("P1 Wins\n\n");
   } else if ( res == 2 ) 
   {
   	printf("P2 Wins\n\n");
   } else 
   {
   	printf("Tie\n\n");
   }

fclose(filename); // close file

}
