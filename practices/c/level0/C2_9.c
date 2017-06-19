#include <stdio.h>

int main()
{
	int i;
	int n1,n2,n3,n4,n5;
	
    printf("请输入0~9中任意五个数: ");
    scanf("%d,%d,%d,%d,%d",&n1,&n2,&n3,&n4,&n5);
    
    for(i=0;i<10;i++)
    {
    	if(n1!=i&&n2!=i&&n3!=i&&n4!=i&&n5!=i)
    	{
    		printf("%d\t",i);
		  }
	}
	
	return 0;
}
