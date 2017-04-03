/*
 * myrand1.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#include<stdlib.h>
#include<time.h>
#include"fun.h"

bool myrand1(int down , int up )
{
	srand(seedfun());

	int number = rand()% up ;

	if( number == down ) return true ;

	return false ;

}





