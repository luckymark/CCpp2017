#include<stdio.h>
#include<time.h>
#include<math.h>

int main(  )
{
    for(int number=2; number<=1000000 ; number++) {

        int k = sqrt (number) ;
        int flag = 1 ;    

        for(int number1 = 2 ; number1 <= k ; number1++) {
            if(number % number1 != 0) {
                flag = 1 ;
            } else {
                flag = 0 ;    
                break;
            }
        }

        if(flag == 1){
            printf("%d\n",number);
        }

    }

    printf("\n %d",clock());

    return 0;

}
