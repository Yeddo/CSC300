#include "q.h"

void enq( queue q, int num )
{
    struct lnode *tmp; // initialize tmp node
    tmp = malloc(sizeof(struct lnode)); // create tmp node
    tmp->data = num; // put value in the tmp node
    tmp->next = 0; // becasue it's the end, nothing is behind
	
	if(!isEmptyq(q)) // if not empty go after the old back
	{
		q->back->next = tmp;
	}
	else // if queue is empty become the front
	{
		q->front = tmp;
	}
    q->back = tmp; // new back
}

int deq( queue q )
{
    int x;
	struct lnode *tmp; // make tmp node
	
    x = q->front->data; // set x as the data to be deleted
    tmp = q->front; // set tmp to the front of queue
    q->front = tmp->next; // move front to next node

    free(tmp); // free node
    return x; // return data that was deleted
}

// this is fine
void showq( queue q )
{
    struct lnode *mov;
    mov = q->front;
    while (mov != NULL)
    {
        printf("%3d ", mov->data);
        mov = mov->next;
    }
    printf("\n");

}

// needs some work
queue makeq( ) // create a new empty queue
{
	queue nq;
	nq = malloc( sizeof( struct qtype ) );
    nq->front = 0;
    nq->back = 0;
    return nq; // return the queue
}

int isEmptyq( queue q )
{
    return (q->front == 0); // return true if empty
}


