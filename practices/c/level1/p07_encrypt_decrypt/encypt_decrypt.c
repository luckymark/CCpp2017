// First, change the letters into ascii , the value of ascii is added by a 
// ramdom number.
// The result is stored in an int arry. at last,each element of arry is swaped

#include<stdio.h>

char a[1000] ;    //plain text


void encypt ( char * );

void decrypt( char * );

int main ( )
{
    scanf("%s",a);
    
    encypt( a );
    
    printf("%s\n",a);
    
    decrypt( a ) ;
    
    printf("%s\n",a);
    
    return 0;
}

void encypt ( char a[] )
{
    char *a1=a;

    while(*a1 != '\0'){
        a1++;
    }

    a1--;

    if((a1-a) % 2 == 0){
        while(a1 != a){
            char swap;
            swap = *a+10;
            *a = *a1+10;
            *a1 = swap;
            a++;
            a1--;
        }
    } else {
        while(a1  != a + 1) {
            char swap;
            swap = *a+10;
            *a = *a1+11;
            *a1 = swap;
            a++;
            a1--;
        }

        char swap;
        swap = *a+10;
        *a = *a1+10;
        *a1 = swap;
    }
    
}

void decrypt( char a[]  )
{
    char *a1=a;

    while( *a1 != '\0' ){
        a1++;
    }

    a1--;

    if( (a1-a) % 2 == 0 ){
        while( a1 != a ){
            char swap;
            swap = *a-10;
            *a = *a1-10;
            *a1 = swap;
            a++;
            a1--;
        }
    } else {
        while(a1  != a + 1) {
            char swap;
            swap = *a-11;
            *a = *a1-10;
            *a1 = swap;
            a++;
            a1--;
        }

        char swap;
        swap = *a-10;
        *a = *a1-10;
        *a1 = swap;
    }

}





