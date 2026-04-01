#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    int age;
    char name[MAX_NAME];
} Person;

Person *hash_table [TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash = 0;
    for(int i = 0; i < length; i++) {
        hash += name[i];
        hash *= name[i];
    }
    return hash % TABLE_SIZE;
}

void init_hash_table()
{
    for(int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_hash_table()
{
    printf("\nIndex\t->\tName\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(hash_table[i] == NULL) {
            printf("%d\t->\t---\n", i);
        } else {
            printf("%d\t->\t%s\n", i, hash_table[i]->name);
        }

    }
}

bool hash_table_insert(Person *p)
{
    if(p == NULL) return false;
    int index = hash(p->name);
    if(hash_table[index] != NULL) {
        printf("Collision! %s %i\n", p->name, index);
        return false;
    }
    hash_table[index] = p;
    return true;
}

Person *hash_table_lookup(char *name)
{
    int index = hash(name);
    if(hash_table[index] == NULL) return NULL;
    if(strncmp(hash_table[index]->name, name, MAX_NAME) != 0) return NULL;
    return hash_table[index];
}

Person *hash_table_delete(char *name)
{
    int index = hash(name);
    if(hash_table[index] == NULL) return NULL;
    if(strncmp(hash_table[index]->name, name, MAX_NAME) != 0) return NULL;
    Person *p = hash_table[index];
    hash_table[index] = NULL;
    return p;
}

int main()
{
    init_hash_table();
    print_hash_table();

    Person bob = {.name="Bob", .age=33};
    Person akira = {.name="Akira", .age=999};
    Person sakamoto = {.name="Sakamoto", .age=3};
    Person dan = {.name="Dan", .age=38};
    hash_table_insert(&bob);
    hash_table_insert(&akira);
    hash_table_insert(&sakamoto);
    hash_table_insert(&dan);
    print_hash_table();

    Person *p = hash_table_lookup("Akira");
    if(p==NULL) {
        printf("Not found\n");
    } else {
        printf("%i\t%s\n", hash(p->name), p->name);
    }

    p = hash_table_lookup("asdf");
    if(p==NULL) {
        printf("Not found\n");
    } else {
        printf("%i\t%s\n", hash(p->name), p->name);
    }

    hash_table_delete("Sakamoto");
    print_hash_table();

    printf("abcdef\n" + 2);

    return 0;
}
