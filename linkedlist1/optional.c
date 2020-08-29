// optional
void insertAfter( struct lheader *L, int val, struct lnode *p )
{
  struct lnode *tmp;
  int pos, i;

  printf("Insert after which node? (1-%d)\n ", L->len ); // after node
  scanf( "%d", &pos );
  if ( L->start == NULL ) // if nothing in the list make start point to p
  {
    L->start = p;
    L->len++; // increment length
  }
  else
  {
    tmp = L->start; // make tmp point to 1st node
    for( i = 1; i < pos; i++) // traverse list until user defined position is hit
    {
      	tmp = tmp->next;
    }
    // the next 2 lines places the new p node in between the provided location
    p->next = tmp->next; // make next node of tmp point to p
    tmp->next = p; // make p point to next node of tmp
    L->len++; // increment length
  }
}


// optional
void insertBefore( struct lheader *L, int val, struct lnode *p )
{
  struct lnode *tmp;
  int pos, i;

  printf("Insert before which node? (1-%d)\n ", L->len ); // before node
  scanf( "%d", &pos );
  if ( L->start == NULL ) // if nothing in the list make start point to p
  {
    L->start = p; // make start point to the new node
    L->len++; // increment length
  }
  else
  {
    tmp = L->start; // make tmp point to 1st node
    for( i = 1; i < pos-1; i++) // traverse list until 1 before user defined position is hit
    {
      	tmp = tmp->next;
    }
    // the next 2 lines places the new p node in between the provided location
    p->next = tmp->next; // make next node of tmp point to p
    tmp->next = p; // make p point to next node of tmp
    L->len++; // increment length
  }
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

