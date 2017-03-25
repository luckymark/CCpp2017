#include <stdio.h>
#include <math.h>
#define SIZE 10000
#define SIZE1 10000

void encrypt(void);
void decrypt(void);
char array[SIZE];
char array1[SIZE1];
int i=0;

int main(void){

    printf("please input the txt that you want to encrypt:\n");
    encrypt();
    printf("\n");
    decrypt();
    printf("\n");

    return 0;
}

void encrypt(void){
    char txt;
    while((txt=getchar()) != EOF){
        if(100<=txt<=126){
            array1[i]=txt;
            txt=txt-23;
            putchar(txt);
            array[i]=txt;
            i++;
        }

        else if(32<=txt<=45){
            array1[i]=txt;
            txt=txt+11;
            putchar(txt);
            array[i]=txt;
            i++;
        }

        else if(45<txt<100){
            array1[i]=txt;
            txt=txt+sqrt(txt)+1;
            putchar(txt);
            array[i]=txt;
            i++;
        }
    }
}

void decrypt(void){
    int j=0;
    while(j<=i){
        if(100<=array1[j]<=126){
            array[j]=array[j]+23;
            putchar(array[j]);
            j++;
        }

        else if(32<=array1[j]<=45){
            array[j]=array[j]-11;
            putchar(array[j]);
            j++;
        }

        else if(45<array1[j]<100){
            array[j]=array[j]-sqrt(array[j])-1;
            putchar(array[j]);
            j++;
        }
    }
}
