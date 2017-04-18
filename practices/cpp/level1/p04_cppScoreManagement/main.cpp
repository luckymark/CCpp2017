#include <iostream>
#include <fstream>
#include <curses.h>
#include <string>
#include "UI.h"
#include "IO.h"
#include <locale.h>
using namespace std;
void main_loop(){
		init();
		draw_interface();
		show_begin();
		while(1){
				update_content();
				//update_content();
				choose_menu();
		}
		finish();
}
int main(){
		setlocale(LC_ALL,"");
		main_loop();
		return 0;
}
