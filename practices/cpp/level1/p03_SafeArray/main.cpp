#include<iostream>
#include"SafeArray.h"
#include<windows.h>

SafeArray t;
using namespace std;

int main(void)
{
	while (1) {
		system("cls");
		cout << "请选择您想做的事情: 1.修改或添加数组元素  2.查看数组元素   3.结束" << endl;
		int n;
		cin >> n;
		switch (n) {
			case 1:
				int No;
				cout << "请输入您想操作的元素的下标：";
				cin >> No;
				if (t.judge(No)) {
					cout << "数组元素：";
					int num;
					cin >> num;
					t.insert(num, No);
				}
				else {
					cout << "下标越界，操作无效";
					system("pause");
				}
				break;
			case 2:
				cout << "请依次输入您想操作的元素的下标：";
				cin >> No;
				if (t.judge(No)) {
					t.look(No);
					system("pause");
				}
				else {
					cout << "下标越界，操作无效";
				}
				break;
			case 3:
				goto end;
		}
	}
	end:;
}
