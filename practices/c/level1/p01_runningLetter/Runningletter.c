#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define TIME 10
#define RUOTE 118

void runningletter(int i);

int main(void)
{
    int i=RUOTE;

    while(1){
          runningletter(i);
    }
    return 0;
}

void runningletter(int i){
        int j,k;
        for(j=0;j<i;j++){
            for(k=0;k<=j;k++){
                printf(" ");
                }
                    printf("s");
                    Sleep(TIME);
                    system("cls");
        }

        for(j=i;j>=0;j--){
            for(k=0;k<=j;k++){
                printf(" ");
            }
                    printf("s");
                    Sleep(TIME);
                    system("cls");
        }
}
