//written on unix
#include <stdio.h>
#include <curses.h>
void delay(){
		for(int i = 1; i <= 50000000; i++);
}
int main(){
		initscr();
		int pos = 0,dir = 1;
		while(1){
				int col = COLS - 1;
				mvaddch(0,pos,'R');
				refresh();
				delay();
				if(pos == 0)
					   	dir = 1;
				if(pos == col)
					   	dir = -1;
				mvaddch(0,pos,' ');
				pos += dir;
		}
		endwin();
		return 0;
}
