#include<stdio.h>
#include<Windows.h>
#include <stdlib.h>

void mapprint();
void posation();
bool move() ;

struct Point
{
	int x;
	int y;
};

struct Point target;
struct Point person;
int main()
{
	move;
	posation();
	mapprint();
	while(!move());
	
	return 0;
}

char map[9][9] ={
	{ '0','R','0','0','0','0','0','0','0' },
	{ '0',' ',' ',' ',' ',' ',' ',' ','0' },
	{ '0',' ','0','0','0','0','0','0','0' },
	{ '0',' ',' ',' ',' ',' ',' ',' ','0' },
	{ '0','0',' ','0','0','0','0','0','0' },
	{ '0',' ',' ',' ',' ',' ',' ',' ','0' },
	{ '0','0','0',' ','0','0','0','0','0' },
	{ '0',' ',' ',' ',' ',' ',' ',' ','0' },
	{ '0','0','0','0','P','0','0','0','0' }
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

void mapprint()
{
	int i, j;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void posation()
{
	target.x=4;
	target.y=8;
	person.x=1;
	person.y=0;
		
}

bool move()
{
	if(GetKeyState(VK_UP) < 0){
		if(map[person.y-1][person.x]==' '){
			person.y--;
			map[person.y][person.x]='R';
			map[person.y+1][person.x]=' ';//注意不能用y++ y的值改变了。 
		}
		Sleep(100);
		system("cls");
		mapprint();
	}
	
	if(GetKeyState(VK_DOWN) < 0){
		if(map[person.y+1][person.x]==' '){
			person.y++;
			map[person.y][person.x]='R';
			map[person.y-1][person.x]=' ';
		}else if(map[person.y+1][person.x]=='P'){
			printf("you win");
			return 1;
		}
		Sleep(100);
		system("cls");
		mapprint();
	}	

	if(GetKeyState(VK_LEFT) < 0){
		if(map[person.y][person.x-1]==' '){
			person.x--;
			map[person.y][person.x]='R';
			map[person.y][person.x+1]=' ';
		}
		Sleep(100);
		system("cls");
		mapprint();
	}	

	if(GetKeyState(VK_RIGHT) < 0){
		if(map[person.y][person.x+1]==' '){
			person.x++;
			map[person.y][person.x]='R';
			map[person.y][person.x-1]=' ';
		}
		Sleep(100);
		system("cls");
		mapprint();
	}
	return 0;
}
