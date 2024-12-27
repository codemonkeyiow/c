#pragma once

typedef struct Node Node;

void printList(Node*);
void deleteList(Node*);
Node* createNode(int value);
void push(Node**, int);
void pushEnd(Node**, int);
int pop(Node*);
int popEnd(Node*);
