#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

char theMap[9][9];
int nowx,nowy;
int directionx[4]={-1,0,1,0},directiony[4]={0,1,0,-1};
int length=0;
int boolean=0;

void game();
void move(int direction);

int main(){
	freopen("mazeMap.txt","r",stdin);
	for (int i=1;scanf("%s",theMap[i]+1)!=EOF;i++);
	fclose(stdin);
	length=strlen(theMap[1]+1);
	for (int i=1;i<=length;i++){
		for (int j=1;j<=length;j++){
			if (theMap[i][j]=='@'){
				nowx=i;
				nowy=j;
			}
		}
	}
	game();
	return 0;	
}

void game(){
	while (1){
		for (int i=1;i<=7;i++){
			for (int j=1;j<=7;j++){
				printf("%c",theMap[i][j]);
			}
			printf("\n");
		}
		char direction=-32;
		while(direction==-32){
			direction=getch();
		}
		move(direction);
		if (boolean){
			system("cls");
			for (int i=1;i<=7;i++){
				for (int j=1;j<=7;j++){
					printf("%c",theMap[i][j]);
				}
				printf("\n");
			}
			printf("\nYou Win!\n");
			return;
		}
		system("cls");
	}
}

void move(int direction){
	theMap[nowx][nowy]='.';
	int x=nowx,y=nowy;
	switch (direction){
		case 72:{nowx+=directionx[0];nowy+=directiony[0];break;}
		case 77:{nowx+=directionx[1];nowy+=directiony[1];break;}
		case 80:{nowx+=directionx[2];nowy+=directiony[2];break;}
		case 75:{nowx+=directionx[3];nowy+=directiony[3];break;}
	}
	if (theMap[nowx][nowy]=='.'||theMap[nowx][nowy]=='*'){
		if (theMap[nowx][nowy]=='*'){
			boolean=1;
		}
		theMap[nowx][nowy]='@';
	}
	else{
		nowx=x;
		nowy=y;
		theMap[x][y]='@';
	}
}

