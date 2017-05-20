/*
 * SafeArry.h
 *
 *  Created on: 2017年3月30日
 *      Author: mark
 */

#ifndef SAFEARRY_H_
#define SAFEARRY_H_

class SafeArry
{
public:
	SafeArry(int number):k(number){
		arry = new int[k] ;
	}

	void put(int number , int value);

	int get(int number) ;

private:
	int k ;
	int* arry ;
};



#endif /* SAFEARRY_H_ */
