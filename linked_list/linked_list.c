#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

//sll init
sll_list*
sll_init()
{
	sll_list *list = (sll_list*)malloc(sizeof(sll_list*));
	assert(list);

	list->head = NULL;
	return list;
}

/*
 * Input : single linked list, data
 * Creates a node at last and inserts
 * the given data in that node. 	
 */

sll_list*
sll_insert_end(sll_list *list, int data)
{
	assert(list);

	//initiate the sll_node
	sll_node *node = (sll_node*)malloc(sizeof(sll_node));
	assert(node);
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

/*
 * Input : SLL and index number to delete
 * If index is less than 0 (errors out)
 * If index is greater than the length of the
 * linked list, then the last node is deleted.
 */

sll_list*
sll_delete_at(sll_list *list, int index)
{
	assert(list);
	assert(index>=0);
	int cnt = 0;
	
	//empty case
	if (list->head == NULL) {
		printf("\nList is empty.Can't Delete\n");
		return list;
	}

	//non empty case
	sll_node *ptr = list->head;
	while (cnt < index-1 && ptr->next != NULL ) {
		ptr = ptr->next;
		cnt++;
	}
	sll_node *temp = ptr->next;
	
	if (temp == NULL)
		ptr->next = NULL;
	else {
		ptr->next = temp->next;
		free(temp);
	}
	printf("Deleted index %d\n", index);
	return list;		
}

void
sll_printall(sll_list *list)
{
	sll_node *ptr = list->head;
	
	while (ptr != NULL) {
		printf("%d--", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

sll_list*
sll_reverse(sll_list* list)
{
	assert(list);
	sll_node *t1 = NULL;
	sll_node *t2 = NULL;
	
	do {
		t2 = list->head->next;
		if (t2 == NULL) {
			list->head->next = t1;
			break;
		}
		list->head->next = t1;
		t1 = list->head;
		list->head = t2;
	} while (t2 != NULL);
	return list;
}
