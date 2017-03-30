#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		return 0;
	return list->data;
}

int
eval_post_exp(char *str)
{
	int size = 0, itr = 0, res = 0;
	ll *list = NULL;
	if (str == NULL)
		return 0;
	int A = 1, B = 2, C = 3, D = 4;

	size = strlen(str);

	for (;itr < size; itr++)
	{
		if (str[itr] == 'A')
			list = ll_add(list, A);
		if (str[itr] == 'B')
			list = ll_add(list, B);
		if (str[itr] == 'C')
			list = ll_add(list, C);
		if (str[itr] == 'D')
			list = ll_add(list, D);

		if (str[itr] == '+' || str[itr] == '-' || str[itr] == '*'
		    || str[itr] == '/')
		{
			int op1 = 0, op2 = 0;
			op1 = ll_top(list);
			list = ll_top_del(list);
			op2 = ll_top(list);
			list = ll_top_del(list);

			if (str[itr] == '+')
				res = op1 + op2;
			if (str[itr] == '-')
				res = op1 - op2;
			if (str[itr] == '*')
				res = op1 * op2;
			if (str[itr] == '/')
				res = op1 / op2;

			list = ll_add(list, res);
		}

	}
	res = ll_top(list);
	return res;
}

int main()
{
	char *str = "AB+CD+*";
	int res = 0;

	res = eval_post_exp(str);
	printf("res %d", res);
}
