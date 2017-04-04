#include<stdio.h>
#include"Stack.h"

/*To do list
 1、显示栈中数据
 2、向栈中添加元素
 3、从栈中弹出一个元素
 4、判断栈是否已满
 5、退出程序
 */

Stack stack;
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
			case 1:if (!stack.isEmpty()) {
						stack.show();
				   }
				   else {
						cout << "The stack is empty." << endl;
				   }
				   system("pause");
				   break;
			case 2:if (!stack.isFull()) {
						cout << "Please input the number." << endl;
						int n = 0;
						cin >> n;
						stack.append(n);
					}
					else {
						cout << "The stack has been full." << endl;
						system("pause");
					}
					break;
			case 3:if (!stack.isEmpty()) {
						int n;
						n = stack.pop();
					}
					system("pause");
					break;
			case 4:if (stack.isFull()) {
						cout << "The stack has been full" << endl;
					}
					else {
						cout << "The stack has not been full" << endl;
					}
					system("pause");
					break;
			case 5:goto END;
		}
	}
	END:;
}