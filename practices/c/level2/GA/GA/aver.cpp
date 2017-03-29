/*
 * aver.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#define AmountOfSample  20
#include<iostream>

using namespace std ;

void aver(DNA* A){
	int sum = 0 ;

	for(int i=0;i<AmountOfSample;i++){
		sum = sum + A->getsource();

		A++;
	}

	float average = sum / AmountOfSample;

	cout<<average<<endl;

}




}



