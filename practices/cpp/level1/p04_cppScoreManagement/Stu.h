#pragma once
#ifndef STU_H_
#define STU_H_
#include<bits/stdc++.h>
using namespace std;
class Stu {
private:
	struct Score {
		int score;
		string name;
	};
	int num;
	map<int, Score>namelist;
public:
	void show();
	void add(string name);
	void del(string name);
	int getnum();
	void putScore(int i, int score);
	Stu();
	~Stu(){}

};
#endif // !STU_H_
