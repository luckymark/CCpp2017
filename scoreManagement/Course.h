#include <string>
using namespace std;
class Course{
	private:
		string name;
		int score;
	public:
		Course(string name,int score);
		~Course();
		string GetCourseName();
		int GetScore();
};
