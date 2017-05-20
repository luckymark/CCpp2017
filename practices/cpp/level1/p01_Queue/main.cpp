/*
 * main.cpp
 *
 *  Created on: 2017年3月28日
 *      Author: mark
 */
#include<iostream>
#include"Queue.h"

using namespace std ;

int main()
{
	Queue queue ;

    queue.Isemp();

	int i =0;

	while( !(queue.IsFull()) ){
		queue.append(i);
		i++;
	}

	queue.show();

	return 0;
}


