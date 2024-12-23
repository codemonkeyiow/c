#include "quicksort.h"
#include <stdbool.h>

void swap(char* x, char* y) {
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void sort(char array[], int length) {
	bool sorted = false;
	while(!sorted) {
		sorted = true;
		for (int i = 1; i < length; i++) {
			if (array[i] < array[i - 1]) {
				swap(&array[i], &array[i - 1]);
				sorted = false;
			}
		}
	};
}
