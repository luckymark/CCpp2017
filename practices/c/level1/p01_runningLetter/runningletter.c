#include<stdio.h>
#include<windows.h>
int main()
{
	int n,i,j,k=1,speed;
	char ch='R';
	scanf("%d %d",&n,&speed);
	for(i=0;i<n;i+=k)
	{
		for(j=0;j<i;j++)putchar(' ');
		putchar(ch);
		Sleep(speed); 
		if(k==-1&&i==0)break;
		system("cls");
		if(i==n-1)k=-1;
	}
	return 0;
}
