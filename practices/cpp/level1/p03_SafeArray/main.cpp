#include<iostream>
#include<conio.h>
#include"Array.h"
using namespace std;

int main(){
	int n,i;
	char ch;
	
	cout<<"Please enter the size of your array:\n";
	cin>>n;
	Array<double> array(n);
	do{
		system("cls");
		cout<<"What do you want:\n";
		cout<<"1.change 2.display 3.quit\n";
		ch=getch();
		switch(ch){
			case '1':
				cout<<"Which do you want to change:\n";
				cin>>i;
				cout<<"Change to:\n";
				cin>>array[i];
				break;
			case '2':
				array.disp();
				system("pause");
				break;
			case '3':
				return 0;
			default:
				;
		}
	}while(1);

	return 0;
}
