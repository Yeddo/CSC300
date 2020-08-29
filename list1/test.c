#include <stdio.h>
#include <stdlib.h>

#define MaxList 50

struct list_type
{
        int data[MaxList];
        int len;
};

typedef struct list_type alist;

// this is fine
void makeList( alist *L )
{
        L->len = 0;
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
        for ( i = L->len; i >= 0; i-- ) // shift elements forward (right)
        {
            L->data[i+1] = L->data[i];
        }
        L->data[0] = x; // insert val at beginning
    }
    L->len += 1; // increment length
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

 //       insertEnd( myList, 8 );
 //       deleteFront(myList);
        insertFront( myList, 9 );
        printList( myList );
}