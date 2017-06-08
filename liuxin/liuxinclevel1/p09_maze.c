#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef long long LL;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

const int MAXN=22;
int n,m,x,y,p,q,a[MAXN][MAXN];
int rand(int n);
int main(){
	int i,j,k;
	srand(time(0));
	printf("Please input the length and the width:\n");
	n=read(); m=read();
	memset(a,0,sizeof(a));
	for (i=1;i<=n*m/2;++i) { j=rand(n); k=rand(m); a[j][k]=1; }
	system("cls");
	for (i=n;i;--i) {
		for (j=m;j;--j) if (!a[i][j]) break;
		if (!a[i][j]) break;
	}
	a[i][j]=2; x=i; y=j;
	for (i=1;i<=n;++i) {
		for (j=1;j<=m;++j) if (!a[i][j]) break;
		if (!a[i][j]) break;
	}
	a[i][j]=3; p=i; q=j;
	for (i=1;i<=n;++i) {
		for (j=1;j<=m;++j)
			switch (a[i][j]) {
				case 0:printf(" "); break;
				case 1:printf("*"); break;
				case 2:printf("U"); break;
				case 3:printf("G"); break;
			}
		puts("");
	}
	printf("U:your position\n");
	printf("G:your goal\n");
	for (k=1;;++k) {
		char ch=getch();
		a[p][q]=0;
		switch (ch) {
			case 75:{
				if (y>1&&!a[x][y-1]) {
					a[x][y]=0;
					a[x][--y]=2;
				}
				break;
			}
			case 77:{
				if (y<m&&!a[x][y+1]) {
					a[x][y]=0;
					a[x][++y]=2;
				}
				break;
			}
			case 72:{
				if (x>1&&!a[x-1][y]) {
					a[x][y]=0;
					a[--x][y]=2;
				}
				break;
			}
			case 80:{
				if (x<n&&!a[x+1][y]) {
					a[x][y]=0;
					a[++x][y]=2;
				}
				break;
			}
		}
		a[p][q]=3;
		system("cls");
		for (i=1;i<=n;++i) {
			for (j=1;j<=m;++j)
				switch (a[i][j]) {
					case 0:printf(" "); break;
					case 1:printf("*"); break;
					case 2:printf("U"); break;
					case 3:printf("G"); break;
				}
			puts("");
		}
		//printf("%d %d\n",k,n*m/2);
		if (x==p&&y==q) {
			printf("Congatulations!\n");
			return 0;
		}
		if (k==n*m*2) {
			printf("UUUUUUUUUUUUUUUUUUUUUUUUUUUSB!\n");
			return 0;
		}
	}
	
	return 0;
}
int rand(int n){ return (rand()<<16|rand())%n+1; }

/*
72 80 75 77
*/
