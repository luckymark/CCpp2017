#include "iostream"
#include "conio.h"
#include "windows.h"
int main()
{
	int  b[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    char a[9][11]= {"   ####   ",
				   	"  #  M#   ",
                	" #     ###",
               		"##  ##   #",
                	"### ##   #",
               		"#   ##  ##",
                	"#  # # ###",
               		"##  #  ## ",
               		"## ###### "};
               		
    int x=1,y=5,ax,ay,i;
    char t;
    std::cout<<"please use w/a/s/d to control";
    Sleep(1000);
    while(a[8][2] != 'M')
    {
    system("cls");
    for(int k=0;k<9;k++)
    printf("%s\n",a[k]);
    t=getch();
	switch(t)	
	{
	case 'd':i=0;break;
    case 's':i=1;break;
	case 'a':i=2;break;
	case 'w':i=3;break;
	default:printf("your input is wrong");
    }
    
	ax=x+b[i][0];
	ay=y+b[i][1];
    if('#'!=a[ax][ay])
	{
        a[x][y]=' ';
		a[ax][ay]='M';
		x=ax;
		y=ay;
    }
    }
    system("cls");
    for(int k=0;k<9;k++)
    printf("%s\n",a[k]);
    std::cout<<"congratulations!you win";
	Sleep(1000);
    system("pause");
    return 0;
	}
