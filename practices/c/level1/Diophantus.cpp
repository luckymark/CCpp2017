#include<stdio.h>
int main()
{
	for(int i=28;i<200;i+=28)
	{
		if((i-4-(i/7)-(i/4)-5)*2==i)
		{
            printf("%d",i-4)
		}
	}
	return 0;
}
