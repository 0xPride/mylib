#include "list.h"

mylib_list_node *mylib_list_at(mylib_list *list, size_t idx)
{
	mylib_list_node *current;

	if (!list || idx >= list->len)
		return 0;
	current = list->head;
	for (size_t i = 0; i < idx; i++)
		current = current->next;
	return current;
}
