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

	char map[10][10]={
				{'#','#','#','#','#','#','#','#','#','#'},
				{'#',' ',' ',' ',' ',' ',' ',' ','#','#'},
				{'@',' ','#','#','#','#','#',' ','#','#'},
				{'#',' ','#',' ','#',' ','#',' ','#','#'},
				{'#',' ',' ',' ',' ',' ','#',' ','#','#'},
				{'#',' ','#',' ','#',' ','#',' ','#','#'},
				{'#',' ','#','#','#',' ','#',' ','#','#'},
				{'#',' ','#',' ','#',' ','#',' ','#','#'},
				{'#',' ',' ','#','#',' ',' ',' ','*','#'},
				{'#','#','#','#','#','#','#','#','#','#'}
			    };

	int *p = a ;

	int number = 0 ;

	while(p < a+99 ){
		number = *p  ;

		p++;

		number = (*p)+(*p) + number ;

		switch (number){
		case 0 :
			if(map[x+1][y]!='#')
				x++;
			break;
		case 1 :
			if(map[x][y+1]!='#')
				y++;
			break;
		case 2 :
			if(map[x-1][y]!='#')
				x--;
			break;
		case 3 :
			if(map[x][y-1]!='#')
				y--;
			break;
		}

		p++;
		if(y == 0 && x ==2 )return 1 ;

	}

	source = 400-sqrt((Destinationx-x)*(Destinationx-x)+(Destinationy-y)*(Destinationy-y));

	x = 8 ;
	y = 8 ;

	if( source == 400 ) return 1 ;

	return 0 ;
}



