/*

 * myrand.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 *
 *
 */
//this is strategy of making pairs

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"fun.h"
using namespace std ;

void myrand(int MIN ,int MAX , int b[] )
{
	int number = MAX-MIN+1;

	int a[number];

	int c = 0 ;

	for( int i = MIN ; i <= MAX ; i++  ){
		a[c] = i ;
		c++ ;
	}

	int k = 0;
	srand(seedfun());
	while( number !=0 ){
		int i = rand() % number ;

		b[k] = a[i] ;

		k++;

		while(i != number-1 ){
			a[i] = a[i+1] ;

			i++ ;
		}

		number -- ;
	}

}


