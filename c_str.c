#include <stdio.h>
#include <stdlib.h>

int main() {
    int str_len = 10;
    char* c_string = malloc(sizeof(char) * (str_len + 1));
    for(int i = 0; i < str_len; i++) {
        *(c_string + i) = i + 64;
    }
    *(c_string + str_len) = '\n';
    printf("%s\n", c_string);
    free(c_string);

    return 0;
}
