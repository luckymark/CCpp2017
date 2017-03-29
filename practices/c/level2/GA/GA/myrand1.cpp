/*
 * myrand1.cpp
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */
#include<stdlib.h>

bool myrand1(int up , int down )
{
	srand((int)time(0));

	int number = rand()% down ;

	if( number == up ) return true ;

	return false ;

}





