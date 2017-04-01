#include <stdio.h> 
#include<time.h>

int isPrimer(int num);

int main()
{	
	int primer[25];
 	int cnt = 0;
 	for(int i = 2;i<100;i++){
	 	if(isPrimer(i))	{
	 		primer[cnt] = i;
	 		cnt++;
		 }
	 }
 
	 for(int i=3;i<=100;i++){
	 	if(i%2==0){
	 		for(int m = 0;m<=25;m++){
	 			for(int n = 0;n<=25;n++){
	 				if(primer[m]+primer[n]==i){
	 					printf("%d=%d+%d\n",i,primer[m],primer[n]);
					 }
				 }
			 }
		 }
	 }
	 
 	printf("So,we can learn that Goldbach's suspect is right in 0-100.\n");
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
 
 
 
