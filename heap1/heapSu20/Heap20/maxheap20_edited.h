#include <iostream>
#include <iomanip>
#include "maxheap20_new.h"
using namespace std; 

class heap
{
 public:
   heap(); // constructor, size is whatever
   heap( int size ); // parameterized constructor, heap ( 320 ) - 320 element array for heap
   void add( int x ); // add item to heap
   int remove(); // remove from heap (Root/Largest #)
   void printA(); // print array
   bool isEmpty(); // heap empty
   bool isFull(); // heap full
//   int heapSort(); // sort a heap
 private:
   int *arr; // dynamically allocated array of appropriate size to impliment heap
   int SZ; // size of array, how many spots
   //int last; // last element of heap/portion that's used. 
   
   int numElements;  // **** ADDED this here !!!!  SK
   
   void upheap(); // for insert
   void downheap( int ); // for delete
};

// default constructor
heap::heap()
{
	SZ = 100;
	arr = new int[101];
	numElements = 0;
}

// parameterized default constructor
heap::heap( int size )
{
// create heap of given size
	numElements = 0;
	SZ = size;
	arr = new int[SZ+1];	
}


// print the array  ( this code is fine )
void heap::printA()
{
	int i;
	for (i = 1; i <= numElements; ++i)
		cout << setw(4) << arr[i] ;
	cout << endl;
}


// Add an item to the heap
void heap::add( int x ) // add item to heap
//- Just put the value into the next available position in the array because there are no spaces in a heap
//- call upheap() to sift/bubble up
{
	if ( isFull() ) // if the heap is full 
	{
		cout << "Heap is full, could not insert value." << endl;
		return;
	}
	else if ( isEmpty () ) // if the heap is empty just make the value root
	{
	    arr[1] = x; // insert value at element 1
		numElements++;
		return;
	}
	numElements++;	
	arr[numElements] = x; // insert value at end of array/heap
	upheap(); // call upheap to sift/bubble up

}


// start at item last, move it up until 
// heap property is restored 

void heap::upheap()
//- if value is greater than the value of it's parent then swap them. repeat until you reach the root element or false.
//- compare newly instered value with its parent. If the parent is larger, stop. If the parent is smallwer, swap the item with its parent.
//- Repeat ^ until the parent is larger or equal to the value.
{	
	int i = numElements; // Last value in heap/number insterted. It's position

	while ( i != 1 && arr[i] > arr[ i / 2] ) // while i is not the root node and is greater than it's parent
	{
		int temp = arr[i]; // swap
		arr[i] = arr[i/2];
		arr[i/2] = temp;
		
		i = ( i / 2 ); // move to parent
	}
}


int heap::remove() // remove from heap (largest #/root value
//- replace the first node with the value in the last node.
//- call downheap()
{	
	int last;
	int root = arr[1];

	if ( isEmpty () ) // if empty, done
	{
		return -1;
	}
	
	last = arr[numElements]; // get last element
	arr[1] = last; // replace root with last element
	numElements--; // decrease size of heap by 1
	downheap( 1 ); // call to sift/bubble down
	return root;  // Return back the biggest #. If downheap is done right the largest value should be root now.
}


// start at item 1, move it down until 
//   heap property is restored 
// ** swap with larger child & repeat
void heap::downheap( int i )
//- check the first node with its children nodes. If the left child is larger, swap it with the left child. If the right node is larger, swap it with the right node.
//- repeat ^ until the parent node is larger than the left and right child node.
//- return the max value.
// parent = i / 2
// lchild = 2 * i
// rchild = 2 * i + 1

{
	int largest = i; // Initialize largest as root
	int lchild;
	int rchild;
	
	lchild = 2*i; // left = 2*i
	rchild = 2*i + 1; // right = 2*i + 1

	// If left child is larger than root
	if ( lchild < numElements && arr[largest] < arr[lchild] )
	{
		largest = lchild;
	}

	// If right child is larger than largest so far
	if ( rchild < numElements && arr[largest] < arr[rchild] )
	{
		largest = rchild;
	}

	// If largest is not root
	if (largest != i )
	{
		int temp = arr[i]; // swap
		arr[i] = arr[largest];
		arr[largest] = temp;
		downheap(largest);
	}
}


bool heap::isEmpty() // is the heap/array empty?
{
	if ( numElements == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool heap::isFull() // is the heap/array full?
{
	//if ( numElements >= heapLength )  *** I CHANGED THIS   SK
	
	if ( numElements >= SZ )
	{
		return true;
	}
	return false;
}

/*
NOT SURE WHAT THIS IS  :)
// don't think I need this as i'm doing that in the parameterized constructor ....
int heap::SZ() // size of array/heap how many spots there are
{
	
}
*/
/*   DON"T NEED THIS
int heap::*arr; // dynamically allocated array of appropriate size to impliment heap
{
	int *arr; // initialize pointer
	//arr = calloc( size, sizeof( int ); // same as below just a different version
	arr = malloc( size * sieof(int) ); // allocate memory. not sure if this is 100% because of the size variable
	return arr; // return the pointer
}
*/

/* nothing yet
int heap:heapSort()
{
HeapSort

- produce a decending sorted liste ( because MaxHeap )
	- keep removing the largest item

build list of values - generate a random list of numbers and put them in the array
list --> heap - take list and add to maxheap
heap --> list - remove items 1 by 1 until you get the list of data

Compare a bubble sort to a heap sort
- known seed so we can replicate the experiement
- can put bubble & heap sort in the same program so you can just uncommenet/comment the one you want
- sort using bubblesort
- sort using heapsort

- time ./a.out
	
	int i = ( numElements - 1 )
	
	for ( i / 2 - 1; i >= 0; i--) // Build heap (rearrange array)
	{
		downheap();
	}
	
	for ( i; i >= 0; i--) // One by one extract an element from heap
	{
		swap(arr[0], arr[i]); // Move current root to end
		maxheapify(); // call downheap on the reduced heap
	}
}
*/
