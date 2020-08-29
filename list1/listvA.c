// CSC 300:  list development
//  Version A:  array & len as parameters

#include <stdio.h>
#include <stdlib.h>

#define MaxList 50

void insertEnd( int L[], int *len, int x )
{
    int length = *len;

    *len += 1; // increment length
	L[length] = x;
}

void insertFront( int L[], int *len, int x )
{
    int i = 0;

    if ( *len == 0 ) // if there are no items just make the first element x
    {
        L[0] = x;
    }
    else
    {
        for ( i = *len; i >= 0; i-- ) // shift elements forward (right)
        {
            L[i+1] = L[i];
        }
        L[0] = x; // insert val at beginning
    }
	*len += 1; // increment length
}

void deleteEnd( int L[], int *len )
{
    *len-= 1;
}

void deleteFront( int L[], int *len )
{
	int c = 0;
	
	if ( len > 0 ) // make sure length is not 0
	{
		for ( c = 0; c < *len; c++ ) // shift elements backwards (left)
		{
			L[c] = L[c+1];
		}
	}
	*len -= 1;
}

int isEmpty( int L[], int len )
{

        if ( len == 0 )
                return 1;
        else
                return 0;
}

int isFull( int L[], int len )
{
	if ( len >= MaxList )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void printList( int L[], int len )
{

        int i;
        for ( i = 0; i < len; i++)
                printf("%3d ", L[i]);
        printf("\n");
}


int main()
{

        int L[MaxList] = {0};
        int lsz = 0;          // list size, items in list
        int x, i;

        srand( 3 );

        if (isEmpty(L, lsz) )
                printf("1 empty\n");
        else
                printf("1 notempty\n");

        if (isFull(L, lsz))
                printf("1 full\n");
        else
                printf("1 notfull\n");


        x = rand() % 100;
        printf("About to add %d\n", x);
        insertEnd( L, &lsz, x );
        printList( L, lsz );
        x = rand() % 100;
        insertEnd( L, &lsz, x );
        printList( L, lsz );


// stopping early
//        return 0;


        if (isEmpty(L, lsz))
                printf("2 empty\n");
        else
                printf("2 notempty\n");

        if (isFull(L, lsz))
                printf("2 full\n");
        else
                printf("2 notfull\n");

        for (i = 0; i < 5; ++i)
        {
                x = rand() % 100;
                insertEnd( L, &lsz, x );
                printList( L, lsz );
        }
        for (i = 0; i < 5; ++i)
        {
                x = rand() % 100;
                insertFront( L, &lsz, x );
                printList( L, lsz );
        }

        if (isEmpty(L, lsz))
                printf("3 empty\n");
        else
                printf("3 notempty\n");

        if (isFull(L, lsz))
                printf("3 full\n");
        else
                printf("3 notfull\n");

        while (!isEmpty(L, lsz) )
        {
                //deleteEnd(L, &lsz);
                deleteFront(L, &lsz);
                printList(L, lsz);
        }

        return 0;
}