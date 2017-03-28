#include <iostream>
#include "Queue.h"
using namespace std;
Queue my_queue;
int main(){
		freopen("main.in","r",stdin);
		cout << my_queue.is_empty() << endl;
		for(int i = 1; i <= 10; i++)
				if(!my_queue.is_full())
						my_queue.append(i);
		for(int i = 1; i <= 10; i++)
				if(!my_queue.is_empty())
						my_queue.pop();
		return 0;
}
