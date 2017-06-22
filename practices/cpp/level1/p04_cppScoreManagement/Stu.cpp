#include"Stu.h"
void Stu::add(string str)
{
	Score temp = { -1 ,str };
	namelist.insert(pair<int, Score>(getnum() + 1, temp));
	num += 1;
}
Stu::Stu()
{
	num = 0;
	namelist.clear();
}
void Stu::putScore(int i,int score)
{
	namelist[i].score = score;
}
void Stu::del(string s1)
{
	map<int, Score>::iterator it;
	it = namelist.begin();
	for (it = namelist.begin(); it != namelist.end(); it++) {
		if (it->second.name == s1) {
			namelist.erase(it);
			break;
		}
	}
}
int Stu::getnum()
{
	return num;
}
void Stu::show()
{
	map<int, Score>::iterator it;
	it = namelist.begin();
	for (it = namelist.begin(); it != namelist.end(); it++) {
		cout << "ID:" << it->first << "Name: " << it->second.name;
		if (it->second.score > 1)
			cout << "  Score: " << it->second.score;
		cout << endl;
	}
}