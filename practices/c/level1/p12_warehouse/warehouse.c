#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int n,m,v[1000];
struct Data
{
	int num;
	char name[10];
};
Data goods[1000],temp[1000];
void loading();
void saving(); 
void working();
int main()
{
	loading();
	working();
	saving();
	return 0;
}
void loading()
{
	FILE *f=fopen("data.txt","r");
	if(f==NULL)
	{
		printf("No data!\n");
		return;
	}
	else 
	{
		fscanf(f,"%d",&n);
		for (int i=1;i<=n;i++) 
		{
			fscanf(f,"%s %d",goods[i].name,&goods[i].num);
		}
	}
	fclose(f);
}
void working()
{
	while (1) 
	{
		printf("1 show list\n");
		printf("2 append\n");
		printf("3 pop\n");
		printf("4 exit\n");
		char ch=getch();
		if (ch<'1'||ch>'6')
			continue;
		int i,j,k=ch-'0';
		if (k==1) {
			for (i=1;i<=n;i++) 
			{
				printf("%d:%s %d\n",i,goods[i].name,goods[i].num);
			}
			Sleep(3000);
		}
	if (k==2) 
	{
		printf("Please input the number of goods you want to add:\n");
		scanf("%d",&m); 
		printf("Please input some goods:\n");
		for (i=n+1;i<=n+m;i++)
		{
			scanf("%s %d",goods[i].name,&goods[i].num);
		}
		n+=m;
	}
	if (k==3) 
	{
		printf("Please input some goods:\n");

			scanf("%d",&j);
		for (i=1;i<=n-j;i++)
		{
			temp[j+i-1]=goods[j+i];
			goods[j+i-1]=temp[j+i-1];
		}
	}
	if (k==4)
		break;
	}
}
void saving()
{
		FILE *f=fopen("data.txt","w");
	fprintf(f,"%d\n",n);
	for (int i=1;i<=n;++i) {
		fprintf(f,"%s %d\n",goods[i].name,goods[i].num);
	}
	fclose(f);
}
