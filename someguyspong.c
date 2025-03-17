#include <ncurses.h>
#include <unistd.h>

#define HEIGHT 15
#define WIDTH  50

#define BALL_SPEED 100000

// gcc someguyspong.c -lncurses
int main() {
    int gameover = 0;

    int player1_y = 6;
    int player2_y = 6;

    int player1_score = 0;
    int player2_score = 0;

    int ball_x = (WIDTH + 1)  / 2;
    int ball_y = (HEIGHT + 1) / 2;

    int ball_x_velocity = 1;
    int ball_y_velocity = 1;

    initscr();
    nodelay(stdscr, 1);
    keypad(stdscr, 1);
    curs_set(0);
    cbreak();
    noecho();

    WINDOW *window = newwin(HEIGHT, WIDTH, 0, 0);
    refresh();

    box (window, 0, 0);
    wrefresh(window);

    while (!gameover) {
        int ch = getch();

        if (player1_score == 10 || player2_score == 10)
            gameover++;

        if (ch == 'w' && player1_y > 1) {
            player1_y--;
            mvprintw((player1_y + 3), 1, " ");
        }

        refresh();

        if (ch == 's' && (player1_y + 4) < HEIGHT) {
            player1_y++;
            mvprintw((player1_y - 1), 1, " ");
        }

        refresh();

        if (ch == KEY_UP && player2_y > 1) {
            player2_y--;
            mvprintw((player2_y + 3), (WIDTH - 2), " ");
        }

        refresh();

        if (ch == KEY_DOWN && (player2_y + 4) < HEIGHT) {
            player2_y++;
            mvprintw((player2_y - 1), (WIDTH - 2), " ");
        }

        refresh();

        for(int i = 1; i <= HEIGHT - 2; i++)
            mvprintw(i, ((WIDTH + 1) / 2), "|");

        refresh();

        for (int i = 0; i < 3; i++)
            mvprintw(player1_y + i, 1, "|");

        refresh();

        for (int i = 0; i < 3; i++)
            mvprintw(player2_y + i, (WIDTH - 2), "|");

        refresh();

        mvprintw(1, (((WIDTH + 1) / 2) - 2), "%d", player1_score);
        mvprintw(1, (((WIDTH + 1) / 2) + 2), "%d", player2_score);

        refresh();

        mvprintw(ball_y, ball_x, "@");

        refresh();

        if (ball_x == WIDTH - 3 && ball_y >= player2_y && ball_y <= player2_y + 3)
            ball_x_velocity = -1;
        else if (ball_x == WIDTH - 1) {
            box(window, 0, 0);
            wrefresh(window);
            player1_score++;
            ball_x = (WIDTH + 1)  / 2;
            ball_y = (HEIGHT + 1) / 2;
            ball_x_velocity = -1;
        }

        if (ball_y == HEIGHT - 2)
            ball_y_velocity = -1;

        if (ball_x == 2 && ball_y >= player1_y && ball_y <= player1_y + 3)
            ball_x_velocity = 1;
        else if (ball_x == 1) {
            box(window, 0, 0);
            wrefresh(window);
            player2_score++;
            ball_x = (WIDTH + 1)  / 2;
            ball_y = (HEIGHT + 1) / 2;
            ball_x_velocity = 1;
        }

        if (ball_y == 1)
            ball_y_velocity = 1;

        ball_x += ball_x_velocity;
        ball_y += ball_y_velocity;

        usleep(BALL_SPEED);
        mvprintw((ball_y - ball_y_velocity), (ball_x - ball_x_velocity), " ");
    }
    delwin(window);
    endwin();
}
