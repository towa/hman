#include <stdio.h>
#include <panel.h>
#include <string.h>
#include <menu.h>

WINDOW *wmenu,*winp;
PANEL *pmenu,*pinp;
ITEM **it;
MENU *me;

void quit_curses(void)
{
	del_panel(pinp);
	del_panel(pmenu);
	delwin(winp);
	delwin(wmenu);
	endwin();

}

int main(void)
{
/*	struct hm_word neu,*zneu;
	zneu = &neu;
	neu.life = 12;
*/	
	init_curses();
	atexit(quit_curses);
	
	mvwaddstr(wmenu,19,70,"Some other Stuff");
	refresh();	
	wrefresh(wmenu);
	getch();
	word_input();
	refresh();
	wrefresh(wmenu);
	getch();

}

int init_curses(void)
{
	int x,y;
	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_WHITE);
	init_pair(2,COLOR_WHITE,COLOR_BLUE);
	getmaxyx(stdscr,y,x);
	wmenu = newwin(20,80,y/2-10,x/2-40);
	winp = newwin(10,40,y/2-5,x/2-20);
	pmenu = new_panel(wmenu);
	pinp = new_panel(winp);
	wbkgd(wmenu,COLOR_PAIR(1));
	wbkgd(winp,COLOR_PAIR(2));
	top_panel(pmenu);
	
}



int word_input(void)
{
	top_panel(pinp);
	mvwaddstr(winp,9,6,"TEXT");
	refresh();
	wrefresh(winp);
	getch();
	top_panel(pmenu);
}
