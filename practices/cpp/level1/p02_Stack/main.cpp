#include<iostream>
#include<conio.h>
#include"Stack.h"
/*todolist
1.append;
2.pop;
3.isFull?;
4.isNull?; */ 
int main(){
	using std::cout;
	using std::cin;
	char ch;
	int n;
	cout<<"Please enter the size of you stack\n";
	cin>>n;
	Stack<int> stack(n);

	do{
		system("cls");
		cout<<"The stack:\n";
		if(!stack.isNull()){
			stack.disp();
		}
		else{
			std::cout<<"Null\n";
		}
		cout<<"What do you want to do?\n";
		cout<<"1.push  2.pop  q.quit\n";
		ch=getch();
		switch(ch){
			case '1':
				if(!stack.isFull()){
					cout<<"Please enter a number:\n";
					cin>>n;
					stack.push(n);	
				}
				else{
					cout<<"The stack is full\n";
					system("pause");
				}
				break;
			case '2':
				if(!stack.isNull()){
					stack.pop();
				}
				else{
					cout<<"The stack is null\n";
					system("pause");
				}
				break;
			case 'q':
				return 0;
			default:
				break;
		}
	}while(1);
	return 0;
}
