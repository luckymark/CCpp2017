#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <termios.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<unistd.h>
using namespace std;
void delay(int t){
		for(int i = 1; i <= 50000000; i++);
}
void print_space(int x){
		for(int i = 1; i <= x; i++) 
				cerr << " ";
		cerr << "R";
}
int main(){
		winsize size;
		int pos = 0,dir = 1;
		while(1){
				ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
				int col = size.ws_col - 1;
				system("clear");
				print_space(pos);
				delay(1);
				if(pos == 1)
					   	dir = 1;
				if(pos == col)
					   	dir = -1;
				pos += dir;
		}
		return 0;
}
