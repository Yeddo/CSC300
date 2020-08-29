#include "lla.h"

int main()
{
	struct lheader *L;
	struct lnode *tmp;
	int i, x;

	L = makelist();

	insertFront( L, 789 );
	printer( L );

//	return 0;

	for (i = 0; i < 5; ++i)
	{
		x = rand() % 25 + 1;
		printf("-- Adding -- %d\n", x);
		insertFront( L, x );
		insertBack( L, x );
		printer( L );
	}
//	return 0;

	for ( i = 0; i < 6; i++ )
	{
		x = removeFront( L );
		printf("out goes %d\n", x);
		printer(L);
	}

//	return 0;
	printf(">>>>Value to search: ");
	scanf("%d", &x);
	i = isInList(L, x);
	printf("I is %d\n", i);
	tmp = findNode(L, x);
	if (tmp == NULL) 
		printf("NOPE\n");
	else  
		printf("Found node %d\n", tmp->data);

	// figure out insertBefore and insertAfter

	return 0;
}
