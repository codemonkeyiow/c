#include <stdlib.h>
#include <stdio.h>

struct B {
    int i;
    int j;
};

struct A {
    int num_b;
    struct B *b;
};

int main() {
    struct A *a = malloc(sizeof(struct A));
    a->num_b = 10;
    a->b = malloc(sizeof(struct B) * a->num_b);

    return 0;
}
