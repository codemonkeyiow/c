#include <stdio.h>

void foo(int* f);

int main()
{
	int i = 10;
	foo(&i);
	printf("%d\n", i);

	return 0;
}


void foo(int* f)
{
	++*f;
	printf("%d\n", *f);
}
