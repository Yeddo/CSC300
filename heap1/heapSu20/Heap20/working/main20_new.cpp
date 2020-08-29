#include <iostream>
#include <iomanip>
#include <fstream>
#include "maxheap20_new.h"
using namespace std;


int main(int argc, char *argv[])
{
	heap h; // this was given.
	int rv, x;
	
	int a, b; // vars a and b for command file
	ifstream ifp;
	
	if (argc != 2) // make sure there are 2 args passed
	{
		cout << "ERROR:  no heap CMD file " << endl;
		return 2;
	}

	ifp.open( argv[1] ); // open passed file

	if ( ! ifp.is_open() ) // if I can't find/open file
	{
		 cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
		 return 3;
	}
	
	ifp >> a; // grab first number in file
	
    while( a != 0 ) // while not 0 ( 0 is quit )
	{
		if ( a == 1 ) // insert value into heap
		{
			ifp >> b;
			h.add( b );
		}
		
		else if ( a == 3 ) // print heap
		{
			h.printA();
		}
		
		else if ( a == -1 ) // remove max value from heap
		{
			cout << "Max value: " << h.remove() << " removed from heap" << endl;
		}
		
		else if ( a == 0 ) // quit
		{
			exit(0);
		}

		ifp >> a; // get the next line
	}

	ifp.close(); // close file
	return 0;
}