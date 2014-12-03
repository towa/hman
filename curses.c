#include <stdio.h>
#include <panel.h>
#include <string.h>

WINDOW *wmenu,*winp;
PANEL *pmenu,*pinp;

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
	
	mvwaddstr(wmenu,19,70,"Stuff");
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
	init_pair(2,COLOR_WHITE,COLOR_RED);
	getmaxyx(stdscr,y,x);
	wmenu = newwin(20,80,y/2-10,x/2-40);
	winp = newwin(4,40,y/2-2,x/2-20);
	pmenu = new_panel(wmenu);
	pinp = new_panel(winp);
	wbkgd(wmenu,COLOR_PAIR(1));
	wbkgd(winp,COLOR_PAIR(2));
	top_panel(pmenu);
	
}



int word_input(void)
{
	char word[1024];
	top_panel(pinp);
	mvwaddstr(winp,1,0,"Enter your Word and press ENTER");
	refresh();
	wrefresh(winp);
	char eingabe = getch();
	int i = 0;
	while (eingabe != '\n')
	{
		word[i] = eingabe;
		i++;
		eingabe = getch();	
	}
	mvwprintw(winp,1,0,"%s",word);
	wrefresh(winp);
	getch();
	top_panel(pmenu);
}
