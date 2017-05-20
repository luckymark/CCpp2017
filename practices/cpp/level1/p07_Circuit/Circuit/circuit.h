/*
 * circuit.h
 *
 *  Created on: 2017年5月2日
 *      Author: mark
 */

#ifndef CIRCUIT_H_
#define CIRCUIT_H_
#include<iostream>
#include"device.h"
using namespace std ;

class circuit
{
private:
	device a[100];
	int head ;
	int tail ;
	int status;
public:
	circuit():status(1),head(0),tail(0){}
	void add(device& A){
		if(tail<100){
			a[tail]= A ;
		}
		else{
			cout<<"sorry cant't add device any more."<<endl;
		}
	}
	void change(){
		if(status==0)status=1;
		if(status==1)status=0;
	}

};




#endif /* CIRCUIT_H_ */
