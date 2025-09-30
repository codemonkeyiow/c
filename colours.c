#include <stdio.h>
#include "colours.h"

int main() {
	set_colour(FG_RED);
	printf("Yo\n");
	bold();
	set_colour(FG_GREEN);
	printf("Yo\n");
	italic();
	set_colour(FG_BLUE);
	printf("Yo\n");
	reset_colour();
	set_colour(BG_RED);
	set_colour(FG_BLUE);
	italic();
	printf("Yo\n");

	reset_colour();
	return 0;
}
