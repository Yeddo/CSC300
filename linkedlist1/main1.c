#include "lla.h"

int main()
{
	struct lheader *L;
	struct lnode  *head, *tmp;
	struct lnode  *mark;
	int i, x;

	L = makelist();

	for (i = 0; i < 5; ++i)
	{
		x = rand() % 25 + 1;
		printf("-- Adding -- %d\n", x);
		insertFront( L, x );
		insertBack( L, x );
		printer( L );
	}

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
	printf(">>>>Value to search: ");
  	scanf("%d", &x);
	tmp = findNode(L, x);
	if (tmp == NULL) 
		printf("DOH!\n");
	else  
		insertBefore( L, 99, tmp );
  	printer( L );

	return 0;
}
