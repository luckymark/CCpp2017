/*
 * classfun.cpp
 *
 *  Created on: 2017年3月30日
 *      Author: mark
 */

#include<iostream>

#include"DNA.h"

#include<stdlib.h>

#include<time.h>

#include"fun.h"
DNA::DNA()
{
	source = 0 ;

	x = 8 ;

	y = 8 ;

	Destinationx = 2 ;

	Destinationy = 0 ;

	srand(seedfun());

	for(int i = 0 ; i < LengthOfDNA ; i++ ){

		a [i] =  rand() % 2;

	}

}


int DNA::gitbit(int i)
{
	return a[i] ;
}

void DNA::setbit(int i , int j)
{
	a[i] = j;
}

