#include <time.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

const int MAXN=202;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,tot,goal[MAXN][2],map[MAXN][MAXN];
void loading();
void working();
int main(){
	loading();
	working();
	return 0;
}
void loading(){
	FILE *f;
	FIRST:
	char s[MAXN],ch;
	printf("Please input the data file name:");
	scanf("%s",s);
	if ((f=fopen(s,"r"))!=NULL) printf("Ok!\n");
	else {
		printf("Oh no!!\n");
		Sleep(3000);
		goto FIRST;
	}
	fscanf(f,"%d%d",&n,&m); fscanf(f,"%c",&ch);
	for (int i=1;i<=n;fscanf(f,"%c",&ch),++i)
		for (int j=1;j<=m;++j) {
			fscanf(f,"%c",&ch);
			switch (ch) {
				case '.':map[i][j]=0;break;
				case 'U':map[i][j]=1;break;
				case 'x':map[i][j]=2;break;
				case '#':map[i][j]=3;break;
				case 'o':map[i][j]=4;break;
			}
		}
	fclose(f);
}
void working(){
	int i,j,k,x,y,num=0;
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
		if (map[i][j]==2) {
			++tot;
			goal[tot][0]=i;
			goal[tot][1]=j;
		}
	for (i=0;i<=n+1;++i) map[i][0]=map[i][m+1]=3;
	for (j=0;j<=m+1;++j) map[0][j]=map[n+1][j]=3;
	for (i=1;i<=n;++i) {
		for (j=1;j<=m;++j)
		if (map[i][j]==1) { x=i; y=j; break; }
		if (map[i][j]==1) break;
	}
	while (1) {
		system("cls");
		for (i=1;i<=n;++i) {
			for (j=1;j<=m;++j)
			switch (map[i][j]) {
				case 0:printf(".");break;
				case 1:printf("U");break;
				case 2:printf("x");break;
				case 3:printf("#");break;
				case 4:printf("o");break;
			}
			printf("\n");
		}
		printf("w:up\ns:down\na:left\nd:right\nx:exit\n");
		for (i=1;i<=tot;++i)
		if (map[goal[i][0]][goal[i][1]]==0) map[goal[i][0]][goal[i][1]]=2;
		for (i=1,j=0;i<=tot;++i)
		if (map[goal[i][0]][goal[i][1]]==4) j++;
		if (tot==j) {
			printf("U win!!!!!\n");
			return;
		}
		READAGAIN:
		char ch=getch();
		num++;
		if (num==100) {
			printf("U lose!!!!!\n");
			return;
		}
		switch (ch) {
			case 's':k=0;break;
			case 'd':k=1;break;
			case 'w':k=2;break;
			case 'a':k=3;break;
			case 'x':break;
			default:goto READAGAIN;
		}
		if (ch=='x') return;
		int xx=x+dir[k][0],yy=y+dir[k][1];
		if (map[xx][yy]<4) {
			if (map[xx][yy]!=3) {
				map[xx][yy]=1;
				map[x][y]=0;
				x=xx; y=yy;
			}
		}
		else {
			int x2=xx+dir[k][0],y2=yy+dir[k][1];
			if (map[x2][y2]<3) {
				map[x2][y2]=4;
				map[xx][yy]=1;
				map[x][y]=0;
				x=xx; y=yy;
			}
		}
	}
}

/*
Ugly format!!!

*/
