/*
	
	WILL INPUT THE WAY TO MOVE DISK FORM A DISK TO DISK
	EXAMPLE : A->B 
		  B->C
	IT MEANS THAT A DISK IN A MOVES FORM A TO B,THEN MOVE A DISK FORM B TO
	C .


*/
#include<stdio.h>
void f(int n,char A, char B,char C);

int main()

{
	
	int n;
	
	char A , B , C;               // A B C IS THREE POLES ;
	
	scanf("%d",&n);		//INPUT HOW MANY DISKS DO YOU WANT?
	
	fflush(stdin);		
	
	scanf("%c",&A);		//INPUT WHICH POLE WHITH ALL DISKS AT BEGGING
	
	fflush(stdin);
	
	scanf("%c",&C);		//INPUT WHICH POLE WHITH ALL DISKS AT LAST
	
	fflush(stdin);
	
	scanf("%c",&B);		

	f( n , A , C , B ) ;
	
	printf("\n");
	
	return 0;
}


void f( int n , char A , char B , char C )
{
	if ( n == 1 ){ printf ( "%c>>%c", A ,B );}
	
	else{
		f( n - 1 , A , C ,B );
		
		printf("\n");
		
		printf("%c>>%c\n",A,B);
		
		f( n-1 , C , B , A );

	}
}
