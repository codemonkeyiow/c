#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(int argc, char *argv[])
{
	LinkedList *list = create_list();
	push(5,list);
	print_list(list);
	push(15,list);
	push(25,list);
	print_list(list);
	bubble_sort(list);
	print_list(list);

	pop(list);
	pop(list);
	print_list(list);
	return 0;
}

Node *create_node(const int value)
{
	Node *const node = malloc(sizeof(Node));
	assert(node != NULL);
	node->value = value;
	node->next = NULL;
	return node;
}

LinkedList *create_list(void)
{
	LinkedList *list = malloc(sizeof(LinkedList));
	assert(list != NULL);
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

void push(const int value, LinkedList *list)
{
	Node *node = create_node(value);
	node->next = list->head;
	list->head = node;
	list->length++;
	printf("\n-Push List-\n %d list->length %d\n", node->value, list->length);
}

int pop(LinkedList *list)
{
	int value = list->head->value;

	Node *head = list->head;
	list->head = list->head->next;
	free(head);

	list->length--;

	printf("\n-Pop List-\n %d list->length %d\n", value, list->length);

	return value;
}

void print_list(LinkedList *list)
{
	if (list == NULL) return;
	printf("\n-Print List-\n");
	Node *node = list->head;
	int index = 0;
	while(node != NULL) {
		printf(" %d:\t%d\n", index, node->value);
		node = node->next;
		index++;
	}
}

void bubble_sort(LinkedList *list)
{
	if (list == NULL) return;

	bool sorted = false;
	Node *node;

	while (!sorted) {
		sorted = true;
		node = list->head;
		while (node->next != NULL) {
			if (node->value > node->next->value) {
				sorted = false;
				int v = node->value;
				node->value = node->next->value;
				node->next->value = v;
			}
			node = node->next;
		}
	}
}
