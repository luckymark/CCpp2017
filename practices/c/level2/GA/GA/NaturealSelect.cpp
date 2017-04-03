/*
 * NaturealSelect.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#include<time.h>
#include<stdlib.h>
#include"DNA.h"
#define AmountOfSample 200

void NaturalSelect( DNA* A )
{
	srand((int)time(0));

	DNA *B =  A;

	int sum = 0 ;
	int flag[AmountOfSample] ;

	for(int i=0;i<AmountOfSample;i++){
			sum = sum + A[i].getsource();
			flag[i]=sum;
		}

	int repoduce[AmountOfSample] = {0} ;



	int j =0;
	while(j < AmountOfSample ){


		int index = rand() % sum ;

		int k =0 ;

		while(1){
			if(index <= flag[k] ){
				repoduce[k] ++ ;
				break;
			}
			k++;
		}

		j++;
	}

	DNA tem[AmountOfSample] ;

	j = 0 ;

	int k = 0 ;

	while(j < AmountOfSample){

		for( int i = 0; i < repoduce[j] ; i++  ){
			tem[k]=*B;
			k++;
		}
		j++;
		B++;
	}

	for(j = 0 ; j < AmountOfSample ; j++  ){
		A[j] = tem[j] ;
	}

}




