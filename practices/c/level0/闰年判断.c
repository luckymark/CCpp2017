#include <stdio.h>
int main(void)
{
	int year;
	
	printf("�����������.\n");
	while (scanf("%d",&year)){
		if (year%100==0){
			if (year%400==0)
				printf("%d�������ꡣ\n",year);
			else 
			    printf("%d�겻�����ꡣ\n",year);
		}
		else {
			if (year%4==0)
			    printf("%d�������ꡣ\n",year);
			else
			    printf("%d�겻�����ꡣ\n",year);
		}
	}
	return 0;
 } 
