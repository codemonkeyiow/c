#include <stdio.h>

int main()
{
	int x = 5, y = 7;

	x = x + y;
	y = x - y;
	x = x - y;

	printf("%d %d\n", x, y);

	int *px = &x, *py = &y;

	printf("%d %d\n", *px, *py);

	px = py;
	printf("%d %d\n", *px, *py);

	return 0;
}
