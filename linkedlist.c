#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(int argc, char *argv[])
{
	node *n = create_node(10);
	printf("%d\n", n->value);

	free(n);


	return 0;
}

node *create_node(const int value)
{
	node *node = malloc(sizeof(node));
	assert(node != NULL);
	node->value = value;
	node->next = NULL;

	return node;
}

linked_list *create_list(void)
{
	linked_list *list = malloc(sizeof(linked_list));
	assert(list != NULL);
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}
