#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode
{
	int data;
	struct lnode *next;
};

struct qtype 
{
	struct lnode *front;
	struct lnode *back;
};

typedef struct qtype *queue;


void enq( queue q, int num );
int deq( queue q );
void showq( queue q );
int isEmptyq( queue q );
queue makeq( );

