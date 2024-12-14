#pragma once

typedef struct ListNode ListNode;

void printList(ListNode*);
ListNode* createNode(int value);
void pushEnd(ListNode*, int);
void push(ListNode**, int);
int pop(ListNode**);

