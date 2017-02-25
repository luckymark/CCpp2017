#include<stdio.h>
#include<time.h>

int main(  )
{
	int number;
	printf("1 ");
	printf("3 ");
	printf("5 ");
	printf("7 ");
	for( number = 11 ; number <= 1000 ; number++ ){
		int number1 = number/2;
		int k;
		int flag = 0;
		for( k = 2; k <= number1 ; k++ ){
			if( number % k == 0){
				flag = 0;
				break;
			}
			flag = 1;
		}
		if( flag == 1 )printf("%d ",number);
	}
	printf("%d", clock() );
	return 0;


}
