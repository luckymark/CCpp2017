#include<cstdio>
#include<cstring>
using namespace std;

#define SIZE 100

class Queue{
	public:
		int q[SIZE+1],head,tail,cnt;
		
		Queue(){
			head=tail=cnt=0;
		}
		
		int operator [] (int x){
			return q[x];
		}
		
		bool append(int x){
			if(cnt<SIZE){
				q[tail]=x;
				tail=(tail+1)%(SIZE+1);
				++cnt;
				return 1;
			}
			return 0;
		}
		
		int pop(){
			int Prehead=head;
			head=(head+1)%(SIZE+1);
			--cnt;
			return q[Prehead];
		}
		
		bool empty(){
			return cnt==0;
		}
		
		bool full(){
			return cnt==SIZE;
		}
		
		void clear(){
			while(cnt){
				pop();
			}
		}
};

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
		if(Q.empty()){
			puts("The Queue is Empty.");
			continue;
		}
		int j=Q.head;
		while(j!=Q.tail){
			printf("%d%c",Q[j],j==(Q.tail+SIZE)%(SIZE+1) ? '\n' : ' ');
			j=(j+1)%(SIZE+1);
		}
	}
	return 0;
}
