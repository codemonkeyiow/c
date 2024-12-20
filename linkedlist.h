#pragma once

typedef struct ListNode ListNode;

void printList(ListNode*);
ListNode* createNode(int value);
void pushEnd(ListNode*, int);
ListNode* push(ListNode*, int);
void pushP(ListNode**, int);
int pop(ListNode*);
int popP(ListNode**);
