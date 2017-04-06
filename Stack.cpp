#include<cstdio>
#include"Stack.h"
using namespace std;

int Stack::pop(){
	return s[--p];
}

bool Stack::push(int x){
	if(p<len){
		s[p++]=x;
		return 1;
	}
	else{
		return 0;
	}
}

bool Stack::empty(){
	return p==0;
}

bool Stack::full(){
	return p==len;
}

void Stack::clear(){
	while(p){
		pop();
	}
}

int main()
{
	Stack st(100);
	
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
	}
	return 0;
}
