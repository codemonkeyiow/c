#include <stdio.h>
#include <locale.h>

#ifndef __STDC_ISO_10646__
#error "Wide characters are not Unicode endpoints"
#endif

#define KBLU "\x1B[34m"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	for (int i = 0; i < 0xffff; i++) {
		printf("%s%lc ", KBLU, i);
	}

	return 0;
}
