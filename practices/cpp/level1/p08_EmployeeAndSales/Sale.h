#ifndef SALE_H_
#define SALE_H_
#include <string>
using namespace std;

class Staff{
	private:
		string name;
		int age,level;
	public:
		Staff(string name, int age,int level):name(name),age(age),level(level){}
		int get_salary(){
			return level * 1000;
		}
};

class Saleman: public Staff{
	private:
		int price;
	public:
		Saleman(string name = "", int age = 0, int level = 0,int price_ = 0):Staff(name,age,level){
			price = price_;
		}
		int get_salary(){
			return Staff::get_salary() + 0.2*price;
		}
};

#endif
