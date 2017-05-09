/*
 * vary.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#include"fun.h"
#define LengthOfSample 200
#define LengthOfDNA 100
void vary (DNA* A)
{
	int i = 0 ;
	int j = LengthOfSample - 1 ;

	while(i <= j ){
		int k = 0 ;
		while(  k < LengthOfDNA ){
				if( myrand1(1,16000) ){
					if(A[i].gitbit(k)==0)A[i].setbit(k,1);
					if(A[i].gitbit(k)==1)A[i].setbit(k,0);
				}
				k++ ;
		}

		i++ ;
	}
}



