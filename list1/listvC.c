// CSC 300:  list development
//  Version C: Structure for a list, with members
//      - data array of a fixed size
//      - len as number of items

#include <stdio.h>
#include <stdlib.h>

#define MaxList 50

struct list_type
{
        int data[MaxList];
        int len;
};

typedef struct list_type alist;


int isEmpty( alist * );
int isFull( alist * );

// this is fine
void makeList( alist *L )
{
        L->len = 0;
}

// return 0 on failure
// return 1 on success
int insertAt( alist *L, int loc, int x )
{
    int i;

//    if ( L->len == 0 ) // if there are no items just make the first element x
//    {
//        L->data[loc] = x;
//    }
//    else if ( loc == L->len ) // if location is at the end
//    {
//        L->data[loc] = x;
//    }
    if ( L->len >=0 )
    {
        for ( i = L->len; i >= loc; i-- ) // shift elements forward (right)
        {
            L->data[i] = L->data[i-1];
        }
        L->data[loc] = x; // insert val at position
        L->len += 1; // increase length
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int insertEnd( alist *L, int x )
{
        // use insertAt as a helper function
        int end;
        
        end = L->len;
        insertAt( L, end, x );
}

int insertFront( alist *L, int x )
{
	int i = 0;

    if ( L->len == 0 ) // if there are no items just make the first element x
    {
		L->data[0] = x;
    }
    else
    {
        for ( i = L->len - 1; i >= 0; i-- ) // shift elements forward (right)
        {
            L->data[i+1] = L->data[i];
        }
        L->data[0] = x; // insert val at beginning
    }
    L->len += 1; // increment length
}

int deleteEnd( alist *L )
{
    if ( L->len == 0 ) // check if length is 0 to prevent going negative
    {
        L->len = 0;
    }
    else
    {
        L->len -= 1; // decrement length
    }    
    
}

int deleteFront( alist *L )
{
        int c = 0;
        
        if ( L->len > 0 ) // make sure length is not 0
        {
                for ( c = 0; c < L->len; c++ ) // shift elements backwards (left)
                {
                        L->data[c] = L->data[c+1];
                }
                L->len -= 1;
        }
}

int isEmpty( alist *L )
{
        if ( L->len == 0 )
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int isFull( alist *L )
{
        if ( L->len >= MaxList ) 
        {
                printf("len is %d MaxList is %d\n\n", L->len, MaxList);
                return 1;
        }
        else
                printf("len is %d MaxList is %d\n\n", L->len, MaxList);
        {
                return 0;
        }
}

void printList( alist *L )
{
        int k;
        printf("Len: %d: ", L->len);
        for ( k = 0; k < L->len; k++ )
                printf("%2d ", L->data[k]);
        printf("\n");
}

// this main will work when you are done
int main()
{
        // these 2 lines are odd, but use myList as the pointer to a list
        alist myListreal;
        alist *myList = &myListreal;

        int x, i;
        int go = 0;

        srand( 3 );

        makeList( myList );
        insertEnd( myList, 8 );
        deleteFront(myList);
        insertFront( myList, 9 );
        deleteEnd(myList);

        insertFront( myList, 2 );

        while ( !isEmpty(myList) && !isFull(myList) )
        {
                go++;
                printf("%3d)\n", go);
                x = rand() % 100;
                if ( x % 3 )
                {
                        printf("At end %d\n", x);
                        insertFront( myList, x );
                        printList( myList );
                }
                else
                {
                        printf("rem\n");
                        deleteEnd( myList );
                        printList( myList );
                }
        }
        printf("all done %d\n", go);

        return 0;
}