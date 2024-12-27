#include "doublelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
  Node* prev;
	Node* next;
};

void printList(Node* list) {
  while(list != NULL) {
    printf("%d -> ", list->value);
    list = list->next;
  }
  putchar('NULL\n');
}

void deleteList(Node* list) {
  Node* head;
  while(list != NULL) {
    head = list;
    list = list->next;
    free(head);
  }
}

Node* createNode(int value) {
  Node* node = (Node*) malloc(sizeof(Node));
  if(!node) {
    printf("ERROR: createNode\n");
    return NULL;
  }
  node->value = value;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void push(Node** head, int value) {
  Node* node = createNode(value);
  node->next = head;
  *head = node;
}

void pushEnd(Node** tail, int value) {
  Node* node = createNode(value);
  node->prev = tail;
  *tail = node;
}

int pop(Node* head) {
  int value = head->value;
  Node* node = head;
  head = head->next;
  free(node);
  return value;
}

int popEnd(Node* tail) {
  int value = tail->value;
  Node* node = tail->prev;
  tail = tail->prev;
  free(node);
  return value;
}
