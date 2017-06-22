#include<iostream>
#include<string>
#include"Stu.h"
using namespace std;
int main()
{
	Stu stu;
	int opt;
	char s1[500];
	string s2;
	int score;
	printf("There are 4 kinds of options in total\n");
	printf("1.show students list\n");
	printf("2.add students\n");
	printf("3.delete students\n");
	printf("4.input score one by one from begin to end\n");
	while (~scanf("%d", &opt) && opt >= 1 && opt  <=4) {
		system("cls");
		cin.get();
		switch (opt) {
		case 1:stu.show(); break;
		case 2:
			printf("Enter the student name that you want input\n");
			printf("Enter blank line to end.\n");
			while (cin) {
				cin.get(s1, 500);
				if (s1[0] != 0) {
					s2 = s1;
					stu.add(s2);
				}
				cin.get();
			}
			cin.clear();
			cin.sync();
			break;
		case 3:
			printf("Enter the student name that you want to delete\n");
			printf("Enter blank line to end.\n");
			while (cin) {
				cin.get(s1, 500);
				if (s1[0] != 0) {
					s2 = s1;
					stu.del(s2);
				}
				cin.get();
			}
			cin.clear();
			cin.sync();
			break;
		case 4:
			for (int i = 0; i < stu.getnum(); i++) {
				printf("Please enter the score of No.%d\n", i + 1);
				cin >> score;
				stu.putScore(i + 1, score);
			}
		}
		printf("There are 4 kinds of options in total\n");
		printf("1.show students list\n");
		printf("2.add students\n");
		printf("3.delete students\n");
		printf("4.input score one by one from begin to end\n");
	}
}