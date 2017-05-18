#include<stdio.h>
int main(void)
{
  int number[10]={0};
  int i,j;

  for(i=1;i<=5;i++){
      scanf("%d",&j);
      number[j]=1;
  }

  for(i=1;i<=9;i++){
      if(number[i]==0){
      printf("%d",i);
  }

  }
   return 0;
}

