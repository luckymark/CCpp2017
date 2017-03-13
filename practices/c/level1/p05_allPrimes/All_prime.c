#include<stdio.h>
#include<time.h>
#include<math.h>
#define MAX 1000000

int main(void)
{
    int i=1,number1,number2;
    for(number1 = 2 ; number1 <= MAX ; number1++){
            int k = sqrt(number1 + 1);
        for(number2 = 2 ; number2 <= k ; number2++){
            if(number1 % number2 != 0){
                i=1;
            }
            else{
                i=0;
                break;
            }
        }
        if(i == 1)
        printf("%d\t",number1);
    }
    printf("\n");
    printf("The time is %d.\n",clock());

    return 0;
}

