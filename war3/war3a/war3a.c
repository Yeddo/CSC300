/* Program war3a: dynamic allocation of parallel arrays

Program war3a:
 - dynamically allocated arrays

All the rules apply, except for these enhancements:
 - array to store the 2 columns of numbers
    should be dynamically allocated to the proper size
- very similar to A1War1 otherwise

Add this function & call it from main


int *allocArray( int n )

*/

// --------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

// dynamically allocate the arrays.
int *allocArray( int n )
{
	int *heapArray
	A = calloc( n, sizeof(int0 );
	//A = malloc( n * sieof(int) );
	return heapArray;
}

// return biggest number from array. there are n items
int maxA( int arr[], int n )
{
	int max = arr[0];
	// loop through array and compare every element with max
	for ( int i = 0; i < n; i++) 
	{
		if (arr[i] > max) 
		{
			max = arr[i];
		}
	}
	return max;
}

// return sum of values in array. there are n items
int sumA( int arr[], int n )
{
	int sum = 0;
	
	for ( int i = 0; i < n; i++ )
	{
		sum += arr[i];
	}
	return sum;
}

// item by item sum;  z = x + y
void addA( int z[], int x[], int y[], int n )
{
	for ( int i = 0; i < n; i++ ) 
	{
		z[i] = x[i] + y[i];
	}
}

// check for item t in array. return 1 for yes, 0 for no
int searchval( int arr[], int n, int t )
{
	int ret = 0;

    for( int i = 0; i < n; i++ ) 
    {
        if( arr[i] == t ) 
        {
            ret++;
            break;
        }
    }
    return ret;
}

// is pair (p,q) in the arrays
int searchpair( int a[], int b[], int n, int p, int q )
{
	int ret = 0;

	for( int i = 0; i < n; i++ ) 
	{
		if ( a[i] == p && b[i] == q ) 
		{
			ret++;
			break;
		}
	}
	return ret;
}

// play war, largest value in each contest wind
// return value for overall cummulative result
// 0 for tie, 1 for first array, 2 for second array
int war( int x[], int y[], int n )
{
	int i = 0; // loop counter var
	int xPoint = 0; // var for x points
	int yPoint = 0; // var for y points
	int ret = 0; // return value
	
	for ( i = 0 ; i < n; i++)  
	{ 
		if ( x[i] > y[i] ) // if x wins increment x
		{
			xPoint++; 
		} 
		else // if x doesn't win increment y
		{
			yPoint++; 
		}
	}	
	if ( xPoint > yPoint) // if x wins
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
	int n = 5; // number of rows in arrays

    // declare 3 arrays to store first number, second number, and total
	x = allocArray(n); // call to function to initialize arrays x and y and fill with numbers
	y = allocArray(n); 
    int tot[100] = {0}; // initialize tot array and fill with 0s
   
    // get the filename as a command line argument
	// ?? not sure what this means but i'm doing that w/argv parameter from main and getting it when opening it below.
	
    // open & read the file into the 2 arrays
	int i = 0; // counter
		
	//FILE *filename = fopen(argv[1], "r"); // declare file pointer and opens the file that's passed as arg. 
	//if (filename == NULL) // make sure there is a filename passed.
	//{
	//	printf("\nERROR: Please enter a valid file name as an argument: i.e., ./war1 xy.dat\n\n");
	//	return -1; // error if no file.
	//}
	//fscanf(filename, "%d", &n); // grab first line in file and store as n.
	
	//while(EOF != fscanf(filename, "%d\t%d\n", &x[i], &y[i])) { // loop through until EOF and store the numbers into the arrays.
	//	i++;
	//}
	
// use function to solve the following

    //max of first array & print
    printf("\nLargest number in x array is %d\n", maxA(x, n));
    
    //max of second array & print
	printf("Largest number in y array is %d\n\n", maxA(y, n));         

    //sum of first array & print
	printf("Sum of numbers in x array is %d\n", sumA(x, n));   
        
    //sum of second array & print
	printf("Sum of umbers in y array is %d\n\n", sumA(y, n));   

    // populate 3rd array as sum of first two
    addA(tot,x,y,n);
                
    // print out the totals as series of lines    x + y = tot
    for ( int i = 0; i < n; i++ ) 
    {
    	printf("%d + %d = %d\n", x[i], y[i], tot[i]);
    }
	 
    // play war; print out tie, or P1 wins, or P2 wins
    int res = war( x, y, n ); 
  
    if ( res == 1 ) 
    {
    	printf("\nP1 Wins\n\n");
    } 
    else if ( res == 2 ) 
    {
    	printf("\nP2 Wins\n\n");
    } 
    else 
    {
    	printf("\nTie\n\n");
    }

//fclose(filename); // close file
}
