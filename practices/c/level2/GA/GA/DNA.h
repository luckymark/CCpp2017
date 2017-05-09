/*
 * DNA.h
 *
 *  Created on: 2017年3月28日
 *      Author: mark
 */
#define LengthOfDNA   100
#ifndef DNA_H_
#define DNA_H_
class DNA
{

public:

	DNA();

	int TestFit();

	int getsource();

	int gitbit(int i);

	void setbit(int i , int j);

private:

	int a[LengthOfDNA] ;

	int source ;

	int x  ;

	int y  ;

	int Destinationx ;

	int Destinationy ;


};

#endif /* DNA_H_ */
