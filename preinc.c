#include <stdio.h>

int main() {
	int i = 1;
	int j = 1;
	printf("%d %d\n", ++i, ++i);
	printf("%d %d\n", j++, j++);
	return 0;
}
