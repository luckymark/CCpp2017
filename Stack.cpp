#include<cstdio>
using namespace std;

#define SIZE 100

class Stack
{
	public:
		int s[SIZE],p;
		
		Stack(){
			p=0;
		}
		
		int operator [] (int x){
			return s[x];
		}
		
		int pop(){
			return s[--p];
		}
		
		bool push(int x){
			if(p<SIZE){
				s[p++]=x;
				return 1;
			}
			else{
				return 0;
			}
		}
		
		bool empty(){
			return p==0;
		}
		
		bool full(){
			return p==SIZE;
		}
		
		void clear(){
			while(p){
				pop();
			}
		}
};
int main()
{
	Stack st;
	
	int op;/*
	op==0 pop;
	op==1 push;
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
			if(st.empty()){
				puts("The Stack is Empty.");
			}
			else{
				printf("%d\n",st.pop());
			}
		}
		else if(op==1){
			scanf("%d",&x);
			bool flag=st.push(x);
			if(!flag){
				puts("The Stack is Full.");
			}
		}
		else if(op==2){
			if(st.empty()){
				puts("The Stack is Empty.");
			}
			else{
				puts("The Stack is not Empty.");
			}
		}
		else if(op==3){
			if(st.full()){
				puts("The Stack is Full.");
			}
			else{
				puts("The Stack is not Full.");
			}
		}
		else{
			st.clear();
		}
		for(int i=0;i<st.p-1;++i){
			printf("%d ",st[i]);
		}
		if(!st.empty()){
			printf("%d\n",st[st.p-1]);
		}
		else{
			puts("The Stack is Empty.");
		}
	}
	return 0;
}
