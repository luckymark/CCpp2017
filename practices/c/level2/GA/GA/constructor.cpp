/*
 * constructor.cpp
 *
 *  Created on: 2017年3月28日
 *      Author: mark
 */
#include<iostream>
#include<stdlib.h>
using namespace std ;

#define LengthOfDNA   100

DNA::DNA():source(0),Number(0)
{
	for(int i = 0 ; i < LengthOfDNA ; i++ ){
		srand((int)time(0));
		a [i] =  rand() % 2;
	}
}



