#include <stdio.h>
void put_max(int * num,int i);
int main(void)
{
	int i,c;
	printf("����������Ƚϵ����ĸ���\n");
	scanf("%d",&i);
	int num[i]; 
	for (c=0;c<i;c++){
		scanf("%d",&num[c]);
	}
	put_max(num,i);
 } 
 void put_max(int *num,int i)
 {
 	int j;
 	int max=0;
 	for (j=0;j<i;j++){
 		if (*num>max)
 		max=*num;
 		num++;
	 }
	 printf("%d�����ֵ��\n",max);
 }
