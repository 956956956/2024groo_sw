#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main(){
	initscr();
	clear();

	for(int i = 0; i < LINES; i++){
		move(i, i + 1);

		if(i % 2 == 1)
			standout();

			addstr("Hello world");

		if(i % 2 == 1)
			standend();
		
	}
	refresh();
	sleep(1);
	endwin();
	return 0;
}