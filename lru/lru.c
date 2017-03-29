#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct dll{
	int data;
	struct dll *prev;
	struct dll *next;
};

typedef struct dll dll; 

struct hash {
	int size;
	dll** arr;
};

typedef struct hash hash;

dll*
dll_add(dll* list, int data)
{
	dll *newnode = (dll*)malloc(sizeof(dll));
	assert(newnode);
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	dll *trav = list;

	if (list == NULL)
	{
		list = newnode;
		return list;
	}
/*
	while (trav->next != NULL)
	{
		trav = trav->next;
	}
	trav->next = newnode;
	newnode->prev = trav;
*/
	newnode->next  = list;
	list->prev = newnode;
	list = newnode;
	return list;
}

dll*
dll_del_last(dll* list)
{
	dll *trav = list;
	dll *temp = NULL;
	if (list == NULL)
		return list;

	if (trav->next == NULL)
	{
		free(trav);
		return NULL;
	}

	while(trav->next->next != NULL)
	{
		trav = trav->next;
	}

	temp = trav->next;
	trav->next  = NULL;
	free(temp);
	return list;
}

hash*
hash_init(int size)
{
	hash *Hash = (hash*)malloc(sizeof(hash));
	assert(Hash);
	Hash->size = size;
	Hash->arr = (dll**)malloc(size * sizeof(dll*));
	int itr = 0;

	for (; itr < size; itr++)
	{
		Hash->arr[itr] = NULL;
	}
	return Hash;
}

hash*
hash_add(hash *Hash, int page, dll *ptrnode)
{
	Hash->arr[page] = ptrnode;
	return Hash;
}

int
dll_size(dll *list)
{
	dll *trav = list;
	int cnt = 1;

	if (list == NULL)
		return 0;
	while (trav->next != NULL)
	{
		trav = trav->next;
		cnt++;
	}
	return cnt;
}

int
dll_last(dll *list)
{
	dll *trav = list;

	if (list == NULL)
		return -1;

	while (trav->next != NULL)
		trav = trav->next;

	return trav->data;
}

dll*
rearrange_list(dll* list, dll *node)
{
	assert(list);
	assert(node);
	dll *prevnode = NULL;
	dll *nextnode  = NULL;
	
	prevnode = node->prev;
	nextnode = node->next;

	if (list == node)
		return list;	
	if (prevnode != NULL)
		prevnode->next  = nextnode;
	if (nextnode != NULL)
		nextnode->prev = prevnode;

	node->prev = NULL;
	node->next = list;

	list = node;
	return list;
}

void
print_list(dll *list)
{
	dll *trav = list;

	if (list == NULL)
		return;

	while (trav->next != NULL)
	{
		printf("%d-->", trav->data);
		trav = trav->next;
	}
	printf("%d-->NULL\n", trav->data);
}

int main()
{
	int c_size = 0, p_size = 0;
	dll *list = NULL;
	dll *get_last = NULL;
	hash *Hash = NULL;
	int l_size = 0;

	printf("Enter the size of cache : ");
	scanf("%d", &c_size);
	printf("Enter the no of pages : ");
	scanf("%d", &p_size);

	Hash = hash_init(p_size);
	// 1,2,3,4,5,6,7

	int page_num[] = {0, 1, 2, 3, 4, 0, 0, 6, 7};
	int itr = 0;
	int get_last_pno = 0;

	for (; itr < 9; itr++)
	{
		print_list(list);
		if (Hash->arr[page_num[itr]] == NULL)
		{
			printf("Check 1 %d \n", page_num[itr]);
			l_size = dll_size(list);
			if (l_size < c_size)
			{
				printf("Check_3 %d\n", page_num[itr]);
				list = dll_add(list, page_num[itr]);
				//get_last = dll_last(list);
				Hash = hash_add(Hash, page_num[itr], list);
			} else if (l_size == c_size) {
				
				get_last_pno = dll_last(list);
				Hash->arr[get_last_pno] = NULL;
				list = dll_del_last(list);

				list = dll_add(list, page_num[itr]);
				//get_last = dll_last(list);
				Hash = hash_add(Hash, page_num[itr], list);
			}
		} else {
			printf("Check 2 %d \n", page_num[itr]);
			list = rearrange_list(list, Hash->arr[page_num[itr]]);
			Hash = hash_add(Hash, page_num[itr], list);
		}
	}

	print_list(list);
}




