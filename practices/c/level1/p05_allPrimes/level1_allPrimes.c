/* 
1. ��ӡ2-1000���ڵ���������
2. ��ӡ���ܵļ���ʱ��
3. �������Ż��㷨��Ч��
*/
#include<stdio.h>
#include<time.h>
#include<Windows.h>
int main()
{
	system("color 0a");
	clock_t t1 = clock();
	for(int a = 2 ; a < 999 ; a++){
		int n = 0;
		for(int i = 2 ; i < a ; i++){
			if(a%i == 0){
				n = 1;
				break;
			}
		}
		if(n == 0){
			printf("%d\t",a);

		}
	}
	clock_t t2 = clock();
	
	printf("\nTime=%d",t2-t1);
	return 0;
}
