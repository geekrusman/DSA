#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ll {
	int data;
	struct ll *next;
};

typedef struct ll ll;

ll*
ll_add(ll *list, int data)
{
	ll *newnode = (ll*)malloc(sizeof(ll));
	assert(newnode);

	newnode->data = data;
	newnode->next = list;
	list = newnode;
	return list;
}

ll*
ll_rev(ll *list, ll *prev)
{
	ll *tnext = NULL;
	if (list == NULL)
		return NULL;
	if (list->next == NULL)
	{
		list->next = prev;
		return list;
	}
	tnext = list->next;
	list->next = prev;
	prev = list;
	list = ll_rev(tnext, prev);
	return list;
}

void
ll_print(ll *list)
{
	ll *trav = list;
	while (trav->next != NULL)
	{
		printf("%d\n", trav->data);
		trav = trav->next;
	}
	printf("%d\n==\n",trav->data);
}

int main()
{
	ll *list = NULL;

	list = ll_add(list, 1);
	list = ll_add(list, 2);
	list = ll_add(list, 3);

	printf("\nBefore\n");
	ll_print(list);
	list = ll_rev(list, NULL);
	printf("\nAfter\n");
	ll_print(list);
}
