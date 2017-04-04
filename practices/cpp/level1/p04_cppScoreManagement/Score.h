#ifndef SCORE_H
#define SCORE_H
#include<string>
using std::string;
struct manage{
	string name;
	string number;
	int score;
};
class Score
{
	private:
		string Subject;
		manage student[30];
	public:
		Score(string subject);
		void disp();
		void add();
		void del();
		void write();
	protected:
};

#endif
