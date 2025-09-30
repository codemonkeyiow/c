#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int value;
	ListNode* next;
};

void printList(ListNode* list) {
  while(list != NULL) {
    printf("%d -> ", list->value);
    list = list->next;
  }
  printf("NULL\n");
}

void deleteList(ListNode* list) {
  ListNode* head;
  while(list != NULL) {
    head = list;
    list = list->next;
    free(head);
  }
}

ListNode* createNode(int value) {
  ListNode* node = (ListNode*) malloc(sizeof(ListNode));
  if (!node) {
    printf("ERROR: createNode failed\n");
    return NULL;
  }
  node->value = value;
  node->next = NULL;
  return node;
}

void pushEnd(ListNode* list, int value) {
  ListNode* node = createNode(value);
  // traverse to the end
  while(list->next != NULL) {
    list = list->next;
  }
  list->next = node;
}

void pushP(ListNode** list, int value) {
  ListNode* node = createNode(value);
  node->next = *list;
  *list = node;
}

ListNode* push(ListNode* list, int value) {
  ListNode* node = createNode(value);
  node->next = list;
  return node;
}

int popP(ListNode** list) {
  if(*list == NULL) {
    printf("WARNING: popping NULL list\n");
    return -1;
  }
  int value = (*list)->value;

  ListNode* head = *list;
  *list = (*list)->next;
  free(head);

  return value;
}

int pop(ListNode* list) {
  if(list == NULL) {
    printf("WARNING: popping NULL list\n");
    return -1;
  }
  int value = list->value;

  ListNode* head = list;
  list = list->next;
  free(head);

  return value;
}

int main() {
  ListNode* list = createNode(1);
  printList(list);
  pushP(&list, 2);
  list = push(list, 3);
  printList(list);
  int p = popP(&list);
  // int p = pop(list);
  printf("%d\n", p);
  printList(list);

  deleteList(list);

  return 0;
}
