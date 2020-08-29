/*
command code & formats:

1:  insert value x into q
      1    x    
3:  print q front to back on 1 line
    label each print with sequential value
-1: remove value from q, return it
-7: clear the q
      -7   x     
     x is the label for the output
     print the number of items & sum of items on 1 line
     q is empty when finished
0:   quit

*/



// Process the command file
//   filename is on the command line
//   make sure filename is provided & is opened
#include "q.h"
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
	int a, b, x, len, sum, t = 1; // vars
	char* buff = malloc(100); // initialize memory buffer for cmd file
	FILE *cmdFile; // initialize file pointer
	queue s;
	s = makeq();


	if (argc < 2 || argc > 3 ) // make sure their is 2 args passed
    {
        printf("[ERROR]: use %s <cmd_file> to run program\n", argv[0]);
        exit(1);
    }

    cmdFile = fopen( argv[1], "r"); // open command file for reading
    if (cmdFile == NULL) // if doesn't exist ...
    {
        printf("[ERROR]: file %s not available\n", argv[1]);
        exit(1);
    }

    fgets( buff, 100, cmdFile ); // read next line in file and store each int in an var
	sscanf( buff, "%d %d", &a, &b ); // parse char array into 2 int vars

    while( !feof(cmdFile) ) // while not EOF
	{
		if ( a == 1 ) // insert value into q
		{
			enq(s, b);
		}
		
		else if ( a == 3 ) // print queue
		{
			struct lnode *prt; // create tmp node
    		prt = s->front; // made tmp node point to front
    		printf("%d: Q F-R: ", t); // initial print banner info

    		while (prt != NULL) // while not end of list
    		{
        		printf("%3d ", prt->data); // print value
        		prt = prt->next; // move to next
    		}
    		printf("\n"); // for newline niceness
    		t++; // increment counter
		}
		
		else if ( a == -1 ) // remove value from q
		{
			x = deq(s); // remove value from q and get return
			//printf("removed %d\n", x);
		}
		
		else if ( a == -7 ) // clear the q
		{
			int len = 0; // counter var
			int sum = 0; // var to add deleted values
			struct lnode *clr; // create tmp node
    		clr = s->front; // made tmp node point to front
			
			while ( !isEmptyq(s) ) // while not end of the queue
			{
				x = deq(s); // remove value from q and get return
				len++; // increase count
				sum = sum + x; // sum values
				//clr = clr->next; // move to next
			}
//			x = deq(s); // remove last value from q and get return
//			len++; // increase count
//			sum = sum + x; // sum values

			printf("Clean: %d: len: %d sum: %d\n", b, len, sum);
		}
		
		else if ( a == 0 ) // quit
		{
			exit(0);
		}

		fgets( buff, 100, cmdFile ); // read next line in file
		sscanf( buff, "%d %d", &a, &b ); // parse char array into 2 int vars
//		printf("%d and %d\n", a, b);
	}
	free(buff); // free allocated memory
	fclose(cmdFile); // close file
	
	return 0; 
}
