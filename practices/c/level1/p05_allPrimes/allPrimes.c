#include<stdio.h>
#include<time.h>
int main()
{
	int j;
	double time;
	clock_t begin, end;
	begin = clock();
	printf("%5d", 2);
	for (int num = 3;num <= 1000;num++){
		j = 2;
		while (num > j){
			if (num%j == 0)
				break;
			else{
				if (num == j + 1){
					printf("%5d", num);
					break;
				}
				j++;

			}
		}
	}
	end = clock();
	time = (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\n\n运行时间为%f秒", time);
}





