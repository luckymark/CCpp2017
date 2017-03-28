#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

char boxMap[20][20];
int aimMap[400][3];
int nowx,nowy;
int lengthx,lengthy;
int boolean=0;
int boxNum=0;
int directionx[4]={-1,0,1,0},directiony[4]={0,1,0,-1};

void game();
void move(int direction);

int main(){
	freopen("pushBoxesMap.txt","r",stdin);
	for (lengthx=0;scanf("%s",boxMap[lengthx+1]+1)!=EOF;lengthx++);
	fclose(stdin);
	lengthy=strlen(boxMap[1]+1);
	int aimNum=0;
	for (int i=1;i<=lengthx;i++){
		for (int j=1;j<=lengthy;j++){
			if (boxMap[i][j]=='@'){
				nowx=i;
				nowy=j;
			}
			else if (boxMap[i][i]=='='){
				boxNum++;
			}
			else if (boxMap[i][j]=='0'){
				aimNum++;
				aimMap[aimNum][1]=i;
				aimMap[aimNum][2]=j;
			}
		}
	}
	game();
	return 0;
}

void game(){
	while (1){
		for (int i=1;i<=lengthx;i++){
			for (int j=1;j<=lengthy;j++){
				printf("%c ",boxMap[i][j]);
			}
			printf("\n");
		}
		printf("@ is yourself\n= is the box\n0 is the aim point\n. is road\n# is wall(means you can't go there)\n");
		printf("BTW,I can't solve the pusszling game problem.I hope you can solve the puzzle.\n");
		char direction=getch();
		direction=getch();
		move(direction);
		system("cls");
		if (boolean==boxNum){
			for (int i=1;i<=lengthx;i++){
				for (int j=1;j<=lengthy;j++){
					printf("%c ",boxMap[i][j]);
				}
				printf("\n");
			}
			printf("You Win!\n");
			return;
		}
	}
}

void move(int direction){
	int x,y;
	x=nowx;
	y=nowy;
	boxMap[nowx][nowy]='.';
	switch (direction){
		case 72:{nowx+=directionx[0];nowy+=directiony[0];break;}
		case 77:{nowx+=directionx[1];nowy+=directiony[1];break;}
		case 80:{nowx+=directionx[2];nowy+=directiony[2];break;}
		case 75:{nowx+=directionx[3];nowy+=directiony[3];break;}
	}
	if (boxMap[nowx][nowy]=='.'){
		boxMap[nowx][nowy]='@';
	}
	else if (boxMap[nowx][nowy]=='='){
		int forwardx,forwardy;
		switch (direction){
			case 72:{forwardx=nowx+directionx[0];forwardy=nowy+directiony[0];break;}
			case 77:{forwardx=nowx+directionx[1];forwardy=nowy+directiony[1];break;}
			case 80:{forwardx=nowx+directionx[2];forwardy=nowy+directiony[2];break;}
			case 75:{forwardx=nowx+directionx[3];forwardy=nowy+directiony[3];break;}
		}
		if (boxMap[forwardx][forwardy]!='.'){
			nowx=x;
			nowy=y;
			boxMap[nowx][nowy]='@';
		}
		else{
			boxMap[nowx][nowy]='@';
			boxMap[forwardx][forwardy]='=';
		}
	}
	else{
		nowx=x;
		nowy=y;
		boxMap[nowx][nowy]='@';
	}
	int score=0;
	for (int i=1;i<=boxNum;i++){
		if (boxMap[aimMap[i][1]][aimMap[i][2]]!='@'&&boxMap[aimMap[i][1]][aimMap[i][2]]!='='){
			boxMap[aimMap[i][1]][aimMap[i][2]]='0';
		}
		else if (boxMap[aimMap[i][1]][aimMap[i][2]]=='='){
			score++;
		}
	}
	boolean=score;
}






