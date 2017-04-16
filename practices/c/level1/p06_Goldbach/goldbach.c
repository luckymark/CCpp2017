#include<stdio.h>
#include<math.h>

int main( void )
{
    int p[100];    //put the number(prime numbers)  in to arry 
    int number;
    int a_arry =0;

    for(number = 2 ; number <= 100 ; number++) {
        int help = sqrt ( number );
        int identify = 1;

        for (int j = 2 ; j <= help ; j++) {
            if ( number % j == 0 ) { 
                identify = 0;
                break;
            }
        }

        if (identify == 1) {
            p[a_arry] = number ;
            a_arry++ ;
        }
    }

        a_arry--;

        int Prove_Number=4;

        while(Prove_Number != 102) {
            int *q = &p[0] ;
            int *p1 = &p[a_arry];

            while( 1 ) {
                int flag=0;

                if(p1 == &p[0] - 1) {
                    break ;
                }

                while( q != p1 + 1 ) {
                    if ( *q + *p1 == Prove_Number ){
                        printf("%d is be proved \n " , Prove_Number );
                        flag=1;
                        break;
                    }
                    q++;
                }

                if( flag==1 ){break;}

                q = &p[0];

                p1--;
            }

            Prove_Number = Prove_Number + 2;

        }

        return 0;
}





            
            

        





