#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int n,t=0,i,m;
	printf("n:");
	scanf("%d",&n);
    
   
    for(i=2;i<=n/2;i++)
    {
    	t=0;
    	m=n%i;
    	if(m==0)
    	{
    		printf("%d��������",n);
			t=1; 
    		break;
		}
		}
    
		if(t==0)
		{
			printf("%d������",n);
		}
   
	system("pause");
	return 0;
}
