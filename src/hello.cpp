#include <curses.h>
#include <iostream>

using namespace std;

/* Helper functions to draw on the screen */
void print_at(int y, int x);
void print_vertical_line(int y1, int y2, int x);
void print_horizontal_line(int x1, int x2, int y);
void print_diag_315_line(int y1, int y2, int x);
void print_title_box();

/* Slides are conceptualized as functions */
void title_slide();
void features_slide();
void popular_slide();

/* Keycode for escape in pdcurses is 27 */
const int KEY_ESCAPE = 27;

int main()
{
	initscr(); //init curses
	start_color(); //enable usage of color
	noecho(); //don't show typing
	keypad(stdscr, TRUE); //enable usage of special keys
	curs_set(0); //turn off blinking cursor
	
	/*init text / background color pairs*/
	init_pair(1, COLOR_BLUE, COLOR_BLUE);	
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	
	title_slide(); //start presentation

	endwin(); //clean up curses
	
	return 0; //exit
}

void title_slide()
{
	clear(); //clear the screen

	attron(COLOR_PAIR(1)); //use color pair 1
	
	/* fill the screen with a blue background */
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			move(i,j);
			printw(" ");
		}
	}
	
	attron(COLOR_PAIR(2)); //use color pair 2
	
	/* Draw ERROR PRONE on the screen */
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
	
	attron(COLOR_PAIR(3)); //use color pair 3
	
	/* Print our names on the screen */
	move(17,22);
	printw("ALLAN MANANGAN");
	move(20,23);
	printw("BRYAN HALEY");
	move(17,42);
	printw("CHRISTOPHER WIRTES");
	move(20,44);
	printw("JOSEPH CAUTHEN");
	
	refresh(); // update the screen
	
	/* test for input */
	int key;
	
	do
	{
		key = getch();
		
		if (key == KEY_LEFT) //previous slide
		{
			popular_slide();
			break;
		}
		
		else if (key == KEY_RIGHT) //next slide
		{
			features_slide();
			break;
		}
		
		else if (key == KEY_ESCAPE) //quit
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
	
	print_title_box(); //prints a box in the upper region of the screen
	printw("MS-DOS 3.30 FEATURES"); //title
	
	attron(COLOR_PAIR(4)); //use color pair 4
	
	/* print slide info */
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
	
	/* check for input */
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
	
	/* print title */
	print_title_box();
	printw("MS-DOS 3.30 REMAINED POPULAR");
	
	attron(COLOR_PAIR(4)); //use color pair 4
	
	/* print slide info */
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
	
	/* check for input */
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

/* print an empty (background color) block at a location */
void print_at(int y, int x)
{
	move(y,x);
	printw(" ");
}

/* print a solid vertical line at a certain location */
void print_vertical_line(int y1, int y2, int x)
{
	for (int y_loc = y1; y_loc <= y2; y_loc++)
	{
		print_at(y_loc, x);
	}
}

/*print a solid horizontal line at a certain location */
void print_horizontal_line(int x1, int x2, int y)
{
	for (int x_loc = x1; x_loc <= x2; x_loc++)
	{
		print_at(y, x_loc);
	}
}

/* print a diagonal line at 315* (bottom right) degrees */
void print_diag_315_line(int y1, int y2, int x)
{
	for (int i = 0; i <= y2-y1; i++)
	{
		print_at(y1+i, x+i);
	}
}

/*print a hollow box for the title on slides*/
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






