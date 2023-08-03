#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../headers/sosoqe.h"

int menu(int num){
	initscr();
	noecho();
	int x = 0, y = 3;
	chtype ch;
	printw("----------------------MENU----------------------");
	printw("\n\n\n\t-> *First Method");
	printw("\n\n\t   *Second Method");
	printw("\n\n\t   *Third Method");
	printw("\n\n\t   *Fourth Method");
	printw("\n\n\t   *Fifth Method");
	printw("\n\n\t   *Sixth Method");
	printw("\n\n\t   *Seventh Method");
	printw("\n\n\t   *Eighth Method");
	printw("\n\n\t   *Ninth Method");
	printw("\n\n\t   *Tenth Method");
	printw("\n\n\n------------------------------------------------");
	refresh();
	move(0,0);
	while(1){
		move(y, x);
		ch = getch();
		move(y, x);
		if(ch == 65 && num != 0){
			num--;
			y-=2;
		}
		if(ch == 66 && num != 9){
			num++;
			y+=2;
		}
		if(num >= 0 && num <= 9){
				move(y - 2, x);
				printw("\t  ");
				move(y + 2, x);
				printw("\t  ");
				move(y, x);
				printw("\t->");
		}
		refresh();
		if(ch == 10){
			move(1, 0);
			refresh();
			endwin();
			system("clear");
			return num;
		}
	}

}