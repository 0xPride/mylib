#include "list.h"
#include <stdio.h>
#include <string.h>

int f(void *s)
{
	if (strcmp(s, "3") == 0)
		return 1;
	return 0;
}

int main()
{
	mylib_list *list;

	list = mylib_list_create(mylib_list_node_create(strdup("1")));
	mylib_list_add_front(list, mylib_list_node_create(strdup("0")));
	mylib_list_add_back(list, mylib_list_node_create(strdup("2")));
	mylib_list_add_back(list, mylib_list_node_create(strdup("4")));
	mylib_list_add_at(list, mylib_list_node_create("3"), 3);
	// mylib_list_node *current = list->head;
	// for (size_t i = 0; i < list->len; i++)
	// {
	// 	printf("%s -> ", current->content);
	// 	current = current->next;
	// }
	printf("%s", mylib_list_search(list, f)->content);
	printf("\n");
	return 0;
}
