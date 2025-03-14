#include <stdlib.h>
#include <stdio.h>

struct B {
    int j;
};

struct A {
    int i;
    struct B *b;
    // struct B **bp;
};

void write_file() {
    FILE *file;
    file = fopen("file_byte_stream.out", "w");

    struct A *a = (struct A*) malloc(sizeof(struct A));
    a->i = 10;
    a->b = (struct B*) malloc(sizeof(struct B));
    a->b->j = 12;

    size_t written = fwrite(a, sizeof(struct A), 1, file);
    printf("%d\n", written);

    fclose(file);
}

void read_file() {
    FILE *file;
    file = fopen("file_byte_stream.out", "r");

    struct A *a = (struct A*) malloc(sizeof(struct A));

    size_t read = fread(a, sizeof(struct A), 1, file);
    printf("%d %d %d\n", read, a->i, a->b->j);

    fclose(file);
}

int main() {
    write_file();
    read_file();

    return 0;
}
