#ifndef SCORE_H
#define SCORE_H
#include <string>
using std::string;
typedef struct student {
	string name;
	string id;
	int score;
}stu;
class Score {
private:
	string Subject;
	stu student[40];
public:
	Score(string subject);
	void show();
	void add();
	void out();
	void inputScore();
protected:
};
#endif