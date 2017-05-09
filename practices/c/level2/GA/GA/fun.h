/*
 * fun.h
 *
 *  Created on: 2017年3月29日
 *      Author: mark
 */

#ifndef FUN_H_
#define FUN_H_

#include"DNA.h"

void myrand(int MIN , int MAX , int b[]);

void aver (DNA* A, int m );

void NaturalSelect(DNA* A );

void cross(DNA* A) ;

void vary (DNA* A ) ;

bool myrand1(int up , int down);

int seedfun();

void way(int *way);



#endif /* FUN_H_ */
