/*
 * cross.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#define AmountOfSample  20
#define LengthOfDNA 100
#include"fun.h"
#include<stdlib.h>
void cross(DNA* A)
{
	int strategy[AmountOfSample] ;

	int *p = strategy ;

	int * q = strategy -1 ;

	myrand(0,AmountOfSample-1,strategy);

	while( p <= q ){
		int m = *p ;
		int n = *(p+1) ;

		srand((int)time(0));

		int posible = rand()%10;

		if( posible < 7 ){
			int bit = rand()%LengthOfDNA ;
			if(bit != LengthOfDNA -1  ){
				for( int j = bit +1 ; j<= LengthOfDNA -1 ; j++  ){
					int temp = A[m].a[j] ;
					A[m].a[j] = A[n].a[j] ;
					A[n].a[j] = temp ;
				}
			}
		}
		p = p + 2 ;
	}
}

