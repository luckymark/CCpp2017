/*### 题目：Queue（队列）

### 功能要求：

实现一个队列类，可容纳100个int数据，并实现下面的操作：

1. append（入队）
2. pop（出队）
3. 判断队列是否满
4. 判断队列是否空
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
		}        //不要放在这 
	}
	while(!is_empty)
	{
		queue.pop();
	}
	
	
	return 0;
}
