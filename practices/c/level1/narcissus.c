#include<stdio.h>
int main()
{
	int shuixianhua,bai,shi,ge;
	printf("the narcissus£º");
	for(shuixianhua=100;shuixianhua<1000;shuixianhua++)
	{
		bai=shuixianhua/100;
		shi=(shuixianhua-100*bai)/10;
		ge=shuixianhua%10;
		
		if(shuixianhua==ge*ge*ge+shi*shi*shi+bai*bai*bai)
		{
			printf("%d\t",shuixianhua);
		}
	}
}
