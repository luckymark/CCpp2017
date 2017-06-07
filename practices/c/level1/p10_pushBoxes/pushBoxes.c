//pushiboxes.cpp
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
 
typedef int bool;
#define true 1
#define false 0

char map[9][9]={0};
FILE* MapChoose();
void MapRead(void);
void MapPrint(void);
void Position(void);
void Turn(void);
bool Check(void);
const int xdir[5]={ 0,0,-1,1,0};
const int ydir[5]={-1,1, 0,0,0};
void Move(void);
struct Point
{
	int x;
	int y;
	int dir;
};
struct Point Right;
struct Point Person;
struct Point Box;


int main(int argc, char *argv[]) 
{
	MapChoose();
//	MapRead();
	Position();
	while(true)
	{
		MapPrint();
		Turn();
		if (Check())
		Move();
		Person.dir = 4;
		system("cls");
	}
	return 0;
}

FILE* MapChoose()
{
	char level;
	printf("Please choose the level you want to play:");
 	scanf("%c",&level);
	FILE *fp;
	
	if((fp = fopen("D:\\Programing\\Homework\\c\\p10_pushBoxes\\1.txt","r")) == NULL)
	{
		printf("can't open the map\n'");
		exit(1);
	}
	
	switch(level)
	{
		case'1':
			fp=fopen("D:\\Programing\\Homework\\c\\p10_pushBoxes\\1.txt","r") ;
			break;
		default:printf("invaild input\n");
	}

	char ch;
	int i = 0;
	int j = 0;
	while ( (ch =  getc(fp) )!= EOF )
	{	
		if(j==10)
		{
			i+=1;
			j=0;	
		}
		
		for (; i < 10 ; ++i )
		{
			for(; j < 9 ; ++j )
				{
					map[i][j] = ch;
					break;
				}
			break;
		}
		j+=1;
	}
}

/*void MapRead()
{
	
}*/

void MapPrint()
{
	int i = 0;
	int j = 0; 
	for (i = 0; i< 9; ++i)
	{
		for (j = 0; j< 9; ++j)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void Position()
{
	Right.x = 3;
	Right.y = 8;
	Person.x = 0;
	Person.y = 1;
	Box.x = 5;
	Box.y = 3;
}

void Turn()
{
	if(_kbhit())
	{
		char dir = _getch();
			switch(dir)
			{
				case 'a': Person.dir = 0;break;
				case 'd': Person.dir = 1;break;
				case 'w': Person.dir = 2;break;
				case 's': Person.dir = 3;break;
				default:
					break;
			}
	}
}

bool Check()
{
	if (map[Person.x+ xdir[Person.dir]][Person.y +ydir[Person.dir]]  == '0' || map[Person.x+ xdir[Person.dir]][Person.y +ydir[Person.dir]]  == 'E')		 
		return false;		//人碰墙、碰出口不动
	else if( map[Person.x+ xdir[Person.dir]][Person.y +ydir[Person.dir]]  == '*' && map[Box.x +xdir[Person.dir]][Box.y +ydir[Person.dir]]  == '0')
		return false;		//人前是箱子，箱子碰墙不动 
	else if(map[Box.x + xdir[Person.dir]][Box.y + ydir[Person.dir]] == 'E')		//箱子到出口赢 
	{
		printf("You win!\n");	
		exit(0);	
	}	
	else
		return true;
}

void Move()
{
	if	(map[Person.x+ xdir[Person.dir]][Person.y +ydir[Person.dir]]  == ' ')	//人前方无障碍，人动 
	{
		map[Person.x][Person.y] = ' ';					
		Person.x = Person.x + xdir[Person.dir];
		Person.y = Person.y + ydir[Person.dir];
		map[Person.x][Person.y] = 'R';
	}	
	
	if( map[Person.x+ xdir[Person.dir]][Person.y +ydir[Person.dir]]  == '*')		//人前方是箱子 
	{
		if ( map[Box.x +xdir[Person.dir]][Box.y +ydir[Person.dir]]  != '0')			//箱子前面不是墙，动 
		{
			map[Person.x][Person.y] = ' ';					
			Person.x = Person.x + xdir[Person.dir];
			Person.y = Person.y + ydir[Person.dir];
			map[Box.x][Box.y] = 'R';
			Box.x = Box.x + xdir[Person.dir];
			Box.y = Box.y + ydir[Person.dir];
			map[Box.x][Box.y] = '*';
		}
	}
}
