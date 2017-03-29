/*
 * TestFit.cpp
 *
 *  Created on: 2017年3月28日
 *      Author: mark
 */
#include<cmath>
#include"DNA.h"

int DNA::TestFit()
{
	int *p = a ;

	while(p != p+99 ){
		int number = *p + *(++p) * 2;

		switch (number){
		case 0 :
			if(map[x+1][y]!='#'||map[x+1][y]!='@')
				x++;
			break;
		case 1 :
			if(map[x][y+1]!='#'||map[x][y+1]!='@')
				y++;
				break;
		case 2 :
			if(map[x-1][y]!='#'||map[x-1][y]!='@')
				x--;
			break;
		case 3 :
			if(map[x][y-1]!='#'||map[x][y-1]!='@')
				y--;
			break;
		}

	}

	source = 400 - sqrt((Destinationx-x)*(Destinationx-x)+(Destinationy-y)*(Destinationy-y))
;
	x = 9 ;
	y = 8 ;

	if( source == 0 )return 1 ;

	return 0 ;
}



