#include<stdio.h>

int main()
{
    int num_judge=100;

    for( ; num_judge <= 999 ; num_judge++ ){
        int k = num_judge;

        int sum = 0;

        while(k != 0){
            int c = k%10;
            sum = sum+c*c*c;
            k = k/10;
        }

        if( sum == num_judge ) printf ( "%d\n" , num_judge );
    }

    return 0;

}
    
