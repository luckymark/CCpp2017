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

	DNA() ;

	int TestFit();

	int getsource();

	~DNA();

private:

	int a[LengthOfDNA] ;

	int source ;

	int Number;

	char map[10][10]={'#','#','#','#','#','#','#','#','#','#',
					  '#',' ',' ',' ',' ',' ',' ',' ','#','#',
					  '@',' ','#','#','#','#','#',' ','#','#',
					  '#',' ','#',' ','#',' ','#',' ','#','#',
					  '#',' ',' ',' ',' ',' ','#',' ','#','#',
					  '#',' ','#',' ','#',' ','#',' ','#','#',
					  '#',' ','#','#','#',' ','#',' ','#','#',
					  '#',' ','#',' ','#',' ','#',' ','#','#',
					  '#',' ',' ','#','#',' ',' ',' ',' ','$',
					  '#','#','#','#','#','#','#','#','#','#',
					};
	int x = 9 ;

	int y = 8 ;

	int Destinationx = 0;

	int Destinationy = 2;

	\
};

#endif /* DNA_H_ */
