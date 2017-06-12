#include<iostream>
#include"Queue.h"
/*todolist:
  1显示队列中元素：show
  2向队列中添加元素：append
  3从队列中弹出一个元素：pop
  4查看队列是否已满：isFull
  5退出*/

Queue queue;
void main()
{
	using namespace std;
	while (1) {
		system("cls");
		cout << "Please input the option you want to do:" << endl;
		cout << "1.show\n2.append(int num)\n3.pop\n4.?isFull\n5.over" << endl;
		int k;
		scanf_s("%d", &k);
		switch (k) {
			 case 1:if (!queue.isEmpty()) {
						queue.show();
				   }
				   else {
						cout << "The queue is empty." << endl;
				   }
				   system("pause");
				   break;
			 case 2:if (!queue.isFull()) {
						cout << "Please input the number." << endl;
				        int n=0;
					    cin >> n;
					    queue.append(n);
			       }
				   else {
					    cout << "The queue has been full." << endl;
						system("pause");
				   }
				   break;
			 case 3:if (!queue.isEmpty()) {
						int n;
						n = queue.pop();
			       }
				   system("pause");
				   break;
			 case 4:if (queue.isFull()) {
						cout << "The queue has been full" << endl;
				   }
				   else {
					    cout << "The queue has not been full" << endl;
				   }
				   system("pause");
				   break;
			 case 5:goto END;
		 }
	}
	END:;
}