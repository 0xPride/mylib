#ifndef MY_LIB_TYPES
#define MY_LIB_TYPES

#include <stddef.h>

typedef enum _mylib_bool
{
	false,
	true,
} mylib_bool;

typedef struct _mylib_list_node
{
	void	                *content;
	struct _mylib_list_node *next;
} mylib_list_node;

typedef struct _mylib_list
{
	mylib_list_node *head;
	mylib_list_node *tail;
	size_t           len;
} mylib_list;

#endif
