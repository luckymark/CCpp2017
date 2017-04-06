#include <cstdio>
using namespace std;

#define SIZE 100

class Queue{
	private:
		int q[SIZE+1],head=0,tail=0,cnt=0;
	
	public:
		bool append(int x);
		int pop();
		bool empty();
		bool full();
		void clear();
};
