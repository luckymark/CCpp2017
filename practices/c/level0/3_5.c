#include<stdio.h>

int main(void)
{
    int k,i=0;

    for(k =0 ;i <= 100;++i){
     k = ++k;
     if(0 == k % 3 && 0 != k % 5){
        printf("%d\n",k);
        }
     }

	return 0;

}

