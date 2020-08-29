// Binary Search Tree - as an array
//  - limited size/depth
//  - limited use - just to get us started
//
//  - let 0 represent an unused array entry


#include <stdio.h>
#include <stdlib.h>

#define LAST 63
// change to 63 once you get printing fixed
//#define LAST 63
// the last index in the array that can be used
//   for a tree value.
// hint/caution, this may not be the size of the array

// modify to not print empty spots
void pre(int tr[], int r)
{
        if ( r > LAST) // keeps from going larger than tree
                return;
        if ( tr[r] != 0 ) // if not a zero
                printf("%2d ", tr[r]); // print data
        pre(tr, r*2); // left
        pre(tr, r*2+1); // right
}

// modify to not print empty spots
void in(int tr[], int r)
{
        if ( r > LAST) // keeps from going larger than tree
                return;
        in(tr, r*2); // left
        if ( tr[r] != 0 ) // if not a zero
                printf("%2d ", tr[r]); // print data
        in(tr, r*2+1); // right
}

// modify to not print empty spots
void post(int tr[], int r)
{
        if ( r > LAST) // keeps from going larger than tree
                return;
        post(tr, r*2); // left
        post(tr, r*2+1); // right
        if ( tr[r] != 0) // if not a zero
                printf("%2d ", tr[r]); // print data
}

// iterative: check if val is in the tree
// tr is the array, for a well-formed tree
// return 1 if found 0 if not found
int isInTreeI( int tr[], int val )
{
    int r = 1; // starting r value

    while ( tr[r] != val ) // while not the value do this
    {
        if ( val > tr[r] ) // look right
        {
            r = r*2+1; // move right
        }

        else if ( val < tr[r] ) // look left
        {
            r = r*2; // move left
        }
        
        if ( r > LAST ) // not found
        {
            return 0;
        }
    }
    return 1; // found
}

// recursive: check if val is in the tree
// tr is the array;  r is the root index
int isInTreeR( int tr[], int r,  int val )
{
    if ( r > LAST ) // make sure root is not larger than the tree and if so, means that the value wasn't found
    {
        return 0; // not found
    }
 
    else if ( tr[r] == val ) // check if it's the one
    {
        return 1;
    }

    else if ( val > tr[r] ) // move right
    {
        r = r*2+1;
        isInTreeR( tr, r, val ); // call function again with new r value
    }
    else // move left
    {
        r = r*2;
        isInTreeR( tr, r, val ); // call function again with new r value
    }  
}

// recursive: insert val into the tree
// tr is a well-formed tree
void insertR( int tr[], int r, int val )
{
    if ( tr[r] == 0 ) // if nothing (0) is there
	{
		tr[r] = val; // insert value
	}

	else if ( val > tr[r] ) // move right
	{
        r = r*2+1;
        insertR(tr, r, val); // call function again with new r value
    }

	else // move left
	{
        r = r*2;
        insertR(tr, r, val); // call function again with new r value
    }	
}

// iterative: insert val into the tree
// uses a loop
void insertI( int tr[], int val )
{
    int r = 1;

    while ( tr[r] != 0 ) // while the element in the array is not empty (0)
    {
        if ( val > tr[r] ) // look right
        {
            r = r*2+1; // move right
        }

        else if ( val < tr[r] ) // look left
        {
            r = r*2; // move left
        }
    }
    tr[r] = val; // insert value at empty element
}

int main()
{
        int t[LAST+1]={0}; // t is the tree
        int i, v;

        // on the quiz you'll replace these 2 lines
        //int dat[] = {0,20,30,10,5,15};
        //int many = 6;
        //int dat[] = {0,40,30,20,10,5,4,50,60,70,80,90};
        //int many = 12;
        //int dat[]={0,10,50,60,70,22,30,25,59,58,57,31,32,15};
        //int many = 14;
        int dat[]={0,10,50,60,70,22,30,25,59,58,57,31,32,15};
        int many = 14;

        for (i = 1; i < many; ++i)
        {
                v = dat[i];
                printf("%d\n", v);
                insertR( t, 1, v );
                //insertI( t, v );
        }

        // print loop
//      for (i = 1; i < LAST+1; ++i)
//        {
//            v = t[i];
//            printf("%d) %d\n", i, v);
//        }
//        {
        for (i = 1; i < many; ++i)
          printf("%2d ", t[i]);
        printf("\n");

        printf(" preorder: ");
        pre( t, 1 );
        printf("\n");

        printf("  inorder: ");
        in( t, 1 );
        printf("\n");

        printf("postorder: ");
        post( t, 1 );
        printf("\n");
//        }

        // run search twice for testing
        for ( i = 0; i < 2; i++ )
        {
                printf("Value to search: ");
                scanf("%d", &v);
                //printf("Found: %d\n", isInTreeI(t,v));
                printf("Found: %d\n", isInTreeR(t,1,v));
        }
        return 0;
}