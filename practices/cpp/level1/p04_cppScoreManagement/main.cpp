/*todolist
1.show
2.add
3.delete
4.input the score
5.exit
*/
#include <iostream>
#include <conio.h>
#include <string>
#include "Score.h"
using namespace std;
void showlist(void);
int main(void) {
	string s1 = "chinese", s2 = "math", s3 = "English";
	Score menu[3] = { Score(s1),Score(s2),Score(s3) };
	showlist();
	int option;
	while (1) {

		system("cls");
		showlist();
		cin >> option;
		switch (option) {
		case 1:
			menu[0].show();
			break;
		case 2:
			menu[1].show();
			break;
		case 3:
			menu[2].show();
			break;
		case 4:
			menu[0].add();
			break;
		case 5:
			menu[1].add();
			break;
		case 6:
			menu[2].add();
			break;
		case 7:
			menu[0].out();
			break;
		case 8:
			menu[1].out();
			break;
		case 9:
			menu[2].out();
			break;
		case 10:
			menu[0].inputScore();
			break;
		case 11:
			menu[1].inputScore();
			break;
		case 12:
			menu[2].inputScore();
			break;
		default:
			cout << "exit" << endl;
			break;
		}
	}
}
void showlist(void) {
	cout << "Please enter the number to achieve the following functions:(enter 'q' to quit)" << endl;
	cout << "Show the namelist:" << "1.chinese 2.math 3.English" << endl;
	cout << "Add the student to:" << "4.chinese 5.math 6.English" << endl;
	cout << "Delete the student of:" << "7.chinese 8.math 9.English" << endl;
	cout << "Input the student's student of:" << "10.chinese 11.math 12.English" << endl;
}