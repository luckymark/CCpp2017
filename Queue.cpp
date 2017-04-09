#include "Queue.h"

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
