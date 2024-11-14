#include <stdio.h>
#include "cool.h"

int intlength(int i) {
  return snprintf(NULL, 0, "%d", i);
}
