#include <stdio.h>
int main(void)
{
	int year;
	
	printf("请输入年份数.\n");
	while (scanf("%d",&year)){
		if (year%100==0){
			if (year%400==0)
				printf("%d年是闰年。\n",year);
			else 
			    printf("%d年不是闰年。\n",year);
		}
		else {
			if (year%4==0)
			    printf("%d年是闰年。\n",year);
			else
			    printf("%d年不是闰年。\n",year);
		}
	}
	return 0;
 } 
