#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cool.h"
#include "quicksort.h"
#include "linkedlist.h"

struct SF {
  int x;
};

void foo(int* x) {
  *x += 5;
}

void bar(int** x) {
  **x += 5;
}

void sfoo(struct SF* sf) {
  sf->x += 5;
}

void psfoo(struct SF** sf) {
  (*sf)->x += 5;
}

int main() {
  int x = 5;
  foo(&x);
  printf("%d\n", x);
  int* px = &x;
  bar(&px);
  printf("%d\n", x);

  struct SF sf;
  sf.x = 1;
  struct SF* psf = &sf;
  sfoo(&sf);
  printf("%d %d\n", sf.x, psf->x);
  psfoo(&psf);
  printf("%d %d\n", sf.x, psf->x);

  struct SF* innit = malloc(sizeof(struct SF));
  innit->x = 22;
  sfoo(innit);
  printf("%d\n", innit->x);
  psfoo(&innit);
  printf("%d\n", innit->x);


	return 0;
}
