/*	system("color 0a");
	while(1){
		printf("0 1");
*/
#include<stdio.h>
#include<Windows.h>
int main()
{
	system("color 0a");
	
 	int i,j;

 	while(1){
 	for(i = 0 ; i < 49 ; i++){
		for(j = 0 ; j < i ; j++){
			printf(" ");
		}
		printf("R");
		system("cls");
	}
 	for(i = 49 ; i > -1 ; i--){
		for(j = i ; j > -1 ; j--){
			printf(" ");
		}
		printf("R");
		system("cls");
	}	
	}
	 
	return 0;
 } 
 
 

