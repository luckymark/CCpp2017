// First, change the letters into ascii , the value of ascii is added by a 
// ramdom number.
// The result is stored in an int arry. at last,each element of arry is swaped

#include<stdio.h>

char a[7] ;    //plain text
int b[6] ;		// encrypted text

void encrypt( char a[] , int b[] );
void decipher( int b[] );

int main()
{
	scanf( "%s" , a);
	encrypt( a , b );
	decipher( b );
	return 0;
}

void encrypt( char a1[7] ,int b1[6])
{
	
	b1[0] = a1[0] + 56;
	b1[1] = a1[1] + 12;
	b1[2] = a1[2] + 11;
	b1[3] = a1[3] + 1111;
	b1[4] = a1[4] + 1234;
	b1[5] = a1[5] + 321;
	
	int swap;
	
	swap = b1[0];
	b1[0] = b1[5];
	b1[5] = swap;

	swap = b1[4];
	b1[4] = b1[1];
	b1[1] = swap;

	swap = b1[2];
	b1[2] = b1[3];
	b1[3] = swap;

	printf( "encrypt:" );
	for(int i = 0 ; i < 6; i++ ){
		
		printf("%d" , b1[i] );
	}
	printf("\n");
	
}

void decipher( int b1[6] )
{
	char a1[7];

	int swap;
	
	swap = b1[0];
	b1[0] = b1[5];
	b1[5] = swap;

	swap = b1[4];
	b1[4] = b1[1];
	b1[1] = swap;

	swap = b1[2];
	b1[2] = b1[3];
	b1[3] = swap;

	a1[0] = b1[0] - 56;
	a1[1] = b1[1]-12;
	a1[2] = b1[2]-11;
	a1[3] = b1[3]-1111;
	a1[4] = b1[4]-1234;
	a1[5] = b1[5]-321;
	a1[6] = '\0';


	printf("decipher:\n");	
	printf("%s" , a1 );
	
	printf("\n");
	
}
