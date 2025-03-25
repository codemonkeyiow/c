#include <stdio.h>

enum Code {
  FG_RED    = 31,
  FG_GREEN  = 32,
  FG_YELLOW = 33,
  FG_BLUE   = 34,
};

void reset() {
  printf("\033[0m");
}

void set_color(int code) {
  printf("\033[%dm", code);
}

void bold() {
  printf("\033[1m");
}

void italic() {
  printf("\033[3m");
}

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
  set_color(FG_BLUE);
  italic();
  printf("Yo\n");
  
  reset();
  return 0;
}
