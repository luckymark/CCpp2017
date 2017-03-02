#include <stdio.h>
int main(void)
{
	int num;
	printf("请输入一个整数，输入任意非数字退出\n");
	while (scanf("%d",&num)){
	   if ((num>0)&&(num%2==0))
	       printf("%d是一个正偶数.\n",num);
	   else if ((num>0)&&(num%2==1))
	       printf("%d是一个正奇数.\n",num);
	   else if ((num<0)&&(num%2==0))
	       printf("%d是一个负偶数.\n",num);
       else if ((num<0)&&(num%2!=0))
	       printf("这是一个负奇数.\n");
	   else
	       printf("这是0.\n");
	 }
	return 0;
}
