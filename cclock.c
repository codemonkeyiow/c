#include <stdio.h>
#include <time.h>
#include "raylib.h"

#define WIDTH 800
#define HEIGHT 600

time_t current_time;
char *time_string;

void update_time()
{
	current_time = time(NULL);
	time_string = ctime(&current_time);
}

int main(int argc, char *argv[])
{
	update_time();

	InitWindow(WIDTH, HEIGHT, "Clock In Hand");
	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawText(time_string, 0, 0, 20, RED);

		int count = 6;
		Vector2 a = (Vector2){WIDTH/2 - 20, HEIGHT/2}; // CL
		Vector2 b = (Vector2){WIDTH/2 - 10, HEIGHT/2 - 10}; // TL
		Vector2 c = (Vector2){WIDTH/2 - 10, HEIGHT/2 + 10}; // BL
		Vector2 d = (Vector2){WIDTH/2 + 10, HEIGHT/2 - 10}; // TR
		Vector2 e = (Vector2){WIDTH/2 + 10, HEIGHT/2 + 10}; // BR
		Vector2 f = (Vector2){WIDTH/2 + 20, HEIGHT/2}; // CR
		printf("%f,%f %f,%f %f,%f \n", d.x, d.y, e.x, e.y, f.x, f.y);

		Vector2 points[] = {b,a,c,e,f,d};
		// DrawTriangleStrip(points, count, RED);
		DrawTriangleFan(points, count, RED);

		EndDrawing();
		update_time();
	}

	CloseWindow();
	printf("Yo %s\n", time_string);
	return 0;
}
