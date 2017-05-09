#include "Score.h"
#include <iostream>
#include <string>
using namespace std;
Score::Score(string subject) {
	 Subject = subject;
	 for (int i = 0;i < 40;++i) {
		 student[i].name = "";
		 student[i].id = "";
		 student[i].score = 0;
	 }
}
void Score::show() {
	cout << "Subject:" << Subject << endl;
	for (int i = 0;i < 40;++i) {
		if ("" == student[i].name) continue;
		cout << "Name:" << student[i].name << endl;
		cout << "ID:" << student[i].id << endl;
		cout << "Score:" << student[i].score << endl;
	}
	system("pause");
}
void Score::add() {
	int is = -1;
	for (int i = 0;i < 40;++i) {
		if ("" == student[i].name) {
			is = i;
			break;
		}
	}
	if (-1 == is) {
		cout << "FULL!" << endl;
		system("pause");
	}
	else {
			cout << " Please enter a student's name:" << endl;
			cin.get();
			getline(cin, student[is].name);
			cout << " Please enter a student's ID:" << endl;
			getline(cin, student[is].id);
	}
	
}
void Score::out() {
	string in;
	int find = 0;
	cout << "Please enter the student's name to delete:" << endl;
	cin >> in;
	for (int i = 0;i < 40;++i) {
		if (student[i].name == in) {
			student[i].name = "";
			student[i].id = "";
			student[i].score = 0;
			find = 1;
		}
	}
	if (0 == find) {
		cout << "No find the student!Please enter the correct name:" << endl;
	}
	system("pause");
}
void Score::inputScore() {
	for (int i = 0;i < 40;++i) {
		if (student[i].name != "") {
			cout << "Please enter the score of " << student[i].name << ":" << endl;
			cin >> student[i].score;
		}
	}
}