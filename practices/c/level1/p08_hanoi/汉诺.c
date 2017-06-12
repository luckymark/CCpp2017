#include<stdio.h>
#include<stdlib.h>
int hannuo(int n,char q,char w,char e)//状态不同  状态转换  
{
	if(n==1)
	{
		printf("将顶端盘子从%c柱移到%c柱\n",q,e);
	}
	else
	{
		hannuo(n-1,q,e,w);
		hannuo(1,q,w,e);
		hannuo(n-1,w,q,e);
	}
	return 0;
}
int main(void)
{
	int n;
	printf("请输入汉诺塔的层数\n");
	scanf("%d",&n); 
	hannuo(n,'A','B','C');
	return 0;
}

