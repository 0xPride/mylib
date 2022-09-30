#include "list.h"

mylib_list_node *mylib_list_search(mylib_list *list, mylib_list_node *node, int (*f)(void *))
{
	mylib_list_node *current;

	if (!list || !node || !f)
		return 0;
	current = list->head;
	while (current)
	{
		if (f(current->content) == 1)
			return current;
		current = current->next;
	}
	return 0;
}
