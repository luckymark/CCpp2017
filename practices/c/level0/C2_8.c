#include <stdio.h>

#define n 9

int main()
{
    int string[n]={0};
	  int i;
	
	  printf("请输入n个数: ");
	
	  for(i=0;i<=n-1;i++)
	  {
		    scanf("%d",&string[i]);
	  }
	
	  for(i=n-1;i>=0;i--)
	  {
		    printf("%d  ",string[i]);
	  }
	
	  return 0;
}
