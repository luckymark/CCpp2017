#include <stdio.h>

int main()
{
	int n1,n2,n3,n4,n5,a=0;
	
	printf("������0~9���������(�ö��Ÿ���)�� ");
	scanf("%d,%d,%d,%d,%d",&n1,&n2,&n3,&n4,&n5);
	
	while(a < 10)
	{
	    if((n1!=a)&&(n2!=a)&&(n3!=a)&&(n4!=a)&&(n5!=a))
	    {
		printf ("%d\,",a);
	    }   
	    a=a+1;
    }
	
	return 0;
}

