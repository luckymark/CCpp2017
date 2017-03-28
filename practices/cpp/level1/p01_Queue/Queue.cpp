/*
 * Queue.cpp
 *
 *  Created on: 2017年3月28日
 *      Author: mark
 */

#include "Queue.h"
#include<iostream>

using namespace std;

Queue::Queue():head(0),tail(0){

	// TODO Auto-generated constructor stub
}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

bool Queue::IsFull()
{
	if( tail == 100 )return true ;
	return false ;
}

bool Queue::Isemp()
{
	if( tail == 0 ){
		cout<<"it's empty"<<endl;

		return true ;
	}
	return false ;
}

void Queue::append(int number)
{
	data [tail] = number ;

	tail ++ ;

}

void Queue::show()
{
	for(int i = 0 ; i < 100 ; i++  ){
		cout << data[i] <<endl;
	}

}




