/*
 * way.cpp
 *
 *  Created on: 2017年4月2日
 *      Author: mark
 */

#include<iostream>

using namespace std ;
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
void way(int *a)
{
	int *p = a ;
	int x = 8;
	int y = 8 ;
	int number = 0 ;
	char ways[100];
	int i = 0;

	while(p < a+99 ){
		number = *p  ;

		p++;

		number = (*p)+(*p) + number ;

		switch (number){
		case 0 :
			if(map[x+1][y]!='#'){
				x++;
				ways[i]='S';
				i++;
			}
			break;
		case 1 :
			if(map[x][y+1]!='#'){
				y++;
				ways[i]='D';
				i++;
			}
				break;
		case 2 :
			if(map[x-1][y]!='#'){
				x--;
				ways[i]='W';
				i++;
			}
			break;
		case 3 :
			if(map[x][y-1]!='#'){
				y--;
				ways[i]='A';
				i++ ;
			}
			break;
		}
		p++;
		if(x==2&&y==0)break;
	}
	ways[i]='\0';
	cout<<ways<<endl;
}

