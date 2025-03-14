#include <stdlib.h>
#include <stdio.h>

struct B {
    int j;
};

struct A {
    int num_bp;
    struct B *b;
    struct B **bp;
};

void write_file(int num_bp) {
    FILE *file;
    file = fopen("file_byte_stream.out", "w");

    struct A *a = (struct A*) malloc(sizeof(struct A));
    a->num_bp = num_bp;

    a->b = (struct B*) malloc(sizeof(struct B));
    a->b->j = 12;

    a->bp = (struct B**) malloc(num_bp * sizeof(struct B*));
    for(int i = 0; i < num_bp; i++) {
        a->bp[i] = (struct B*) malloc(sizeof(struct B));
        a->bp[i]->j = i * i;
    }

    size_t written = fwrite(a, sizeof(struct A), 1, file);
    printf("%d\n", written);

    fclose(file);
}

void read_file() {
    FILE *file;
    file = fopen("file_byte_stream.out", "r");

    struct A *a = (struct A*) malloc(sizeof(struct A));

    size_t read = fread(a, sizeof(struct A), 1, file);
    printf("%d %d %d\n", read, a->num_bp, a->b->j);

    for(int i = 0; i < a->num_bp; i++) {
        printf("%d ", a->bp[i]->j);
    }
    putchar('\n');

    fclose(file);
}

int main() {
    write_file(6);
    read_file();

    return 0;
}
