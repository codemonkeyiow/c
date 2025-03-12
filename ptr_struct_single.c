#include <stdlib.h>
#include <stdio.h>

struct B {
    int i;
    int j;
};

struct A {
    struct B *b;
};

int main() {
    struct A *a = malloc(sizeof(struct A));
    a->b = malloc(sizeof(struct B));
    a->b->i = 10;

    return 0;
}
