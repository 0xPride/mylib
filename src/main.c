#include "list.h"
#include <stdio.h>
#include <string.h>

int main()
{
	mylib_list *list;

	list = mylib_list_create(mylib_list_node_create(strdup("1")));
	mylib_list_add_front(list, mylib_list_node_create(strdup("0")));
	mylib_list_add_back(list, mylib_list_node_create(strdup("2")));
	mylib_list_add_back(list, mylib_list_node_create(strdup("4")));
	mylib_list_add_at(list, mylib_list_node_create("3"), 30);
	mylib_list_node *current = list->head;
	for (size_t i = 0; i < list->len; i++)
	{
		printf("%s -> ", current->content);
		current = current->next;
	}
	printf("\n");
	return 0;
}
