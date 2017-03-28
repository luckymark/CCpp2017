#include<iostream>
#include<conio.h>
#include<windows.h>
#include"Queue.h"
/*todolist
1.append;
2.pop;
3.isFull?;
4.isNull?; */ 
int main(){
	using std::cout;
	using std::cin;
	char ch;
	double n;
	Queue queue;
	queue.initialize();
	do{
		system("cls");
		cout<<"The queue:\n";
		if(!queue.isNull()){
			queue.disp();
		}
		else{
			std::cout<<"Null\n";
		}
		cout<<"What do you want to do?\n";
		cout<<"1.append  2.pop  q.quit\n";
		ch=getch();
		switch(ch){
			case '1':
				if(!queue.isFull()){
					cout<<"Please enter a number:\n";
					cin>>n;
					if(n!=0){
						queue.append(n);
					}	
				}
				else{
					cout<<"The queue is full\n";
					system("pause");
				}
				break;
			case '2':
				if(!queue.isNull()){
					queue.pop();
				}
				else{
					cout<<"The queue is null\n";
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
