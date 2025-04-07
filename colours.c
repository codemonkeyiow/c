#include <stdio.h>
#include "colours.h"

int main() {
  set_color(FG_RED);
  printf("Yo\n");
  bold();
  set_color(FG_GREEN);
  printf("Yo\n");
  italic();
  set_color(FG_BLUE);
  printf("Yo\n");
  reset();
  set_color(BG_RED);
  set_color(FG_BLUE);
  italic();
  printf("Yo\n");
  
  reset();
  return 0;
}
