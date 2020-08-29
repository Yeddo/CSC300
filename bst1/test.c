40
30
20
10
5
4
50
60
70
80
90
40 30 50 20  0  0 60 10  0  0  0 
 preorder: 40 30 20 10  5  4 50 60 70 80 90 
  inorder:  4  5 10 20 30 40 50 60 70 80 90 
postorder:  4  5 10 20 30 90 80 70 60 50 40 

40
30
20
10
5
4
50
60
70
80
90
40 30 50 20  0  0 60 10  0  0  0 
 preorder: 40 30 20 10  5  4 50 60 70 80 90 
  inorder:  4  5 10 20 30 40 50 60 70 80 90 
postorder:  4  5 10 20 30 90 80 70 60 50 40 


int isInTreeI( int tr[], int val )
{
    int r = 1;

    
    while ( r < LAST )
    {
        if ( val > tr[r]) // look right
        {
            r = r*2+1;

            if ( tr[r] == val )
            {
                return 1; // value found
            }
            printf(" r is %d\n", r);
        }
        else if ( val < tr[r] ) // look left
        {
            r = r*2;

            if ( tr[r] == val )
            {
                return 1; // value found
            }
            printf (" r is %d\n", r);
        }
    }
}

void insertI( int tr[], int val )
{
    int r = 1;

    while ( val < tr[r] ) // go left
    {
        if ( tr[r] == 0 )
        {
            tr[r] = val; // insert value at empty element
            break;
        }
        r= r*2;
    }

    while ( val > tr[r] ) // go right
    {
        if ( tr[r] == 0 )
        {
            tr[r] = val; // insert value at empty element
            break;
        }
        r = r*2+1; 
    }
}
