#include "maxheap20.h"

// default constructor
heap::heap()
{
	SZ = 100;
	arr = new int[100];
}

// parameterized default constructor
heap::heap( int size )
{
// create heap of given size
	//numElements = 0;
	//heapLength = size;
	SZ = size;
	arr = new int[SZ];
}


// print the array  ( this code is fine )
void heap::printA()
{
	int i;
	for (i = 1; i < last; ++i)
		cout << setw(4) << arr[i] ;
	cout << endl;
}

// Add an item to the heap
void heap::add( int x ) // add item to heap
/* 
- Just put the value into the next available position in the array because there are no spaces in a heap
- call upheap() to sift/bubble up
*/

{
	if ( isFull() ) // if the heap is full 
	{
		cout << "Heap is full, could not insert value." << endl;
		return;
	}
	else if ( isEmpty () ) // if the heap is empty just make the value root
	{
		h[1] = x; // insert value at element 1
		return;
	}
	
	numElements++;
	i = numElements;
	
	h[i - 1] = x; // insert value at end of array/heap
	upheap(); // call upheap to sift/bubble up

}
// start at item last, move it up until 
//   heap property is restored 
void heap::upheap()
/*
- if value is greater than the value of it's parent then swap them. repeat until you reach the root element or false.
*/
{	
	int i;

	while ( i != 1 && i > h[ i / 2] ) // while i is not the root node and is greater than it's parent
	{
		h[ i ] = h[ i / 2]; // move down
		i = ( i / 2 ); // move to parent
	}
	heap[i] = x; // insert value
}


int heap::remove() // remove from heap (largest #/root value
/*
- copy last value from heap to the root
- decrement the number of elements
- call downheap()
*/
{	
	int last;
	
	if ( isEmpty () ) // if empty, done
	{
		return;
	}
	
	last = h[numElement - 1]; // get last element
	h[0] = last; // replace root with last element
	numElement--; // decrease size of heap by 1
	downheap(); // call to sift/bubble down
	return h;
}


// start at item 1, move it down until 
//   heap property is restored 
// ** swap with larger child & repeat
void heap::downheap()
/*
- if one of its children has a larger value, then move it to the child with the largest value
- repeat until you reach a leaf
parent = i / 2
lchild = 2 * i
rchild = 2 * i + 1
*/

{
		int child;
		int last;
		last = numElement - 1;

	
	while ( child <= numElements )
	{
		if ( child < numElements && h[child] < h[ child + 1 ] )
		{
			child ++;
		}
		if ( last = h[child] ) // can you put last in heap[child]?
		{
			break; // yup
		}
		// nope
		h[i] = h[ child ]; // move child up
		i = child; // move down a level
		child = child * 2;
		}
	}
	h[i] = last;
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
	if ( numElements >= heapLength )
	{
		return true;
	}
	return false;
}


// don't think I need this as i'm doing that in the parameterized constructor ....
int heap::SZ() // size of array/heap
{
	
}

int heap::*array // dynamically allocated array of appropriate size to impliment heap
{
	int *arr; // initialize pointer
	//arr = calloc( size, sizeof( int ); // same as below just a different version
	arr = malloc( size * sieof(int) ); // allocate memory. not sure if this is 100% because of the size variable
	return arr; // return the pointer
}

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
}
*/