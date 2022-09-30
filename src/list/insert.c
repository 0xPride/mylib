#include "list.h"

mylib_list_node *mylib_list_add_front(mylib_list *list, mylib_list_node *node)
{
	if (!node || !list)
		return 0;
	if (list->len == 0)
	{
		list->head = node;
		list->tail = node;
		list->len++;
		return node;
	}
	node->next = list->head;
	list->head = node;
	list->len++;
	return (node);
}

mylib_list_node *mylib_list_add_back(mylib_list *list, mylib_list_node *node)
{
	if (!node || !list)
		return 0;
	if (list->len == 0)
	{
		list->head = node;
		list->tail = node;
		list->len++;
		return node;
	}
	list->tail->next = node;
	list->tail = node;
	list->len++;
	return node;
}

mylib_list_node *mylib_list_add_at(mylib_list *list, mylib_list_node *node, size_t idx)
{
	mylib_list_node *current;
	mylib_list_node *prev;

	if (!list || !node || idx >= list->len)
		return 0;
	prev = 0;
	current = list->head;
	for (size_t i = 0; i < idx; i++)
	{
		prev = current;
		current = current->next;
	}
	node->next = current;
	prev->next = node;
	list->len++;
	return node;
}
