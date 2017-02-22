#include<cstdio>
using namespace std;
class Stack
{
	#define SIZE 100
	public:
		int s[SIZE],p,cnt;
		Stack()
		{
			p=cnt=0;
		}
		bool push(int x)
		{
			if(cnt<SIZE)
			  {
			  	s[p++]=x;
			  	++cnt;
			  	return 1;
			  }
			else
			  return 0;
		}
		bool pop()
		{
			if(cnt)
			  {
			  	--p;
			  	--cnt;
			  	return 1;
			  }
			else
			  return 0;
		}
		bool full()
		{
			return cnt==SIZE;
		}
		bool empty()
		{
			return cnt==0;
		}
};
int main()
{
	return 0;
}
