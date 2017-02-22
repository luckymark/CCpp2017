#include<cstdio>
#include<cstring>
using namespace std;
class Queue
{
	#define SIZE 100
	public:
		int q[SIZE],head,tail,cnt;
		Queue()
		{
			head=tail=cnt=0;
		}
		int front()
		{
			return q[head];
		}
		bool append(int x)
		{
			if(cnt<SIZE)
			  {
			  	q[tail]=x;
			  	tail=(tail+1)%SIZE;
			  	++cnt;
			  	return 1;
			  }
			return 0;
		}
		bool pop()
		{
			if(cnt)
			  {
			  	head=(head+1)%SIZE;
			  	--cnt;
			  	return 1;
			  }
			return 0;
		}
		bool empty()
		{
			return cnt==0;
		}
		bool full()
		{
			return cnt==SIZE;
		}
};
int main()
{
	return 0;
}
