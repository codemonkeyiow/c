#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node* create_node(int);
void push(int, struct Node**);
void push_end(int, struct Node*);
int pop(struct Node**);
void print_list(struct Node*);
void bubble_sort(struct Node*);
struct Node* insertion_sort(struct Node*);
void delete_list(struct Node*);

int main() {
    struct Node* list = create_node(11);
    print_list(list);

    push(12, &list);
    push(32, &list);
    push(-423, &list);
    push(182534, &list);
    push(32485790, &list);
    push(9, &list);
    print_list(list);

    int v = pop(&list);
    print_list(list);

    bubble_sort(list);
    print_list(list);

    // delete_list(list);
    // print_list(list);

    return 0;
}

struct Node* create_node(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    return n;
}

void push(int val, struct Node** list) {
    struct Node* n = create_node(val);
    n->next = *list;
    *list = n;
}

void push_end(int val, struct Node* list) {
    struct Node* n = create_node(val);

    while(list->next != NULL) {
        list = list->next;
    }

    list->next = n;
}

int pop(struct Node** list) {
    int v = (*list)->val;
    struct Node* n = *list;
    *list = (*list)->next;
    free(n);
    return v;
}

void print_list(struct Node* list) {
    while (list != NULL) {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("NULL\n");
}

void bubble_sort(struct Node* list) {
    if (list == NULL) return;

    bool sorted = false;
    struct Node* node;

    while(!sorted) {
        sorted = true;
        node = list;
        while (node->next != NULL) {
            if (node->val > node->next->val) {
                sorted = false;
                int v = node->val;
                node->val = node->next->val;
                node->next->val = v;
            }
            node = node->next;
        }
    }
}

struct Node* insertion_sort(struct Node* list) {
    struct Node* sorted_list = malloc(sizeof(struct Node));

    return sorted_list;
}

void delete_list(struct Node* list) {
    struct Node* n;

    while(list != NULL) {
        n = list;
        list = list->next;
        free(n);
    }
}

