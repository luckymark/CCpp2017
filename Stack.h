#include<cstdio>
using namespace std;
class Stack
{
	private:
		int* s;
		int p,len;
		
	public:
		Stack(int __len){
			p=0;
			len=__len;
			s=new int[len];
		}
		int pop();
		bool push(int x);
		bool empty();
		bool full();
		void clear();
};
