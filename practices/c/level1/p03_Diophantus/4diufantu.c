#include<stdio.h>
int main(void)
{
	int i;
	double a=1.0/6+1.0/12+1.0/7;
	double b;
	for(i=1;i<=200;i++)
	{
		b=2*(i-a*i-5-4);
		if((i-b)<0.001)break;
    	}
    	printf("\n\nÄêÁäÊÇ%dËê\n\n\n\n",i);
    	system("pause");
    	return 0;
}
