#include <stdio.h>
int main(void)
{
	int num;
	printf("������һ����������������������˳�\n");
	while (scanf("%d",&num)){
	   if ((num>0)&&(num%2==0))
	       printf("%d��һ����ż��.\n",num);
	   else if ((num>0)&&(num%2==1))
	       printf("%d��һ��������.\n",num);
	   else if ((num<0)&&(num%2==0))
	       printf("%d��һ����ż��.\n",num);
       else if ((num<0)&&(num%2!=0))
	       printf("����һ��������.\n");
	   else
	       printf("����0.\n");
	 }
	return 0;
}
