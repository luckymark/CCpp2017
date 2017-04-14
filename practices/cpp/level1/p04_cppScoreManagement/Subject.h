/*
 * Subject.h
 *
 *  Created on: 2017年4月14日
 *      Author: mark
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_
#include<iostream>
#include<string>
#include"class.h"

using namespace std ;

class Point{
public:
	Student* now ;

	Point* last  ;

	Point* next  ;

};


class SUBJECT
{
private :
	Point* Link_Head ;
	Point* Link_Tail ;
	int Number ;
public:
	SUBJECT():Number(0){
		Link_Head = new Point ;
		Link_Tail = Link_Head ;

		Link_Head->now = new Student ;
		Link_Head->next = NULL ;
		Link_Head->last = NULL ;


		cout<<"Have built relevant information"<<endl;
	}
	int ADD_STUDENT(Student temp){
		if( Number == 0 && Link_Tail->now != NULL ){
			*(Link_Tail->now) = temp ;
			Number ++ ;
			Link_Tail->now->Setnumber(Number);

			return 0 ;
		}
		else{
			Student* student = new Student ;
			*student = temp ;

			Number++ ;

			if( Link_Head ->now == NULL ){
				Link_Head ->now = student;
				Link_Head->now->Setnumber(Number);

			}

			else{
				Point* temp1 = new Point ;
				Link_Tail->next = temp1 ;
				temp1->now = student ;
				temp1->next = NULL ;
				temp1->last = Link_Tail ;
				temp1->now->Setnumber(Number);

				Link_Tail = temp1 ;
			}



		}
		return 0 ;
	}
	int DELETE_STUDENT(int n){
		Point* A  = Link_Head ;
		if ( Number == 0 ) return 1;
		while(1){
			if( A->now->Getnumber() == n ){break;}
			A = A->next ;
			if( A == NULL ){
				return 1 ;
			}
		}
		Point *B = A ->next;

		if(Link_Head == Link_Tail){
			delete A->now;
			A->now = NULL ;
			Number--;
			return 0 ;
		}

		if( A->next == NULL ){
			A->last->next = NULL ;

			Link_Tail = A->last;

			delete A->now;
			A->now = NULL;
			delete A ;
			Number -- ;
		}

		else if( A->last == NULL ){
			A->next->last = NULL ;

			Link_Head = A->next ;

			delete A->now;
			A->now = NULL;
			delete A ;
			A = NULL ;

			Number -- ;
		}

		else {
			A->next->last = A->last;
			A->last->next = A ->next ;

			delete A->now ;
			A->now = NULL ;
			delete A ;
			A = NULL ;


			Number -- ;
		}
		while(B!=NULL){
			B->now->Setnumber(n);
			n++ ;
			B = B->next ;

		}

		return 0 ;
	}

	int putsource(string name,float s){
		Point* A  = Link_Head ;
		while(1){
			if( A->now->Getname() == name ){break;}
			A = A->next ;
			if( A == NULL ){
				return 1 ;
			}
		}

		A->now->setsroce(s) ;

		return 0 ;
	}

	int show(){
		if( Number == 0 ) return 1;
		Point* B = Link_Head ;

		while( B != NULL ){
			cout<<"NAME::"<<B->now->Getname()<<endl;
			cout<<"NUMBER:"<<B->now->Getnumber()<<endl;
			cout<<"SCORE:"<<B->now->Getscore()<<endl;
			cout<<"######################"<<endl;
			B = B->next;
		}
		return 0 ;
	}

};





#endif /* SUBJECT_H_ */
