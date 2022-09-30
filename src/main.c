#include "list.h"
#include <stdio.h>

int main()
{
	mylib_list *list;

	list = mylib_list_create(mylib_list_node_create(0));
	printf("%p\n", list);
	printf("%p\n", list->head);
	printf("%p\n", list->tail);
	printf("%zu\n", list->len);
	return 0;
}
