/*
 * NaturealSelect.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#include<time.h>
#include<stdlib.h>

#define AmountOfSample 20

void NaturalSelect( DNA* A )
{
	DNA *B =  A;

	DNA *C = A ;

	int sum = 0 ;
	float flag[AmountOfSample] ;

	for(int i=0;i<AmountOfSample;i++){
			sum = sum + A->getsource();
			flag[i]=sum;
		}

	int repoduce[AmountOfSample] ;

	int c =0;

	int j =0;
	while(j < AmountOfSample ){
		srand((int)time(0));

		float index = rand() % sum ;

		int k =0 ;

		while(1){
			if(index <= flag[k] ){
				repoduce[c] = k ;
				c++;
				break;
			}
			k++;
		}
		j++;
	}

	DNA temp[AmountOfSample] ;

	j = 0 ;

	while(j < AmountOfSample){

		for( int i = 0; i < repoduce[j] ; i++  ){
			temp[i]=B;
		}
		j++;
		B++;
	}

	for(j = 0 ; j < AmountOfSample ; j++  ){
		A[j] = temp[j] ;
	}

}




