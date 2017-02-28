#include <stdio.h>

int main()
{
	int a,b,c,max;
	printf("请输入三个正数(用逗号隔开): ");
	scanf("%d,%d,%d",&a,&b,&c);
	
	max=a>=b?a:b;
	max=max>c?max:c;
	printf("%d",max);
	
	return 0;
}
