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
        if ( r > LAST)
                return;
        if ( tr[r] != 0 ) // if not a zero
                printf("%2d ", tr[r]); // print data
        pre(tr, r*2); // left
        pre(tr, r*2+1); // right
}

// modify to not print empty spots
void in(int tr[], int r)
{
        if ( r > LAST)
                return;
        in(tr, r*2); // left
        if ( tr[r] != 0 ) // if not a zero
                printf("%2d ", tr[r]); // print data
        in(tr, r*2+1); // right
}

// modify to not print empty spots
void post(int tr[], int r)
{
        if ( r > LAST)
                return;
        post(tr, r*2); // left
        post(tr, r*2+1); // right
        if ( tr[r] != 0)
                printf("%2d ", tr[r]); // print data
}

// iterative: check if val is in the tree
// tr is the array, for a well-formed tree
// return 1 if found 0 if not found
int isInTreeI( int tr[], int val )
{
    int r = 1;

    while ( tr[r] < LAST*2 )
    {
        if ( tr[1] == val ) // if its the root
        {
            return 1;
        }

        if ( val > tr[r] ) // look right
        {

            r = r*2+1; // move right
            
            printf("right r is %d\n", r);

            if ( tr[r] == val )
            {
                return 1; // found
            }
        }

        else if ( val < tr[r] ) // look left
        {
            r = r*2; // move left

            printf("left r is %d\n", r);

            if ( tr[r] == val )
            {
                return 1; // found
            }
        }
    }
    return 0; // if not found
}

// recursive: check if val is in the tree
// tr is the array;  r is the root index
int isInTreeR( int tr[], int r,  int val )
{
    if ( tr[1] == val ) // if its the root
    {
        return 1;
    }

	if ( val > tr[r]) // look right
    {
        r = r*2+1;

        if ( tr[1] == val )
        {
            return 1; // value found
        }
        else 
        {
            isInTreeR(tr, r, val);
        }
    }
    else if ( val < tr[r] ) // look left
    {
        r = r*2;

        if ( tr[r] == val )
        {
            return 1; // value found
        }
        else
        {
            isInTreeR(tr, r, val); // call function again if there was a value at the element
        }
    }
    return 0; // value not found   
}

// recursive: insert val into the tree
// tr is a well-formed tree
void insertR( int tr[], int r, int val )
{
    if ( r > LAST) // make sure root is not larger than tree
    {
        return;
    }

	if ( tr[1] == 0 ) // if array is empty make first element (tree root) the val 
	{
		tr[1] = val; // insert value at element 1
	}

	if ( val > tr[r] ) // go right
	{
        r = r*2+1;

        if ( tr[r] == 0 )
        {
            tr[r] = val; // insert value at empty element
        }
        else
        {
		  insertR(tr, r, val); // call function again if there was a value at the element
	    }
    }
	else if ( val < tr[r] ) // go left
	{
        r = r*2;

        if ( tr[r] == 0 )
        {
            tr[r] = val; // insert value at empty element
        }
		else
        {
            insertR(tr, r, val); // call function again if there was a value at the element
        }	
    }
}

// iterative: insert val into the tree
// uses a loop
void insertI( int tr[], int val )
{
    int r = 1;

    while ( tr[r] < LAST*2 )
    {
//        if ( tr[1] == 0 ) // if array is empty make first element (tree root) the val 
//        {
//            tr[1] = val; // insert value at element 1
//            break; // leave loop
//        }

        if ( val > tr[r] ) // look right
        {
            //r = r*2+1; // move right
            //printf("right r is %d\n", r);

            if ( tr[r] == 0 )
            {
                tr[r] = val; // insert value at empty element
                break; // leave loop
            }
            r = r*2+1; // move right
        }

        else if ( val < tr[r] ) // look left
        {
            //r = r*2; // move left
            //printf("left r is %d\n", r);

            if ( tr[r] == 0 )
            {
                tr[r] = val; // insert value at empty element
                break; // leave loop
            }
            r = r*2; // move left
        }
    }
}

int main()
{
        int t[LAST+1]={0}; // t is the tree
        int i, v;

        // on the quiz you'll replace these 2 lines
        //int dat[] = {0,20,30,10,5,15};
        //int many = 6;
        int dat[] = {0,40,30,20,10,5,4,50,60,70,80,90};
        int many = 12;

        for (i = 1; i < many; ++i)
        {
                v = dat[i];
                printf("%d\n", v);
                insertR( t, 1, v );
                //insertI( t, v );
        }

        //for (i = 1; i < LAST+1; ++i)
        {
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
        }

        // run search twice for testing
        for ( i = 0; i < 2; i++ )
        {
                printf("Value to search: ");
                scanf("%d", &v);
                printf("Found: %d\n", isInTreeI(t,v));
                //printf("Found: %d\n", isInTreeR(t,1,v));
        }
        return 0;
}