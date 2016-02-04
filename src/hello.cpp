#include <curses.h>
#include <iostream>

using namespace std;

//void title_slide();
//void

int main()
{
	initscr();
    start_color();

	char screen[25][80];
	
    init_pair(0, COLOR_BLACK, COLOR_RED);

    attron(COLOR_PAIR(0));

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			screen[i][j] = 'A';
			//move(i,j);
			//printw(&screen[i][j]);
		}
	}
	
    refresh();

    getch();

    endwin();
	
	return 0;
}
