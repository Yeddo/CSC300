#include <iostream>
#include <iomanip>
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
   void sortHeap(); // sort a heap
 private:
   int *arr; // dynamically allocated array of appropriate size to impliment heap
   int SZ; // size of array, how many spots
   //int last; // last element of heap/portion that's used. 
   int numElements;  // **** ADDED this, guess it's the same as last ....
   void upheap(); // for insert
   void downheap( int i ); // for delete
};
