/*
2 command line args: name of input file, name of output file

Input: 2 numbers per line
Output: The sum of those 2 numbers ( as a nice expression )

Best: any number of integer pairs
OK: If need to solve it, first line tells you how many pairs
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
    FILE *inFile, *outFile; // initialize file pointers
	char buff[100] = {0};
	int a, b;

    if (argc < 3) // make sure their are 3 args passed
    {
        printf("[ERROR]: use %s <input_file> <output_file> to run program\n", argv[0]);
        exit(1);
    }
    
    inFile = fopen( argv[1], "r"); // open input file for reading
    if (inFile == NULL) // if doesn't exist ...
    {
        printf("[ERROR]: file %s not available\n", argv[1]);
        exit(1);
    }
	
	outFile = fopen( argv[2], "w"); // open output file for writing
	if (outFile == NULL) // if doesn't exist ...
	{
		printf("[ERROR]: File %s is not available\n", argv[2]);
		exit(1);
	}
	
	fgets( buff, 100, inFile); // read next line in files
	sscanf(buff,"%d %d ", &a, &b); // parse char array into 2 int vars

	while( !feof(inFile) ) 
	{
		fprintf(outFile, "%d + %d = %d\n", a, b, a+b); // write to output file
		printf("%d + %d = %d\n", a, b, a+b); // print to screen
		fgets( buff, 100, inFile); // read next line in files
		sscanf(buff,"%d %d ", &a, &b); // parse char array into 2 int vars
	}

	// close files
	fclose(inFile);
	fclose(outFile);

	return 0;
}