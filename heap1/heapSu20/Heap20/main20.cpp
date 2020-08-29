#include <iostream>
#include <iomanip>
using namespace std;

#include "maxheap20_edited.h"

int main()
{
	heap h(5);
/*	
	if (h.isEmpty())
	{
		cout << "Empty Heap" << endl;
	}
	else 
	{
		cout << "NOT Empty Heap" << endl;
	}
*/
	h.add(10);
	h.add(20);
	h.add(64);
	h.add(34);
	
	int r = h.remove();
	cout << r << endl;
	
	h.add(16);
	
	h.printA();	
	return 0;
}


//int main()
//{
//	heap h; // this was given.
//	int rv, x;
//	
///* commented out until other stuff is working
//	
//	int a, b, // vars a and b for command file
//	ifstream ifp;
//	
//	if (argc != 2) // make sure there are 2 args passed
//	{
//		cout << "ERROR:  no heap CMD file " << endl;
//		return 2;
//	}
//
//	ifp.open( argv[1] ); // open passed file
//
//	if ( ! ifp.is_open() ) // if I can't find/open file
//	{
//		 cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
//		 return 3;
//	}
//	
//	ifp >> a; // grap first number in file
//	
//    while( a != 0 ) // while not 0 ( 0 is quit )
//	{
//		if ( a == 1 ) // insert value into heap
//		{
//			ifp >> b;
//			h.add( b );
//		}
//		
//		else if ( a == 3 ) // print heap
//		{
//			h.printA();
//		}
//		
//		else if ( a == -1 ) // remove max value from heap
//		{
//			cout << "Max value: " << h.remove() << " removed from heap" << endl;
//		}
//		
//		else if ( a == 0 ) // quit
//		{
//			exit(0);
//		}
//
//		ifp >> a; // get the next line
//	}
//
//	ifp.close(); // close file
//*/
//
//// below is to test before implimenting the I/O file
//	cout <<  "Value to insert (-1 to stop): ";
//	cin >> x;
//	while (x != -1)
//	{
//		h.add( x );
//		h.printA();
//		cout <<  "Value to insert (-1 to stop): ";
//		cin >> x;
//	}
//	
//	
//	cout <<  "-1 to remove 0 to stop: ";
//	cin >> x;
//	while ( x == -1 )
//	{
//		rv = h.remove( );
//		cout << "removed " << rv << endl;
//		h.printA();
//		cout <<  "-1 to remove 0 to stop: ";
//		cin >> x;
//	}
//	
//	return 0;
//}
