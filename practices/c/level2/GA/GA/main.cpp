
/*

 * main.cpp
 *
 *  Created on: 2017年3月28日
 *      Author: mark
 */

#include<iostream>

#include"DNA.h"
#include"fun.h"
#include<cstdlib>
#include<time.h>

#define AmountOfSample  200

using namespace std ;

int seed = 0 ;

int seedfun()
{
	if( seed == 10000000  )
		seed = 0 ;
	seed=seed+100;;
	return time(0)+seed;
}

int main()
{
	int time1 = time(0);

	DNA amount[AmountOfSample] ;

	for(int i = 0 ; i < AmountOfSample ; i ++ ){
		DNA temp ;
		amount[i] =  temp ;
	}

	int k = 0 ;

	DNA* mid = amount ;

	while(1){

		int yorn = 0 ;

		for(int i = 0 ; i < AmountOfSample ; i ++ ){

			yorn = amount[i].TestFit();

			k = i ;

			if(yorn == 1)break;

		}


		if(yorn == 1)break;

		aver(mid,AmountOfSample);

		NaturalSelect(mid);

		cross(mid);

		vary(mid) ;


	}

	int wayo[100];

	for(int j = 0 ;j< LengthOfDNA ; j++){

		wayo[j]=amount[k].gitbit(j);
	}

	way(wayo);

	int time2 = time(0);

	cout<<endl<<time2-time1<<endl;

	return 0 ;
}




