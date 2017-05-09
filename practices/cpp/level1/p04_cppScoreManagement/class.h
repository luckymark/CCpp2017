/*
 * class.h
 *
 *  Created on: 2017年3月31日
 *      Author: mark
 */

#ifndef CLASS_H_
#define CLASS_H_

#include<string>
using namespace std ;
class Student
{
private:
	string Name;

	string Subject ;

	float Score ;

	int Number ;

public:
	void setsroce(float s){
		Score = s ;
	}

	void Setname(string name){
			Name = name ;
	}

	void Setnumber(int N){
		Number = N ;
	}


	int Getnumber(){
		return Number ;
	}

	int Getscore(){
		return Score;
	}

	string Getname(){
		return Name ;
	}

	string Getsubject(){
		return Subject ;
	}

};


#endif /* CLASS_H_ */
