/*todolist
1.显示队列
2.入队
3.出队
4.判断队列是否已满 
*/
#include "Queue.h"
#include <iostream>
#include <windows.h>
using std::cin;
using std::cout;
using std::endl;
int main() {
	Queue queue;

	cout << "Please enter the number to choose what you want to do(enter 'q' to exit)" << endl;
	cout << "1.show the queue\n2.append\n3.pop\n4.isFull?" << endl;
	
	while (1) {
		int option;
		if (scanf("%d", &option)) {
			switch (option) {
			case 1:
				if (!queue.isEmpty()) {
					queue.disp();
				}
				else {
					cout << "The queue is empty!" << endl;
					Sleep(1000);
				}
				break;
			case 2:
				if (!queue.isFull()) {
					int num;
					cout << "Enter the number to append:" << endl;
					cin >> num;
					queue.append(num);
				}
				break;
			case 3:
				if (!queue.isEmpty()) {
					queue.pop();
				}
				else {
					cout << "The queue is empty!" << endl;
				}
				break;
			case 4:
				if (queue.isFull()) {
					cout << "The queue is full!" << endl;
				}
				else {
					cout << "The queue isn't full!" << endl;
				}
				break;
			default:
				cout << "Please enter the  correct number 1~4 or 'q' to exit." << endl;
				break;
			}
		}
		else
			return 0;
		cout << "Please enter the option continue(enter 'q' to exit):" << endl;
	}
}
