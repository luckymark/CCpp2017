#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

const int MAXN=200005;
int n,m,v[MAXN];
struct Data{
	int num;
	char name[20];
}goods[MAXN],tmp[MAXN];

void loading();
void saving();
void working();
int main(){
	loading();
	working();
	saving();
	return 0;
}
void loading(){
	FILE *f=fopen("data.txt","r");
	if (f==NULL) {
		printf("Oh,no!!!\n");
		n=0;
	}
	else {
		fscanf(f,"%d",&n);
		for (int i=1;i<=n;++i) {
			fscanf(f,"%s %d",goods[i].name,&goods[i].num);
		}
	}
	fclose(f);
}
void saving(){
	FILE *f=fopen("data.txt","w");
	fprintf(f,"%d\n",n);
	for (int i=1;i<=n;++i) {
		fprintf(f,"%s %d\n",goods[i].name,goods[i].num);
	}
	fclose(f);
}
void working(){
	while (1) {
		system("cls");
		printf("1 show list\n");
		printf("2 in\n");
		printf("3 out\n");
		printf("4 exit\n");
		READAGAIN:
		char ch=getch();
		if (ch<'1'||ch>'6') goto READAGAIN;
		int i,j,k=ch-'0';
		if (k==1) {
			for (i=1;i<=n;++i) {
				printf("%d:%s %d\n",i,goods[i].name,goods[i].num);
			}
			Sleep(5000);
		}
		if (k==2) {
			printf("Please input some goods:\n");
			scanf("%d",&m); getchar();
			for (i=n+1;i<=n+m;++i) {
				scanf("%s %d",goods[i].name,&goods[i].num);
				getchar();
			}
			n+=m;
		}
		if (k==3) {
			printf("Please input some goods:\n");
			scanf("%d",&m);
			for (i=1;i<=n;++i) {
				v[i]=0;
			}
			while (m--) {
				scanf("%d",&j);
				v[j]=1;
			}
			for (i=1,j=0;i<=n;++i)
			if (!v[i]) {
				tmp[++j]=goods[i];
			}
			for (i=1,n=j;i<=n;++i) {
				goods[i]=tmp[i];
			}
		}
		if (k==4) break;
	}
}

/*
Ugly format!!!
*/
