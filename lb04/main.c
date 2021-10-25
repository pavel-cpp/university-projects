#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include "sosoqe.h"

int main()
{
	initscr();
	int num = 0, a ,b, c;
	num = menu(num);
	refresh();
	system("clear");
	echo();
	printw("----------------------MENU----------------------");
	printw("\n\tEnter the arguments:");
	printw("\n\n\t\ta = ");
	printw("\n\n\t\tb = ");
	printw("\n\n\t\tc = ");
	printw("\n\n\n------------------------------------------------");
	move(4, 20);
	scanw("%d", &a);
	move(6, 20);
	scanw("%d", &b);
	move(8, 20);
	scanw("%d", &c);
	endwin();
	system("clear");
	refresh();
	endwin();
	if((float)(sqrt(pow(b, 2) - 4 * a * c)) >= 0){
		printf("\n\n\n\t\t Answer: ");
		switch(num){
			case 0:
				firstMethod(a, b, c);
				break;
			case 1:
				secondMethod(a, b, c);
				break;
			case 2:	
				thirdMethod(a, b, c);
				break;
			case 3:
				fourthMethod(a, b, c);
				break;
			case 4:
				fifthMethod(a, b, c);
				break;
			case 5:
				sixthMethod(a, b, c);
				break;
			case 6:
				seventhMethod();
				break;
			case 7:
				eighthMethod();
				break;
			case 8:
				ninthMethod();
				break;
			case 9:
				tenthMethod();
				break;
	}
	printf("\n\n\n ");
	}
	else
		printf("\n\n\n\t\tNo Roots\n\n\n");
}