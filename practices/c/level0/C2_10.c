#include <stdio.h>

int main()
{
	int a[6]={0};
	int i,j;
	int changed,temp;
	
	printf("请输入五个0~9的数： ");
	
	for(i=1;i<=5;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for (i=1;i<5;i++)
	{
		changed=0;
		for(j=1;j<5;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				changed=1;
			}
		}
		if(changed==0)
		{break;
		}
	}
	
	for(i=1;i<=5;i++)
	{
		printf("%d\t",a[i]);
	}
	
	return 0;
}
