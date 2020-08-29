#include "lla.h"


struct lheader *makelist( )
{
	struct lheader *alist;
	alist = malloc( sizeof( struct lheader ) );
	alist->len = 0;
	alist->start = NULL;
	return alist;
}

struct lnode *makenode( int val )
{
	struct lnode *box;
	box = malloc( sizeof( struct lnode ) );
	box->data = val;
	box->next = NULL;
	return box;
}


void insertFront( struct lheader *L, int val )
{
	struct lnode *n;
	n = makenode( val );

	n->next = L->start;
	L->start = n;
	L->len++;
}

// write this one
void insertBack( struct lheader *L, int val )
{
	struct lnode *n,  *end;
	n = makenode( val ); // make a new node
	end = L->start; // make end pointer point to where start points

	while ( end->next != NULL ) // traverse to the last node but not after it (NULL). Goes to the node that points to NULL.
	{
		end = end->next;
	}
	end->next = n; // point last node to the newly created one (n)
	L->len++; // increment legth by 1
}

// write this one
int removeFront( struct lheader *L )
{
	struct lnode *tmp;
	tmp = L->start; // store where start points in tmp
	L->start = tmp->next; // move where start points to the next node
	L->len--; // decrement length
	return tmp->data; // returns the # being removed to the calling function
	free(tmp); // clears memory occupied by the tmp, the first node
}

int isInList( struct lheader *L, int val )
{
	struct lnode *tmp;
	tmp = L->start;
	while ( tmp != NULL)
	{
		if (tmp->data == val)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

// write this one
struct lnode *findNode( struct lheader *L, int val )
{
	struct lnode *tmp;
	tmp = L->start; // store where start points in tmp

	while ( tmp != NULL ) // while tmp isn't the last node
	{
		if ( tmp->data == val ) // if the current node value is = to the val passed
		{
			return tmp; // return node
		}
		tmp = tmp->next; // move to next node
	}
	return NULL; // if val isn't in the linked list
}

// optional
void insertAfter( struct lheader *L, int val, struct lnode *p )
{
  	struct lnode *n;
	int i;
	n = makenode( val ); // create new node
	n->next = p->next; // sets the new node to what p is pointing to
	p->next = n; // points new node to point to the next node p is pointing to
	L->len++; // increase length
}

// optional
void insertBefore( struct lheader *L, int val, struct lnode *p )
{
	struct lnode *n, *tmp, *prev; // need 2 pointers for this one tmp and prev
	int i;

	tmp = L->start; // store where start points in tmp
	n = makenode( val ); // create new node with passed value

	while ( tmp != NULL ) // traverse both prev and tmp in parallel
	{
		if ( tmp->data == p->data ) // check to see if current data value is equal to passed
		{
			n->next = tmp; // make new node point to tmp
			if ( prev != NULL ) // if prev is not at the end
			{
				prev->next = n; // make what prev point to new node
			}
		}
		prev = tmp; // current node (tmp) will become previous (prev)
		tmp = tmp->next; // moving to next node
	}
	L->len++; // increase length
}


void printlist( struct lnode *front )
{
	struct lnode *mov;
	mov = front;
	while (mov != NULL)
	{
		printf("%d  ", mov->data);
		mov = mov->next;
	}
	printf("\n");
}


void printer( struct lheader *alist )
{
	struct lnodev *mov;
	printf("--------------------------\n");
	printf("List print, len %d\n", alist->len); 
	printlist( alist->start ); 
	printf("--------------------------\n");
}

