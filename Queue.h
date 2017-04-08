#include <cstdio>
using namespace std;

#define SIZE 100

class Queue{
	private:
		int q[SIZE+1],head=0,tail=0,cnt=0;
	
	public:
		bool append(int x);
		int pop();
		bool isEmpty();
		bool isFull();
		void clear();
};

bool Queue::append(int x){
	if(cnt<SIZE){
		q[tail]=x;
		tail=(tail+1)%(SIZE+1);
		++cnt;
		return 1;
	}
	return 0;
}

int Queue::pop(){
	int Prehead=head;
	head=(head+1)%(SIZE+1);
	--cnt;
	return q[Prehead];
}

bool Queue::isEmpty(){
	return cnt==0;
}

bool Queue::isFull(){
	return cnt==SIZE;
}

void Queue::clear(){
	while(cnt){
		pop();
	}
}
