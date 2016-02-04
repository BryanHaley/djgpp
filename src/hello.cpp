#include <curses.h>
#include <iostream>

using namespace std;

void print_at(int y, int x);
void print_vertical_line(int y1, int y2, int x);
void print_horizontal_line(int x1, int x2, int y);
void print_diag_315_line(int y1, int y2, int x);
void print_title_box();

void title_slide();
void features_slide();
void popular_slide();

const int KEY_ESCAPE = 27;

int main()
{
	initscr();
	start_color();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	
	init_pair(1, COLOR_BLUE, COLOR_BLUE);	
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	
	title_slide();

	endwin();
	
	return 0;
}

void title_slide()
{
	clear();

	attron(COLOR_PAIR(1));
	
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			move(i,j);
			printw(" ");
		}
	}
	
	attron(COLOR_PAIR(2));
	
	print_vertical_line(9,15,4);
	print_vertical_line(9,15,11);
	print_vertical_line(9,15,18);
	print_vertical_line(9,15,32);
	print_vertical_line(9,15,42);
	print_vertical_line(9,15,48);
	print_vertical_line(9,15,62);
	print_vertical_line(9,15,66);
	print_vertical_line(9,15,70);
	
	print_vertical_line(9,12,14);
	print_vertical_line(9,12,21);
	print_vertical_line(9,12,35);
	print_vertical_line(9,12,51);

	print_vertical_line(10,14,24);
	print_vertical_line(10,14,29);
	print_vertical_line(10,14,54);
	print_vertical_line(10,14,59);
	
	print_vertical_line(10,11,45);
	print_vertical_line(10,11,63);

	print_vertical_line(12,12,64);
	print_vertical_line(13,14,65);

	print_horizontal_line(5,8,9);
	print_horizontal_line(5,8,15);

	print_horizontal_line(5,7,12);

	print_horizontal_line(12,13,9);
	print_horizontal_line(12,13,12);

	print_horizontal_line(19,20,9);
	print_horizontal_line(19,20,12);

	print_horizontal_line(25,28,9);
	print_horizontal_line(25,28,15);
	print_horizontal_line(33,34,9);
	print_horizontal_line(33,34,12);
	
	print_horizontal_line(43,44,9);
	print_horizontal_line(43,44,12);

	print_horizontal_line(49,50,9);
	print_horizontal_line(49,50,12);

	print_horizontal_line(55,58,9);
	print_horizontal_line(55,58,15);

	print_horizontal_line(71,74,9);
	print_horizontal_line(71,74,15);
	print_horizontal_line(71,73,12);

	print_diag_315_line(13,15,13);
	print_diag_315_line(13,15,20);
	print_diag_315_line(13,15,34);
	print_diag_315_line(13,15,50);
	
	attron(COLOR_PAIR(3));
	
	move(17,22);
	printw("ALLAN MANANGAN");
	move(20,23);
	printw("BRYAN HALEY");
	move(17,42);
	printw("CHRISTOPHER WIRTES");
	move(20,44);
	printw("JOSEPH CAUTHEN");
	
	refresh();
	
	int key;
	
	do
	{
		key = getch();
		
		if (key == KEY_LEFT)
		{
			popular_slide();
			break;
		}
		
		else if (key == KEY_RIGHT)
		{
			features_slide();
			break;
		}
		
		else if (key == KEY_ESCAPE)
		{
			clear();
			refresh();
			break;
		}
	} while (key!=KEY_RIGHT);
}

void features_slide()
{
	clear();
	
	print_title_box();
	printw("MS-DOS 3.30 FEATURES");
	
	attron(COLOR_PAIR(4));
	
	move(8,8);
	printw("* Shipped with IBM PS/2 Computer (rebranded as PC-DOS).");
	
	move(10,8);
	printw("* Support for multiple logical partitions, up to 32MB each.");
	
	move(12,8);
	printw("* Support for 3.5 inch, 1.44MB floppy disks.");
	
	move(14,8);
	printw("* Added character sets for other languages.");
	
	move (16,8);
	printw("* Support for 'extended' partitions.");
	
	refresh();
	
	int key;
	
	do
	{
		key = getch();
		
		if (key == KEY_LEFT)
		{
			title_slide();
			break;
		}
		
		else if (key == KEY_RIGHT)
		{
			popular_slide();
			break;
		}
		
		else if (key == KEY_ESCAPE)
		{
			clear();
			refresh();
			break;
		}
	} while (key!=KEY_RIGHT && key!=KEY_LEFT);
}

void popular_slide()
{
	clear();
	
	print_title_box();
	printw("MS-DOS 3.30 REMAINED POPULAR");
	
	attron(COLOR_PAIR(4));
	
	move(8,8);
	printw("* MS-DOS 3.31 was only available to OEM manufacturers.");
	
	move(12,8);
	printw("* MS-DOS 3.30 could be used on custom-built PCs, and worked");
	move(13,12);
	printw("well with most hardware.");
	
	move(16,8);
	printw("* MS-DOS 4.0 was buggy; memory address errors caused many");
	move(17,12);
	printw("programs to crash.");
	
	refresh();
	
	int key;
	
	do
	{
		key = getch();
		
		if (key == KEY_LEFT)
		{
			features_slide();
			break;
		}
		
		else if (key == KEY_RIGHT)
		{
			title_slide();
			break;
		}
		
		else if (key == KEY_ESCAPE)
		{
			clear();
			refresh();
			break;
		}
	} while (key!=KEY_RIGHT && key!=KEY_LEFT);
}

void print_at(int y, int x)
{
	move(y,x);
	printw(" ");
}

void print_vertical_line(int y1, int y2, int x)
{
	for (int y_loc = y1; y_loc <= y2; y_loc++)
	{
		print_at(y_loc, x);
	}
}

void print_horizontal_line(int x1, int x2, int y)
{
	for (int x_loc = x1; x_loc <= x2; x_loc++)
	{
		print_at(y, x_loc);
	}
}

	
void print_diag_315_line(int y1, int y2, int x)
{
	for (int i = 0; i <= y2-y1; i++)
	{
		print_at(y1+i, x+i);
	}
}

void print_title_box()
{
	attron(COLOR_PAIR(2));
	print_horizontal_line(0,79,0);
	print_horizontal_line(0,79,4);
	print_vertical_line(1,3,0);
	print_vertical_line(1,3,79);
	
	attron(COLOR_PAIR(3));
	move(2,3);
}






