#include <stdio.h>
#include <unistd.h>
#include <curses.h>

#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10

int main() {
	char *message = "Hello";
	char *blank = "     ";
	int direction = 1;
	int position = LEFTEDGE;

	initscr();
	clear();

	while (1) {
		move(ROW, position);
		addstr(message);
		move(LINES - 1, COLS - 1);
		refresh();
		sleep(1);

		move(ROW, position);
		addstr(blank);

		position += direction;

		if (position <= LEFTEDGE) {
			direction = 1;
		}

		if (position >= RIGHTEDGE) {
			direction = -1;
		}
	}
	return 0;
}