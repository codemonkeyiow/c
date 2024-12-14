#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int value;
	ListNode* next;
};

void printList(ListNode *list) {
  while(list != NULL) {
    printf("%d ", list->value);
    list = list->next;
  }
  putchar('\n');
}

ListNode* createNode(int value) {
  ListNode *node = (ListNode*) malloc(sizeof(ListNode));
  if (!node) {
    printf("ERROR: createNode failed\n");
    return NULL;
  }
  node->value = value;
  node->next = NULL;
  return node;
}

void pushEnd(ListNode *list, int value) {
  ListNode *node = createNode(value);
  // traverse to the end
  while(list->next != NULL) {
    list = list->next;
  }
  list->next = node;
}

void push(ListNode **list, int value) {
  ListNode *node = createNode(value);
  node->next = *list;
  *list = node;
}

int pop(ListNode **list) {
  int value = (*list)->value;

  ListNode *head = *list;
  *list = (*list)->next;

  free(head);

  return value;
}

int main() {
  ListNode *list = (ListNode*) malloc(sizeof(ListNode));
  printList(list);
  push(&list, 5);
  push(&list, 15);
  printList(list);
  int p = pop(&list);
  printf("%d\n", p);
  printList(list);
  return 0;
}
