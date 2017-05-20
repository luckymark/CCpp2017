/*
 * device.h
 *
 *  Created on: 2017年5月2日
 *      Author: mark
 */

#ifndef DEVICE_H_
#define DEVICE_H_
#include<iostream>
using namespace std ;

class device
{
private:
	int status ;

public:
	device():status(0){};
	virtual void display() = 0 ;
	void change(){
		if(status==0)status=1;
		if(status==1)status=0;
	}
	int getstaus(){
		return status;
	}
	~device(){};
};

class Light : public device
{
public:
	void display(){
		if(getstaus()==1){
			cout<<"run"<<endl;
		}
		else{}
	}
	~Light(){}
};



#endif /* DEVICE_H_ */
