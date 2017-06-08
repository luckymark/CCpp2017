/*
 * myrand.cpp
 *
 *  Created on: 2017年6月8日
 *      Author: mark
 */
#include<time.h>
#include<cstdlib>
int myrand(){
	static int x = 0;
	static int i = 0;
	if(i%6==0){
		x = rand()%300;
	}
	x = x + 100 ;
	i++;
	return x ;

}



