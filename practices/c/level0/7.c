#include<stdio.h>

int main(void)
{
    int k,j=0,i=0;

    for(k =0 ;i < 100;++i){
        k = ++k;
        if(0 == k % 7 ){
           printf("%d\n",k);
        }
    }

     for( j = 0;j<10;++j){
         printf("%d\n",k=j*10+7);
        }


	return 0;

}

