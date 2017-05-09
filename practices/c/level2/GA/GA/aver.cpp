/*
 * aver.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#define AmountOfSample  200
#include<iostream>
#include"DNA.h"
using namespace std ;

void aver(DNA* A,int m){
	int sum = 0 ;

	for(int i=0;i<AmountOfSample;i++){
		sum = sum + A->getsource();

		A++;
	}

	float average = sum / AmountOfSample;

	cout<<"average="<<average<<endl;

}








