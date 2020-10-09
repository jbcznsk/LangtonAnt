#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

struct
{
	int x;
	int y;
	int dir;
} ant_s;
typedef struct ant_s ant;

int
main(int argc, char **argv)
{
	initscr();
	curs_set(1);
	
	int lin, col;
	



	endwin();
	return 0;
}
