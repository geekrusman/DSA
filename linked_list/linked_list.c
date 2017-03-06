#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <linked_list.h>

//sll init
sll_list*
sll_init()
{
	sll_list *list = (sll_list)malloc(sizeof(sll_list*));
	assert(list, "memory failure");

	list->head = NULL;
	return list;
}

sll_list*
sll_insert_end(sll_list *list, int data)
{
	assert(list);

	//initiate the sll_node
	sll_node *node = (sll_node*)malloc(sizeof(sll_node));
	assert(node, "memory failure");
	node->data = data;
	node->next = NULL;

	//empty case
	if (list->head == NULL) {
		list->head = node;
		return list;
	}	

	//non empty case
	sll_node *ptr = list->head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next  = node;
	return list;
}

sll_list*
sll_delete_at(sll_list *list, int index)
{
	assert(list);
	assert(index>=0, "Index should be greated than 0");
	int cnt = 0;
	
	//empty case
	if (list->head == NULL) {
		printf("\nList is empty.Can't Delete\n");
		return list;
	}

	//non empty case
	sll_node *ptr = list->head;
	while (cnt < index-1) {
		ptr = ptr->next;
		cnt++;
	}
	sll_node *temp = ptr->next;
	
	ptr->next = temp->next;
	free(temp);
	printf("Deleted index %d", index);
	return list;		
}

