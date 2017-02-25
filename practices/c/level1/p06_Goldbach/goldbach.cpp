#include<stdio.h>

int main(  )
{
	int p[100];	//put the number(prime numbers)  in to arry 
	int number;
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 5;
	p[4] = 7;
	
	int i=4;
	for(number=11;number<=100;number++){
		int number1=number/2;
		int k;
		int flag=0;
		for(k=2;k<=number1;k++){
			if(number%k==0){
				flag=0;
				break;
			}
			flag=1;
		}
		if(flag==1){
			p[i]=number;
			i++;	
		}
	}
	

	int c_arry,flag2;  // start to prove 

	for( i = 1 ; i <= 100 ; i++ ){
		for( c_arry = 0 ; c_arry < 100 ; c_arry++ ){
			flag2 = 0;
			if( i == p[c_arry] ){
				printf("%d be proved\n",i);
				flag2 = 1;
				break;
			}
			if( p[c_arry] > i){
				break;
			}
		}
		if( flag2 ){continue;}
		int p_arry = 0 , q_arry = c_arry - 1;
		while( 1 ){
			if( p_arry == q_arry ){
				if( p[p_arry] + p[q_arry] == i ){
					printf("%d be proved\n",i);
					break;
				}

				p_arry = 0;
				q_arry-- ;
			}
			if( p[p_arry] + p[q_arry] == i ){
				printf("%d be proved\n",i);
				break;
			}
			else{
				p_arry++;

			}
			
		}
	}
	return 0;
}
