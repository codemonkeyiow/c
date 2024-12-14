#include <stdio.h>

enum { row = 2, col = 3 };

void print_2d(int arr[][col], size_t row) {
  for(size_t x = 0; x < row; x++) {
    for(size_t y = 0; y < col; y++) {
      printf("%d ", arr[row][col]);
    }
    putchar('\n');
  }
}

int main() {
  int array[row][col] = {
  {4,5,6},
  {7,8,9}
  };
  print_2d(array, row);

  return 0;
}
