#pragma once

typedef struct node {
	int value;
	struct node *next;
} node;

typedef struct linked_list {
	node *head;
	node *tail;
	size_t length;
} linked_list;

node *create_node(const int value);
linked_list *create_list(void);
