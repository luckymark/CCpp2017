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
class STUDENT
{
private:
	string name;

	string subject ;

	int source ;

	int number ;

	STUDENT* next = NULL ;

	STUDENT* last = NULL ;

public:
	void setsource(){
		cout<<"Please input the source the student get"<<endl;
		int s ;
		cin >> s ;
		source = s ;

	}

	void setname(){
		cout<<"please input the name ."<<endl;
		cin >> name ;
	}

	void numberset(int N){
		number = N ;
	}

	void SETPOINTER_NEXT(STUDENT* PN ){
		next = PN ;
	}

	void SETPOINTER_LAST(STUDENT* PL ){
		last = PL ;
	}

	int getnumber(){
		return number ;
	}

	int getsource(){
		return source ;
	}

	string getname(){
		return name ;
	}

	string getsubject(){
		return subject ;
	}

	STUDENT* getlast(){
		return last ;
	}

	STUDENT* getnext(){
			return next ;
	}
};

class SUBJECT
{
private :
	STUDENT* Student_Head ;

	STUDENT* Student_Tail ;

	int NUMBER = 0 ;
public:
	SUBJECT(){
		Student_Head = new STUDENT ;
		Student_Tail = Student_Head ;

		Student_Tail->setname();

		Student_Tail->numberset(NUMBER);
		NUMBER++;
	}

	void ADD_STUDENT(){
		STUDENT* temp = Student_Tail ;
		STUDENT* temp1 = new STUDENT ;

		Student_Tail->SETPOINTER_NEXT(temp1) ;

		temp1->SETPOINTER_LAST(temp) ;
		temp1->SETPOINTER_NEXT(NULL);

		Student_Tail = temp1 ;


		Student_Tail->setname();
		Student_Tail->numberset(NUMBER);
		NUMBER++;

	}

	int DELETE_STUDENT(){
		if( NUMBER == 0 ){
			cout<<"there is no information of any student now ."<<endl;
			return 0 ;
		}
		STUDENT* find = Student_Head ;
		cout<<"NAME"<<endl;
		string NAME ;
		cin >> NAME ;
		while(1){
			if(find->getname()==NAME){break;}

			find = find->getnext();

			if(find == NULL){
				cout<<"can't find the student!"<<endl ;
				return 0 ;
			}

		}
		if( find == Student_Head ){
			if( find->getnext() != NULL){
				Student_Head = find ->getnext();
				find->getnext()->SETPOINTER_LAST(NULL);
			}
			else {
				delete find ;
				NUMBER--;
				cout<<NUMBER<<endl;
				return 0 ;
			}

		}
		else if(find == Student_Tail){
			find->getlast()->SETPOINTER_NEXT(find->getnext()) ;

			Student_Tail = find->getlast();
		}
		else{

			find->getnext()->SETPOINTER_LAST(find ->getlast()) ;

			find->getlast()->SETPOINTER_NEXT(find->getnext()) ;

			Student_Tail = find ->getnext() ;
		}
		delete find ;
		NUMBER--;
		cout<<NUMBER<<endl;
		return 0 ;
	}

	void putsource(){
		while(1){
			cout<<"Please input the number of student"<<endl;
			int n ;
			cin >> n ;

			STUDENT* PUT_POINT = Student_Head ;

			while(1){
				if( PUT_POINT->getnumber() == n ){break;}

				PUT_POINT = PUT_POINT->getnext();

				if(PUT_POINT == NULL){
					break ;
				}
			}
			PUT_POINT->setsource();

			cout<<"Do you want to still? y/n"<<endl;
			char c ;
			cin>>c ;
			if(c == 'n' ) break ;
		}
	}

	int show(){
		if( NUMBER == 0){
			cout<<"there is no information of any students."<<endl;
			return 0 ;
		}

		STUDENT* SHOW_POINT = Student_Head ;

		while( SHOW_POINT != NULL ){
			cout<<"NAME :"<<SHOW_POINT->getname()<<endl;
			cout<<"NUMBER :"<<SHOW_POINT->getnumber()<<endl;
			cout<<"SUBJECT :"<<SHOW_POINT->getsubject()<<endl;
			cout<<"SOURCE :"<<SHOW_POINT->getsource()<<endl;

			SHOW_POINT = SHOW_POINT->getnext() ;
		}
		return 0 ;
	}
};




#endif /* CLASS_H_ */
