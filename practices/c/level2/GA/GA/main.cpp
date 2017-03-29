
/*

 * main.cpp
 *
 *  Created on: 2017年3月28日
 *      Author: mark
 */

#include<iostream>
#include"DNA.h"
#include"fun.h"

#define AmountOfSample  20

using namespace std ;



int main()
{
	DNA amount[AmountOfSample] ;

	for(int i = 0 ; i < AmountOfSample ; i ++ ){

		DNA temp ;

		amount[i] =  temp ;

	}

	int k = 0 ;

	while(1){

		int yorn = 0 ;

		for(int i = 0 ; i < AmountOfSample ; i ++ ){

			yorn = amount[i].TestFit();

			if(yorn == 1)break;

			k = i ;
		}

		if(yorn == 1)break;

		aver(amount);

		NaturalSelect(amount);

		cross(amount);

		vary(amount) ;

	}

	for(int j = 0 ;j< LengthOfDNA ; j++){
		cout<<amount[k].a[j]<<endl;
	}
	return 0 ;
}


