#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cool.h"
#include "quicksort.h"
#include "linkedlist.h"


int main() {
  int x = 10;
  int l = intlength(x);
  char str[l+1];
  sprintf(str, "%d", x);
  printf("%d %s\n", l, str);
  int i = 0, j = l - 1;
  while(i < l/2, j >= l/2) {
    printf("%d %d\n", str[i] - '0', str[j] - '0');
    if(str[i] != str[j]) {
      printf("mismatch\n");
    }
    i++;
    j--;
  }
	return 0;
}
