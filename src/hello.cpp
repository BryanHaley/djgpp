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
	
    init_pair(1, COLOR_BLUE, COLOR_BLUE);

	attron(COLOR_PAIR(1));
	
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			screen[i][j] = ' ';
			move(i,j);
			printw(&screen[i][j]);
		}
	}
	
    refresh();

    getch();

    endwin();
	
	return 0;
}
