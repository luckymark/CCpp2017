/*### ��Ŀ��Queue�����У�

### ����Ҫ��

ʵ��һ�������࣬������100��int���ݣ���ʵ������Ĳ�����

1. append����ӣ�
2. pop�����ӣ�
3. �ж϶����Ƿ���
4. �ж϶����Ƿ��
  */
#include "iostream"
using namespace std;
int main()
{
	Queue queue;
	while(!is_full())
	{
		cin>>a;
		queue.append(a);
		cout<<"if you have finished,please enter e";
		if('e'==getch())
		{
			break;
		}        //��Ҫ������ 
	}
	while(!is_empty)
	{
		queue.pop();
	}
	
	
	return 0;
}
