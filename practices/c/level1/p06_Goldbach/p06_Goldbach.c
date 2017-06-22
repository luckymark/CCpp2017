#include <stdio.h>
#define RAN 100
int main(void)
{
	int num;
	int i,j;
	int a,b; 
	int temp;
	int judge=0;
	for (num=4;num<RAN;num=num+2){
		temp=num/2;
		for (j=2;j<=temp;j++){
			for (i=2;i*i<=j;i++){
			    if (j%i==0){
				    break;
				}
			}
			if (i*i>j){
				    judge++;
				}
			for (i=2;i*i<=(num-j);i++){
			    if ((num-j)%i==0)break;
			}
			if (i*i>(num-j)){
				judge++;
			}
			if (judge==2){ 
			    printf("%dÂú×ã¸çµÂ°ÍºÕ²ÂÏë,²ğ·ÖÎª%3d, %3d\n",num,j,num-j);
			} 
				judge=0;
		}
	}
 } 
