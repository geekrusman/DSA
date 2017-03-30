#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct ll {
	char data;
	struct ll *next;
};

typedef struct ll ll;

ll*
list_add(ll *list, char ch)
{
	ll* newnode = (ll*)malloc(sizeof(ll*));
	assert(newnode);

	newnode->data = ch;
	newnode->next = list;
	list =  newnode;
	return list;
}

ll*
list_top_del(ll *list)
{
	ll *temp = list;

	if (list == NULL)
		return NULL;
	if (list->next  == NULL)
	{
		if (list->data != '(' && list->data != ')')
			printf("%c", list->data);
		free(list);
		list = NULL;
		return list;
	}

	list = list->next;
	temp->next = NULL;
	if( temp->data != '(' && temp->data != ')')
		printf("%c", temp->data);
	free(temp);
	return list;
}

char
list_top(ll *list)
{
	if (list == NULL)
		return '\0';
	return list->data;
}


int
get_pre(char ch)
{
	int pre = 0;

	if (ch == '\0')
		pre = -1;
	if (ch == ')')
		pre = 0;
	if (ch == '+' || ch == '-')
		pre = 2;
	if (ch == '*' || ch == '/')
		pre = 3;
	if (ch == '(')
		pre = 1;

	return pre;
}

void
print_list(ll *list)
{
	if (list == NULL)
	{
		printf("NULL");
		return;
	}
	while (list->next != NULL)
	{
		if (list->data != '(' && list->data != ')')
			printf("%c", list->data);
		list = list->next;
	}
	if (list->data != '(' && list->data != ')')
		printf("%c", list->data);
}

char*
postorder(char *str)
{
	char *post = NULL;
	int size = strlen(str);
	ll *list = NULL;
	int itr = 0;

	post = (char*)malloc(sizeof(char)*size);

	for (; itr < size; itr++)
	{
		//printf("\nEvery Itrer\n");
		//print_list(list);
		//printf("\nDone\n\n\n");
		if ((str[itr] >= 65 && str[itr] <= 90) ||
		    (str[itr] >= 97 && str[itr] <= 122))
		{
			printf("%c", str[itr]);
		} else if (str[itr] == '+' || str[itr] == '-' || str[itr] == '*'
		    || str[itr] == '/' || str[itr] == '(' || str[itr] == ')' ) {
			
			char ch = list_top(list);
			int pre1 = 0;
			int pre2 = 0;

			pre1 = get_pre(str[itr]);
			pre2 = get_pre(ch);

			if (str[itr] == '(')
				list = list_add(list, str[itr]);
			else if (pre1 > pre2 || ch == '(')
			{
				list = list_add(list, str[itr]);
			} else {
				do {
					list = list_top_del(list);
					ch = list_top(list);
					if (ch == '(')
					{
						list = list_top_del(list);
						break;
					}
					pre2 = get_pre(ch);

				} while ( pre1 <= pre2);
				if (str[itr] != ')')
					list = list_add(list, str[itr]);
			}
				
		}
	}
	print_list(list);
	return NULL;
}

int main()
{
	char *str = "A+B+C+D";
	char *post = NULL;
	ll *list = NULL;

	list = list_add(list, 'a');
	list = list_add(list, 'b');
	//assert(list != NULL);
	//printf("%c", list->data);
	//print_list(list);
	//printf("\n");
	//list = list_top_del(list);
	//printf("\n");
	//print_list(list);
	post = postorder(str);
	printf("\n");
}
