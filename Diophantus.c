#include <stdio.h>
int main(int argc, char** argv)
{
    int fatherAge=0;
	for(double i=1.0;i<100;i++)           //�������� 
	{
		for(double j=1;j<200;j++)       //�������� 
		{
			if((1.0/6.0*j+1.0/12.0*j+1.0/7.0*j+5+i+4==j)&&(2*i==j))
			{
				fatherAge=j;
				break;
			}
		}
	}
	printf("������ʱ����ͼ����Ϊ%d",FatherAge-4);
	return 0;
}
