#include <stdio.h> 
# include<math.h>

int main(void)
{
	int shuixianshu;
	int baiwei,shiwei,gewei;
	
	printf("三位水仙数如下：\n");
	
	for(int i = 100;i<1000;i++){
		baiwei = i/100;
		shiwei = (i%100)/10;
		gewei  = i%10;
		
		if(i==pow(baiwei,3)+pow(shiwei,3)+pow(gewei,3)){
			shuixianshu = i;
			printf("%d\t",shuixianshu);
		}
	}
	
	return  0;
 } 
