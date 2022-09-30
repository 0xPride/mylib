#include "list.h"
#include <stdlib.h>

mylib_list_node *mylib_list_node_create(void *content)
{
	mylib_list_node *node;

	node = calloc(1, sizeof(mylib_list_node));
	if (!node)
		return 0;
	node->content = content;
	node->next = 0;
	return node;
}

mylib_list *mylib_list_create(mylib_list_node *node_nullable)
{
	mylib_list *list;

	list = calloc(1, sizeof(mylib_list));
	if (!list)
		return 0;
	list->head = node_nullable;
	list->tail = node_nullable;
	list->len = 0;
	if (node_nullable)
		list->len = 1;
	return (list);
}
