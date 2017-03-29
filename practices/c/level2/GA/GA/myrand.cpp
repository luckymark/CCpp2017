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
using namespace std ;

void myran(int MIN ,int MAX , int b[MAX-MIN+1] )
{
	int a[MAX-MIN+1];

	int c = 0 ;

	for( int i = MIN ; i <= MAX ; i++  ){
		a[c] = i ;
		c++ ;
	}

	int number = MAX-MIN+1 ;

	int k = 0;

	while( number !=0 ){
		srand((int)time(0));
		int i = rand() % number ;

		b[k] = a[i] ;

		k++;

		while(i != number-1 ){
			a[i] = a[i+1] ;

			i++ ;
		}

		number -- ;
	}

	for( int i = 0; i<=MAX-MIN ; i ++ ){
		cout<<b[i]<<endl;
	}

}


