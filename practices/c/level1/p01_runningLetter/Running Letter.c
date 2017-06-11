#include <iostream>
#include <windows.h>
int main(int argc, char** argv)
 {
 	while(1)
 	{
	 
		printf("R");
	 	Sleep(30);
		system("cls");
		for(int i=0;i<79;i++)
		{
			for(int j=0;j<i;j++)
				printf(" ");	
			printf("R");
			Sleep(30);
			system("cls");
		}
		for(int i=79;i>=0;i--)
		{
			for(int j=0;j<i;j++)
				printf(" ");
			printf("R");
			Sleep(30);
			system("cls");
		}
	}
	return 0;
}
