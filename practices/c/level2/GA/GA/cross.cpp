/*
 * cross.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#define AmountOfSample  200
#define LengthOfDNA 100
#include"fun.h"
#include"DNA.h"
#include<stdlib.h>
#include<time.h>
#include"fun.h"
void cross(DNA* A)
{
	srand(seedfun());

	int strategy[AmountOfSample] ;

	int *p = strategy ;

	int * q = strategy+AmountOfSample-2 ;

	myrand(0,AmountOfSample-1,strategy);

	while( p <= q ){
		int m = *p ;
		int n = *(p+1) ;

		int posible = rand()%10;

		if( posible < 7 ){
			int bit = rand()%LengthOfDNA ;
			if(bit != LengthOfDNA -1  ){
				for( int j = bit +1 ; j<= LengthOfDNA -1 ; j++  ){
					int temp = A[m].gitbit(j)  ;
					A[m].setbit( j , A[n].gitbit(j) );
					A[n].setbit(j , temp );
				}
			}
		}
		p = p + 2 ;
	}
}

