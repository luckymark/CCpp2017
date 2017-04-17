#include "Course.h"

Course::Course(string name,int score){
	this->name=name;
	this->score=score;
}

Course::~Course(){}

string Course::GetCourseName(){
	return name;
}

int Course::GetScore(){
	return score;
}
