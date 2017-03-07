#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
	int itr = 0;
	sll_list *mylist = sll_init();
	
	for ( itr = 0; itr < 10; itr++) {
		mylist = sll_insert_end(mylist, itr);
	}
	
	sll_printall(mylist);

	mylist = sll_delete_at(mylist, 9);
	sll_printall(mylist);

	mylist = sll_reverse(mylist);
	sll_printall(mylist);
}

