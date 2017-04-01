#include <stdio.h> 
#include<time.h>

int isPrimer(int num);

int main()
{
	clock_t start,finish;
	start = clock();	
	int primer;
	
	
	for(int i = 2;i<=1000;i++){
		primer = isPrimer(i);
		if(primer){
			printf("%d\n",i);
		}
	}
	
	printf("the running time is:\t");
	finish = clock();
	double time = (double)(finish-start)*1000/CLOCKS_PER_SEC;
	printf("%lf ms",time);
	
	return  0;
 } 
 
 int isPrimer(int num){
 	int result = 0;
 	int cnt = 0;
 	
 	for(int i = 2;i<=sqrt(num);i++){
 			if(num%i==0)  {
 				cnt++;
 				break;
			 }
		 }
	 
	if(cnt==0){
	 	result = 1;
	}
	 
	 return result;
 }
