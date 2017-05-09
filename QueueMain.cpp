#include <cstdio>
#include "Queue.h"
using namespace std;

int main(){
	Queue<int,100> q;
	
	int op;/*
	op==0 pop;
	op==1 append;
	op==2 isEmpty;
	op==3 isFull;
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
			if(q.isEmpty()){
				puts("The Queue is Empty.");
			}
			else{
				printf("%d\n",q.pop());
			}
		}
		else if(op==1){
			scanf("%d",&x);
			bool flag=q.append(x);
			if(!flag){
				puts("The Queue is Full.");
			}
		}
		else if(op==2){
			if(q.isEmpty()){
				puts("The Queue is Empty.");
			}
			else{
				puts("The Queue is not Empty.");
			}
		}
		else if(op==3){
			if(q.isFull()){
				puts("The Queue is Full.");
			}
			else{
				puts("The Queue is not Full.");
			}
		}
		else{
			q.clear();
		}
	}
	
	Queue_Iterator<int> a=q.begin();
	Queue_Iterator<int> b=q.end();
	a==b;
	a!=b;
	for(Queue_Iterator<int> it=q.begin();it!=q.end();++it){
		printf("%d ",*it);
	}
	puts("");
	return 0;
}
