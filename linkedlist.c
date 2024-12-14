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

int main() {
  ListNode *list = (ListNode*) malloc(sizeof(ListNode));
  printList(list);
  return 0;
}
