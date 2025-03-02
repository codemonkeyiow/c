#include <stdlib.h>
#include <stdio.h>

struct B {
    int i;
    int j;
};

struct A {
    int num_b;
    struct B **b;
};

int main() {
    struct A *a = malloc(sizeof(struct A));
    a->num_b = 10;
    a->b = (struct B**) malloc(sizeof(struct B*) * a->num_b);

    for(int i = 0; i < a->num_b; i++) {
        a->b[i] = (struct B*) malloc(sizeof(struct B));
        a->b[i]->i = i;
        a->b[i]->j = i * i;
    }

    for(int i = 0; i < a->num_b; i++) {
        printf("%d %d\n", a->b[i]->i, a->b[i]->j);
    }

    return 0;
}
