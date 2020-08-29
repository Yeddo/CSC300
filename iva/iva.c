/*
L: the list
n: number of items stored in the list, not the size of the array
val: number to insert into the list, the data
loc: the index at which new data should be inserted
         - all other data in list is preserved

All parameters will be valid; no error checking needed

Currently 0 things, insert value 10 at location 0

*/

void insertValAt( int L[], int n, int val, int loc )
{
    int i;

    if ( n == 0 ) // if there are no items just make the first element val
    {
        L[loc] = val;
    }
    else
    {
        for ( i = n; i >= loc; i-- ) // shift elements forward (right)
        {
            L[i] = L[i-1];
        }
        L[loc]=val; // insert val at position
    }
}