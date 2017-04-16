#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define STOP  450

int main(void)
{
	int i , j ;
	char b[5][5];

	for( i = 0 ; i<5 ; i++ ){
        for( j=0 ; j<5 ; j++ ){	
			b[i][j] = ' ' ;		
		}
	}
		
	for(i = 0 ; i < 5 ; i++) {	
        for( j = 0 ; j < 5; j++) {	
			if(i != 0 && j== 0) { 
				printf("\n");
			}
			printf( "%c" , 'r' );
			Sleep( STOP );
			system("cls");		
		
			int k ,f;
		
			for( k = 0 ; k<= i ; k++ ){
				for( f=0 ; f<=j ; f++ ){
					if( k != 0 && f == 0){ printf("\n"); }
					printf("%c", b[k][f]);
				}
			}
		}
	}
	printf("\n over \n");
			
}


	
