// CSC 300:  list development
//  Version B:  Location 0 in the array is used to
//       hold the length and the rest of the spots
//       hold the list contents

#include <stdio.h>
#include <stdlib.h>

#define MaxList 50

void insertEnd( int L[], int x )
{
	int length = L[0]; // get length from first element om array
	
	length++; // increment length
	L[length] = x; // insert value at the end
	L[0] = length; // increase length in first element of array
}

void insertFront( int L[], int x )
{
	int i = 0; // counter var
    int length = L[0]; // get length from first element om array

    if ( length == 0 ) // if there are no items just make the second element x
    {
        L[1] = x;
    }
    else
    {
        for ( i = length; i >= 1; i-- ) // shift elements forward (right)
        {
            L[i+1] = L[i]; // element [i] gets moved into element [i + 1] hence moving forward
        }
        L[1] = x; // insert val at beginning
    }
	length++; // increment length
	L[0] = length; // update length in first element of array
	
}

void deleteEnd( int L[] )
{
	int length = L[0];
	length--; // decrement length
    L[0] = length; // update length in first element of array 
}

void deleteFront( int L[] )
{
    int c = 0;
    int length = L[0];
    
    if ( length > 0 ) // make sure length is not 0 as to not step on element 0
    {
        for ( c = 0; c < length; c++ ) // shift elements backwards (left)
        {
            L[c] = L[c+1]; // element [1+1] gets moved into element [c] hence moving backwards
        }
    }
    length--; // decrement length
    L[0] = length; // update length in first element of array
}

int isEmpty( int L[] )
{
	int length = L[0];
	
    if ( length == 0 )
	{
		return 1;
	}
    else
	{
		return 0;
	}
}

int isFull( int L[] )
{
	int length = L[0];
	
	if ( length >= MaxList )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void printList( int L[] )
{
	int i; // counter variable
	int length = L[0];
	
    for ( i = 1; i <= length; i++) // i = 1 starts at element 1 not 0 which is the # of items in list
	{
		printf("%3d ", L[i]);
	}
    printf("\n");
}

int main()
{
        int L[MaxList] = {0};
        int x, i;

        srand( 3 );

        if (isEmpty(L) )
                printf("1 empty\n");
        else
                printf("1 notempty\n");

        x = rand() % 100;
        insertEnd( L, x );
        printList( L );

        x = rand() % 100;
        insertFront( L, x );
        printList( L );

        deleteEnd( L );
        printList( L );


// stopping early
//        return 0;

        for (i = 0; i < 5; ++i)
        {
                x = rand() % 100;
                insertEnd( L, x );
                printList( L );
        }

        for (i = 0; i < 5; ++i)
        {
                x = rand() % 100;
                insertFront( L, x );
                printList( L );
        }

        while (!isEmpty(L) )
        {
                deleteFront(L);
                printList(L);
        }

 return 0;
}