#ifndef MY_LIB_LINKED_LIST_H
#define MY_LIB_LINKED_LIST_H

#include "mylib/types.h"

mylib_list_node *mylib_list_node_create(void *);
mylib_list      *mylib_list_create(mylib_list_node *);
mylib_list_node *mylib_list_add_front(mylib_list *, mylib_list_node *);
mylib_list_node *mylib_list_add_back(mylib_list *, mylib_list_node *);
/**
 * return the inserted node on success otherwise return null
 */
mylib_list_node *mylib_list_add_at(mylib_list *, mylib_list_node *, size_t);
/**
 * if function if return 1 that means a match otherwise it will continue to search
 */
mylib_list_node *mylib_list_search(mylib_list *, mylib_list_node *, int (*f)(void *));
mylib_list_node *mylib_list_at(mylib_list *, size_t);
#endif
