#pragma once

typedef struct Node Node;

void printList(Node*);
void deleteList(Node*);
Node* createNode(int value);
void pushEnd(Node*, int);
Node* push(Node**, int);
int pop(Node**);
