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

sll_node*
sll_reverse_knodes(sll_node **head, int k)
{
	assert(head);
	sll_node *t1 = NULL;
	sll_node *t2 = NULL;
	sll_node *prev_head = *head;
	int cnt = 0;
	
	do {
		t2 = (*head)->next;
		if (t2 == NULL ) {
			(*head)->next = t1;
			break;
		}
		if (cnt == k-1) {
			(*head)->next = t1;
			prev_head->next = sll_reverse_knodes(&t2, k);
			break;
		}
		(*head)->next = t1;
		t1 = *head;
		*head = t2;
		cnt++;

	} while (t2 != NULL);
	return *head;
}

sll_list*
sll_reverse_knodes_list(sll_list *list, int k)
{
	assert(list);
	sll_node *t1 = NULL;
	sll_node *t2 = NULL;
	sll_node *prev_head = list->head;
	int cnt = 0;
	
	assert(k>=0);
	if ( k == 0 | k == 1 )
		return list;
	
	list->head = sll_reverse_knodes(&list->head, k);
	return list;

}

int
sll_size(sll_list *list)
{
	if (list == NULL || list->head == NULL)
		return 0;
	sll_node *temp = list->head;
	int size = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return size;
}

sll_list*
sll_rotate_k(sll_list *list, int k)
{
	assert(k >= 0);
	int cnt = 0;
	int size = 0;
	sll_node *temp = NULL;
	sll_node *temp2 = NULL;
	sll_node *temp3 = NULL;

	if (list == NULL || list->head == NULL || k == 0)
		return list;

	size = sll_size(list);

	if (k >= size)
		return list;

	temp = list->head;

	while (cnt < k-1)
	{
		cnt++;
		temp = temp->next;
	}

	temp2 = temp->next;
	temp->next = NULL;

	temp3 = temp2;

	while (temp3->next != NULL)
	{
		temp3 = temp3->next;
	}
	temp3->next = list->head;
	list->head = temp2;

	return list;
}
