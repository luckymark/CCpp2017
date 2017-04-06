#include <cstdio>
#include "Queue.h"
using namespace std;

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

bool Queue::empty(){
	return cnt==0;
}

bool Queue::full(){
	return cnt==SIZE;
}

void Queue::clear(){
	while(cnt){
		pop();
	}
}

int main(){
	Queue Q;
	
	int op;/*
	op==0 pop;
	op==1 append;
	op==2 empty;
	op==3 full;
	op==4 clear;
	*/
	
	int n;/*
	sum of operations
	*/
	
	int x;
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&op);
		if(op==0){
			if(Q.empty()){
				puts("The Queue is Empty.");
			}
			else{
				printf("%d\n",Q.pop());
			}
		}
		else if(op==1){
			scanf("%d",&x);
			bool flag=Q.append(x);
			if(!flag){
				puts("The Queue is Full.");
			}
		}
		else if(op==2){
			if(Q.empty()){
				puts("The Queue is Empty.");
			}
			else{
				puts("The Queue is not Empty.");
			}
		}
		else if(op==3){
			if(Q.full()){
				puts("The Queue is Full.");
			}
			else{
				puts("The Queue is not Full.");
			}
		}
		else{
			Q.clear();
		}
	}
	return 0;
}
