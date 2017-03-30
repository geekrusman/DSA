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
ll_top_del(ll *list)
{
	ll *temp = list;
	if (list == NULL)
		return NULL;
	if (list->next == NULL)
	{
		free(list);
		list = NULL;
		return list;
	}

	list = list->next;
	temp->next = NULL;
	free(temp);
	return list;
}

int
ll_top(ll *list)
{
	if (list == NULL)
		return 99999;
	return list->data;
}

void
stock_span(int *price, int n)
{
	int *span = (int*)calloc(n ,sizeof(int));
	assert(span);
	int itr = 0;
	int top_ele = 0;
	ll *list = NULL;

	for (; itr < n; itr++)
	{
		top_ele = ll_top(list);
		if (price[itr] < top_ele)
		{
			list = ll_add(list, price[itr]);
			span[itr] = 1;
		} else {
			int index = 0;
			while (price[itr] >= top_ele)
			{
				list = ll_top_del(list);
				top_ele = ll_top(list);
				index++;
			}
			list = ll_add(list, price[itr]);
			int itr2 = 1;
			int cnt = 0;
			for( ; cnt < index ;cnt++ )
			{
				span[itr] = span[itr] + span[itr-itr2];
				itr2 = itr2 + span[itr-itr2];
			}
			span[itr] = span[itr] + 1;
		}
	}

	for (itr = 0; itr < n; itr++)
	{
		printf("%d ", span[itr]);
	}
	printf("\n");	
}

int main()
{
	int price[] = {100, 60 ,70, 65, 80, 85};
	stock_span(price, 6);
}
