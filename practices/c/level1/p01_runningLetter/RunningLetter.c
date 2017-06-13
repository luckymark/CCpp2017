# include<stdio.h>
# include<windows.h>

int main()
{
	int i,j;
	for(i=0;i<12;i++){
		for(j=0;j<i;j++){
			printf(" ");
		}
		Sleep(100);
		printf("R");
		system("cls");
	}
	
	for(i=12;i>0;i--){
		for(j=0;j<i;j++){
			printf(" ");
		}
		Sleep(100);
		printf("R");
		system("cls");
	}
	
	return 0;
 } 
