# include<stdio.h>

int i= 0;

int main()
{
	int N;
	printf("input positive integer N: ");
	scanf("%d",&N);
	
	move('a','b','c',N);
	
	printf("these are all steps!");
	return 0;
 } 
 
 void move(char str1,char str2,char str3,int n)
 {
 	if(n==1){
 		printf("the %dst step:\t",++i);
 		printf("%c->%c\n",str1,str3); 
	 }else{
	 	move(str1,str3,str2,n-1);
	 	printf("the %dst step:\t",++i);
	 	printf("%c->%c\n",str1,str3);
	 	move(str2,str1,str3,n-1);
	 }
 }
