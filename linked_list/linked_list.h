#pragma once

struct sll_node {
	int data;
	struct ll_node *next;
};

typedef struct sll_node sll_node;

struct sll_list {
	sll_node *head;
};

typedef struct sll_list sll_list;

//init
sll_list*
sll_init();

//insert at end
sll_list*
sll_insert_end(sll_list* , int );

//delete
sll_list*
sll_delete_at(sll_list*, int );

//reverse
sll_list*
sll_reverse(sll_list* );
